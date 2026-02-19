#include "Interpret.h"

void PrintAST(const std::unique_ptr<ASTNode>& node, int depth = 0) {
	std::string indent(depth * 2, ' ');
	
	if (auto* num = dynamic_cast<NumberNode*>(node.get())) {
		std::cout << indent << "Number: " << num->value << std::endl;
	}
	else if (auto* bin = dynamic_cast<BinOpNode*>(node.get())) {
		std::cout << indent << "Binary Operator: " << bin->op << std::endl;
		std::cout << indent << "LHS:" << std::endl;
		PrintAST(bin->left, depth + 1);
		std::cout << indent << "RHS:" << std::endl;
		PrintAST(bin->right, depth + 1);
	}
	else if (auto* uk = dynamic_cast<UnknownNode*>(node.get())) {
		std::cout << indent << "Unknown: " << uk->uk << std::endl;
	}
	else {
		std::cout << indent << "Empty Node" << std::endl;
	}
}

int Interpret(const std::unique_ptr<ASTNode> &node)
{
	
	if(auto* num_node = dynamic_cast<NumberNode*>(node.get()))
	{
		return num_node->value;
	}
	else if(auto* bin_node = dynamic_cast<BinOpNode*>(node.get()))
	{
		if(bin_node->op == "+")
		{
			int lhs = Interpret(bin_node->left);
			int rhs = Interpret(bin_node->right);
			
			return lhs + rhs;
		}
		
		return 0;
	}
	else
	{
		return 0;
	}
	
//	PrintAST(node);
}
