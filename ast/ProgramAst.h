/*
 * ProgramAst.h
 *
 *  Created on: 18-Sep-2023
 *      Author: user
 */

#ifndef AST_PROGRAMAST_H_
#define AST_PROGRAMAST_H_

#include <memory>
#include <vector>

#include "Ast.h"

class ProgramAst: public Ast {
private:
	std::vector<std::unique_ptr<Ast>> statements;
public:
	ProgramAst(std::vector<std::unique_ptr<Ast>> ast) : statements(ast) {};
	virtual ~ProgramAst();
};

#endif /* AST_PROGRAMAST_H_ */
