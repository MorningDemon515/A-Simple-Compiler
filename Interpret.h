#ifndef INTERPRET_H
#define INTERPRET_H

#include "Token.h"
#include "Lexer.h"
#include "AST.h"

int Interpret(const std::unique_ptr<ASTNode> &node);

#endif
