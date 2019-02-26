


#include <iostream>
#include <string>
#include <vector>

#include <yambasic.h>
#include <scanner.h>
#include <token.h>

int main(int argc, char * arv[]) {


	std::string test = "(){},.+-*/:= => =< < <> >< <= >= \nAND OR NOT PRINT ? A3 AB B6 Z \n R5=B 33 .1 3.6 .2.2 53.5.";
	yambasic::Scanner tscanner(test);
	std::vector<yambasic::Token> tokens = tscanner.ScanTokens();

	std::cout << test << std::endl;
	for(yambasic::Token t: tokens) {
			std::cout << t.ToString() << std::endl;
	}


	return 0;
}
