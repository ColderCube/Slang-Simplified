/*
 * Token.h
 *
 *  Created on: 13-Sep-2023
 *      Author: user
 */

#ifndef TOKEN_TOKEN_H_
#define TOKEN_TOKEN_H_

#include <iostream>
#include <limits>
#include <string>

#include "tag.h"

class Token {
public:
	Token(Tag t) :
			tag(t) {
	}
	;
	Token(Tag t, std::string s) :
			tag(t), str(s) {
	}
	;
	Token(Tag t, int val) :
			tag(t), ival(val) {
	}
	;
	Token(Tag t, float val) :
			tag(t), fval(val) {
	}
	;
	Token(Tag t, double val) :
			tag(t), fval(val) {
	}
	;
	Token(Tag t, char c) :
			tag(t), c(c) {
	}
	;
	virtual ~Token() {
		delete this;
	}
	;

	char getChar() const {
		return c;
	}

	float getFloat() const {
		return fval;
	}

	int getInt() const {
		return ival;
	}

	const std::string& getStr() const {
		return str;
	}

	Tag getTag() const {
		return tag;
	}

	void Print() {
		if (str != "") {
			std::cout << str;
		} else if (c != '\0') {
			std::cout << c;
		} else if (ival != std::numeric_limits<int>::infinity()) {
			std::cout << ival;
		} else if (fval != std::numeric_limits<float>::infinity()) {
			std::cout << fval;
		}
	}
private:
	Tag tag;
	std::string str = "";
	int ival = std::numeric_limits<int>::infinity();
	float fval = std::numeric_limits<float>::infinity();
	char c = '\0';
};

#endif /* TOKEN_TOKEN_H_ */
