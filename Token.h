#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>

enum class TokenType
{
	END_OF_FILE=0, 
	UNKNOWN,
	NUMBER,
	ADD
};

struct Token
{
	TokenType type;
	std::string value;
	
	Token(TokenType t, const std::string& v = "") : type(t), value(v) { }
};

#endif
