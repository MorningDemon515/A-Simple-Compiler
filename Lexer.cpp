#include "Lexer.h"
#include <ctype.h>

Token Lexer::GetToken()
{
	char cchar = source[pos];
	
	if(isspace(cchar))
	{
		pos++;
		cchar = source[pos];
	}
		
	if((size_t)pos >= source.size())
	{
		return Token(TokenType::END_OF_FILE, "EndFile");
	}
	
	if(isdigit(cchar))
	{
		std::string t = "";
		while(isdigit(cchar))
		{
			t += std::string(1, cchar);
			pos++;
			cchar = source[pos];
		}
		
		
		return Token(TokenType::NUMBER, t);
	}
	
	if('+')
	{
		pos++;
		return Token(TokenType::ADD, "+");
	}

	return Token(TokenType::UNKNOWN, "Unknown");
		
}
