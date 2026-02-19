cmake_minimum_required(VERSION 3.10)

project(A-Simple-Compiler)

add_executable(Compiler 
        AST.cpp
        Interpret.cpp
        Lexer.cpp
        Main.cpp
)