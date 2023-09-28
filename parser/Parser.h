/*
 * Parser.h
 *
 *  Created on: 14-Sep-2023
 *      Author: user
 */

#ifndef PARSER_PARSER_H_
#define PARSER_PARSER_H_

#include "../lexer/Lexer.h"

class Parser {
private:
	Lexer* lexer;
	Token* CurToken = nullptr;
public:
	Parser(Lexer* l) : lexer(l) {};
	virtual ~Parser();

	Token* getCurToken() const {
		return CurToken;
	}
};

#endif /* PARSER_PARSER_H_ */
