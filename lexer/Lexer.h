/*
 * Lexer.h
 *
 *  Created on: 27-Aug-2023
 *      Author: user
 */

#ifndef LEXER_LEXER_H_
#define LEXER_LEXER_H_

#include <fstream>
#include <map>
#include <string>

#include "../token/tag.h"
#include "../token/Token.h"

class Lexer {
private:
	int line_number = 0;
	int char_number = 0;
	int total_char = 0;

	char peek = ' ';

	std::istream *file;

	std::map<std::string, Token*> reserved;
public:
	Lexer(std::fstream &f);
	void create_reserved();
	void readch();
	bool match(char c);
	char getpeek();
	Token* scan();
	virtual ~Lexer();
};

#endif /* LEXER_LEXER_H_ */
