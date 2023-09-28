/*
 * Token.h
 *
 *  Created on: 13-Sep-2023
 *      Author: user
 */

#ifndef TOKEN_TOKEN_H_
#define TOKEN_TOKEN_H_

#include <string>

#include "tag.h"

class Token {
public:
	Tag tag;
	std::string str = "";
	int ival = 0;
	float fval = 0;
	char c = '\0';
	Token(Tag t) : tag(t) {};
	Token(Tag t, std::string s) : tag(t), str(s) {};
	Token(Tag t, int val) : tag(t), ival(val) {};
	Token(Tag t, float val) : tag(t), fval(val) {};
	Token(Tag t, double val) : tag(t), fval(val) {};
	Token(Tag t, char c) : tag(t), c(c) {};
	virtual ~Token() { delete this; };

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
};

#endif /* TOKEN_TOKEN_H_ */
