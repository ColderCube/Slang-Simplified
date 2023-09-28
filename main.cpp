/*
 * main.cpp
 *
 *  Created on: 27-Aug-2023
 *      Author: user
 */

#include <iostream>

#include "lexer/Lexer.h"


int main() {
	std::fstream f("source.slang");
	Lexer l(f);
	Token * t = l.scan();
	while (t->tag!=EOF_ && t->tag!=UNIDENTIFIED) {
		t = l.scan();
	}
	std::cout << "End" << std::endl;
	return 0;
}



