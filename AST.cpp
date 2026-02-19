#include "AST.h"
#include <stdexcept>

Parser::Parser(Lexer l)
{
	pos = 0;
	Token t = Token(TokenType::UNKNOWN, "");
	
	while(t.type != TokenType::END_OF_FILE)
	{
		t = l.GetToken();
		tks.push_back(t);
	}
}

Token Parser::CurrentToken()
{
	return tks[pos];
}

void Parser::eat()
{
	pos++;
}

std::unique_ptr<ASTNode> Parser::ParseExpression()
{
	auto node = ParseNumber();
	
	while(CurrentToken().type == TokenType::ADD)
	{
		std::string op = CurrentToken().value;
		eat();
		
		auto right = ParseNumber();
		node = std::make_unique<BinOpNode>(op, std::move(node), std::move(right));
	}
	
	return node;
}

std::unique_ptr<ASTNode> Parser::ParseNumber()
{
	if(CurrentToken().type == TokenType::NUMBER)
	{
		int val = std::stoi(CurrentToken().value);
		auto node = std::make_unique<NumberNode>(val);
		eat();
		return node;
	}
	else
	{
		return std::make_unique<UnknownNode>("Unknown!");
	}
}

std::unique_ptr<ASTNode> Parser::Work()
{
	return ParseExpression();
}
