#ifndef AST_H
#define AST_H

#include "Lexer.h"
#include <memory>
#include <iostream>
#include <vector>

//基节点
struct ASTNode {
	virtual ~ASTNode() = default;
};

//子节点
struct UnknownNode : ASTNode
{
	std::string uk;
	
	UnknownNode(std::string uu) : uk(uu) { }
};

struct BinOpNode : ASTNode
{
	std::string op;//运算符
	std::unique_ptr<ASTNode> left;
	std::unique_ptr<ASTNode> right;
	
	BinOpNode(
		const std::string& operation, 
		std::unique_ptr<ASTNode> lhs,
		std::unique_ptr<ASTNode> rhs) : op(operation), left(std::move(lhs)), right(std::move(rhs)){ };
};

struct NumberNode : ASTNode {
	int value;
	NumberNode(int val) : value(val) {}
};

class Parser
{
private:
	std::vector<Token> tks;
	size_t pos;
	
	Token CurrentToken();
	void eat();
	
	std::unique_ptr<ASTNode> ParseNumber();
	std::unique_ptr<ASTNode> ParseExpression();
public:
	Parser() { };
	Parser(Lexer l);
	
	std::unique_ptr<ASTNode> Work();
};

#endif
