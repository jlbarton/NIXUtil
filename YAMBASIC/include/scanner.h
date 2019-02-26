#ifndef YAMBASIC_SCANNER_H
#define YAMBASIC_SCANNER_H

#include <string>
#include <vector>
#include <map>
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
	void Retreat();
	char Advance();
	char Peek();
	char PeekNext();
	void AddToken(TokenType type);
	bool IsAtEnd();
	void GetIdentifier();
	void GetNumber(char c);
	void GetString();



public:
	static std::map<std::string,TokenType> keywords;
	Scanner(std::string source);
	std::vector<Token> ScanTokens();


};











}
#endif
