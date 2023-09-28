/*
 * Lexer.cpp
 *
 *  Created on: 27-Aug-2023
 *      Author: user
 */

#include "Lexer.h"

#include <cctype>
#include <iostream>
#include <utility>

Lexer::Lexer(std::fstream &f) {
	this->file = &f;
	this->create_reserved();
}

void Lexer::create_reserved() {
	reserved["if"] = new Token(IF, "if");
	reserved["else"] = new Token(ELSE, "else");
	reserved["while"] = new Token(WHILE, "while");
	reserved["do"] = new Token(DO, "do");
	reserved["break"] = new Token(BREAK, "break");
}

void Lexer::readch() {
	file->get(peek);
	total_char++;
	char_number++;
	if (peek == '\n') {
		line_number++;
		char_number = 0;
	}
}

bool Lexer::match(char c) {
	readch();
	if (peek == c)
		return true;
	return false;
}

char Lexer::getpeek() {
	return peek;
}

Token* Lexer::scan() {
	if (file->eof()) {
		std::fstream *fs = dynamic_cast<std::fstream*>(file);
		if (fs != 0) {
			fs->close();
		}
		return new Token(EOF_);
	}
	for (; !file->eof() || peek == '\0'; readch()) {
		if (peek == ' ' || peek == '\t' || peek == '\n')
			continue;
		break;
	}
	if (peek == '\0' || peek < 0 || file->eof()) {
		std::fstream *fs = dynamic_cast<std::fstream*>(file);
		if (fs != 0) {
			fs->close();
		}
		return new Token(EOF_);
	}
	switch (peek) {
	case '&': {
		if (match('&')) {
			readch();
			return new Token(AND, "&&");
		} else {
			return new Token(BIT_AND, "&");
		}
	}
	case '|': {
		if (match('|')) {
			readch();
			return new Token(OR, "||");;
		} else {
			return new Token(BIT_OR, "|");
		}
	} // @suppress("No break at end of case")
	case '=': {
		if (match('=')) {
			readch();
			return new Token(EQ, "==");;
		} else {
			return new Token(ASSIGN, "=");
		}
	} // @suppress("No break at end of case")
	case '!': {
		if (match('=')) {
			readch();
			return new Token(NE, "!=");
		} else {
			return new Token(NOT, "!");
		}
	}
	case '<': {
		if (match('=')) {
			readch();
			return new Token(LE, "<=");
		} else {
			return new Token(LT, "<");
		}
	}
	case '>': {
		if (match('=')) {
			readch();
			return new Token(GE, ">=");
		} else {
			return new Token(GT, ">");
		}
	}
	case '+': {
		;
		readch();
		return new Token(PLUS, "+");
	}
	case '-': {
		readch();
		return new Token(MINUS, "-");
	}
	case '*': {
		readch();
		return new Token(MULTIPLY, "*");
	}
	case '/': {
		if (match('/')) {
			while (peek != '\n')
				readch();
			return scan();
		}
		return new Token(DIVIDE, "/");
	}
	case '(': {
		readch();
		return new Token(LPARAN, "(");
	}
	case ')': {
		readch();
		return new Token(RPARAN, ")");
	}
	case '[': {
		readch();
		return new Token(RSBRAC, "[");
	}
	case ']': {
		readch();
		return new Token(LSBRAC, "]");
	}
	case '{': {
		readch();
		return new Token(RCBRAC, "{");
	}
	case '}': {
		readch();
		return new Token(LCBRAC, "}");
	}
	case '\'': {
		char charac;
		readch();
		charac = peek;
		if (!match('\'')) {
			std::cerr << "The closing \"\'\" is missing at line" << line_number
					<< "character " << char_number << std::endl;
			return scan();
		}
		readch();
		return new Token(CHARA, charac);
	}
	case '\"': {
		readch();
		std::string str;
		while (peek != '\"' && peek != '\n') {
			str += peek;
			readch();
		}
		if (match('\"') != 0) {
			std::cerr << "The closing \"\"\" is missing at line" << line_number
					<< "character " << char_number << std::endl;
			return scan();
		}
		readch();
		return new Token(STRING, str);
	}
	}
	if (std::isdigit(peek)) {
		int v = 0;
		do {
			v = v * 10 + (peek - '0');
			readch();
		} while (std::isdigit(peek));
		if (peek != '.') {
			return new Token(NUM, v);
		}
		float x = v;
		float d = 10;
		for (;;) {
			readch();
			if (!(std::isdigit(peek)))
				break;
			x = x + (peek - '0') / d;
			d = d * 10;
		}
		return new Token(REAL, x);
	}
	if (std::isalpha(peek) || peek == '_') {
		std::string str;
		do {
			str += peek;
			readch();
		} while (std::isalnum(peek) || peek == '_');
		for (auto i : reserved) {
			if (i.first == str) {
				return i.second;
			}
		}
		if (str == "int" || str == "float" || str == "char" || str == "bool") {

			return new Token(DATATYPE, str);
		}
		if (str == "true") {
			return new Token(TRUE, str);
		}
		if (str == "false") {
			return new Token(FALSE, str);
		}
		return new Token(ID, str);
	}
	if (peek == ';') {
		readch();
		return new Token(SEMI, ";");
	}
	if (peek == ',') {
		readch();
		return new Token(COMA, ",");
	}
	std::cerr << "Found Unknown at " << line_number << ":" << char_number
			<< std::endl;
	return new Token(UNIDENTIFIED);
}

Lexer::~Lexer() {
}

