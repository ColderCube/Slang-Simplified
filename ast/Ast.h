/*
 * Ast.h
 *
 *  Created on: 18-Sep-2023
 *      Author: user
 */

#ifndef AST_AST_H_
#define AST_AST_H_


class Ast {
public:
	virtual void print() {};
	virtual void* codegen() { return nullptr; };
	virtual ~Ast() {};
};

#endif /* AST_AST_H_ */
