


#include <iostream>
#include <string>
#include <vector>

#include <yambasic.h>
#include <scanner.h>
#include <token.h>

int main(int argc, char * arv[]) {


	std::string test = "(){},.+-*/";
	yambasic::Scanner tscanner(test);
	std::vector<yambasic::Token> tokens = tscanner.ScanTokens();

	std::cout << test << std::endl;
	for(yambasic::Token t: tokens) {
			std::cout << t.ToString() << std::endl;
	}


	return 0;
}
