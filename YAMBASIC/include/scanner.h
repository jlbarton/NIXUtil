#ifndef YAMBASIC_SCANNER_H
#define YAMBASIC_SCANNER_H

#include <string>
#include <vector>
#include <token.h>
namespace yambasic{


// Scanner goes through a source string character by character, building up
// tokens until it reachs the end, need to keep track of current source position
class Scanner {
private:
	std::string source_;
	std::vector<Token> tokens_;
	unsigned int start_;
	unsigned int current_;
	unsigned int line_;


	void ScanToken();
	char advance();
	char peek();
	void addToken(TokenType type);
	bool IsAtEnd();



public:
	Scanner(std::string source);
	std::vector<Token> ScanTokens();


};











}
#endif
