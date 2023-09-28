/*
 * Ast.h
 *
 *  Created on: 18-Sep-2023
 *      Author: user
 */

#ifndef AST_AST_H_
#define AST_AST_H_

#include <memory>
#include <vector>


class Ast {
public:
	virtual void print() {};
	virtual void* codegen() { return nullptr; };
	virtual ~Ast() {};
};

class ProgramAst: public Ast {
private:
	std::unique_ptr<Ast> statements;
public:
	ProgramAst(std::unique_ptr<Ast> ast) : statements(ast) {};
	virtual ~ProgramAst();
};

class StatementsAst: public Ast {
private:
	std::vector<std::unique_ptr<Ast>> statement;
public:
	StatementsAst(std::vector<std::unique_ptr<Ast>> ast) : statement(ast) {};
	virtual ~StatementsAst();
};

class BlockStatementAst: public Ast {
private:
	std::unique_ptr<Ast> statements;
public:
	BlockStatementAst(std::unique_ptr<Ast> ast) : statements(ast) {};
	virtual ~BlockStatementAst();
};

#endif /* AST_AST_H_ */
