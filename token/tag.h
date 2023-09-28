/*
 * tag.h
 *
 *  Created on: 27-Aug-2023
 *      Author: user
 */

#ifndef TOKEN_TAG_H_
#define TOKEN_TAG_H_


typedef enum {
	EOF_,
	SEMI,
	COLON,
	AND,
	BASIC,
	BREAK,
	BIT_AND,
	BIT_OR,
	BIT_NOT,
	COMA,
	CHARA,
	STRING,
	RPARAN,
	LPARAN,
	RSBRAC,
	LSBRAC,
	RCBRAC,
	LCBRAC,
	DATATYPE,
	DO,
	ELSE,
	EQ,
	FALSE,
	GE,
	GT,
	ID,
	IF,
	INDEX,
	LE,
	LT,
	ASSIGN,
	MINUS,
	NE,
	NOT,
	PLUS,
	MULTIPLY,
	DIVIDE,
	NUM,
	OR,
	REAL,
	TEMP,
	TRUE,
	WHILE,
	FN,
	UNIDENTIFIED=99999999
} Tag;


#endif /* TOKEN_TAG_H_ */
