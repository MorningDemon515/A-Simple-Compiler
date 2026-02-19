#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdexcept>

#include "Interpret.h"

std::string getExtension(const std::string& filename)
{
	size_t pos = filename.find_last_of('.');
	if (pos == std::string::npos || pos == filename.length() - 1) {
		return "";
	}
	return filename.substr(pos + 1);
}

int main(int argc, char *argv[])
{
	std::vector<std::string> arg_s;
	for(int i = 1;i < argc;++i){
		arg_s.push_back(std::string(argv[i]));
	}
	
	std::string ext = "";
    for(size_t i = 0; i < arg_s.size();++i){
		ext = getExtension(arg_s[i]);
		if(ext != "script")
			std::cerr << (arg_s[i] + " File format error!") << std::endl;
	}
//-------------------------------------------------------------------------
	std::ifstream file(argv[1]);
	
	if (!file.is_open()) {
		std::cerr << "Unable to open script: " + std::string(argv[1]) << std::endl;
		return -1;
	}
	
	std::stringstream fileStream;
	fileStream << file.rdbuf();
	file.close();
	
	std::string code = fileStream.str();
	
	Lexer l = Lexer(code);
	Parser p = Parser(l);
	std::unique_ptr<ASTNode> node = p.Work();
	
	int result = Interpret(node);
	std::cout << "result: " << result << std::endl;
	
	system("pause");
	return 0;
}
