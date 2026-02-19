#ifndef LEXER_H
#define LEXER_H

#include "Token.h"

class Lexer
{
private:
	std::string source;
	int pos;

public:
	Lexer() { };
	Lexer( std::string code ) : source(code), pos(0) { };
	
	Token GetToken();
};

#endif
