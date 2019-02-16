

#include <string>
#include <vector>

#include <scanner.h>
#include <token.h>

/* Grammar ideas:
if a character is special operator ( of a set like (){},.-+;*), then we can
process it immediately.. if it is of a certain type that can be double characters
operator (like <= >=, etc) then we must look for both.

when it comes to operators and number and such we can skip past whitespace, but
identifiers must be bounded by whitespace.


so if single, case statement to capture, if number we need to to build up an
integer or float


NOTE: to correctly do GOTOS, lines must start with a line label, there will be
a map that associates line numbers with vector positions. The map will be updated
if line numbers change. but a  goto statement will move the current execution to
the associated line

*/
namespace yambasic {


	//PRIVATE

	//Processes a single token and adds to vector
	void Scanner::ScanToken() {

		char c = advance();

		switch(c) {

			//whitespace and special
			case ':': addToken(TOK_EOS); break;


			//unary operators and symbols
			case '(': addToken(TOK_LEFT_PAREN); break;
			case ')': addToken(TOK_RIGHT_PAREN); break;
			case '{': addToken(TOK_LEFT_BRACE); break;
			case '}': addToken(TOK_RIGHT_BRACE); break;
			case ',': addToken(TOK_COMMA); break;
			case '-': addToken(TOK_MINUS); break;
			case '+': addToken(TOK_PLUS); break;
			case '*': addToken(TOK_STAR); break;
			case '/': addToken(TOK_SLASH); break;
			case '^': addToken(TOK_CARET); break;
			//
			// //single or double width operators and symbols
			// case '=': addToken() break;
			// case '<': addToken() break;
			// case '>': addToken() break;

			//Identifiers and Keywords

			//numbers

			default: break;

		}
	}

	//consumes current character and returns (stack pop)
	char Scanner::advance() {
		current_++;
		return source_[current_ -1 ];
	}

	//returns character at current index (stack front peek)
	char Scanner::peek() {
		return '\0';
	}

	//add literal token
	void Scanner::addToken(TokenType type) {
		tokens_.push_back(Token(type, source_.substr(start_,current_-start_), line_));
		return;
	}

	//true if at end of source, (stack is empty)
	bool Scanner::IsAtEnd() {
		return current_ >= source_.length();
	}


	//PUBLIC
	Scanner::Scanner(std::string source) {
		source_ = source;
		start_ = 0;
		current_ = 0;
		line_ = 1;

	}
	std::vector<Token> Scanner::ScanTokens() {

			while(!this->IsAtEnd()) {
				ScanToken();
				start_ = current_;
			}

			//add final EOF token
			tokens_.push_back(Token(TOK_EOF, "EOF", line_));

			return tokens_;
	}












}
