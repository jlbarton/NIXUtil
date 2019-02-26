

#include <string>
#include <vector>
#include <map>
#include <ctype.h>
#include <iostream>


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

	std::map<std::string,TokenType> Scanner::keywords= {
		{"AND",TOK_AND},
		{"OR",TOK_OR},
		{"NOT",TOK_NOT},
		{"GOTO",TOK_GOTO},
		{"IF",TOK_IF},
		{"THEN",TOK_THEN},
		{"FOR",TOK_FOR},
		{"TO", TOK_TO},
		{"NEXT",TOK_NEXT},
		{"GOSUB",TOK_GOSUB},
		{"RETURN",TOK_RETURN},
		{"POP",TOK_POP},
		{"STOP",TOK_STOP},
		{"CONT",TOK_CONT},
		{"END",TOK_END},
		{"REM",TOK_REM}

	};


	//PRIVATE

	//Processes a single token and adds to vector
	void Scanner::ScanToken() {

		char c = Advance();

		switch(c) {

			//whitespace and special
			case ' ': break;
			case ':': AddToken(TOK_EOS); break;
			case '\n': AddToken(TOK_EOL); break;


			//unary operators and symbols
			case '(': AddToken(TOK_LEFT_PAREN); break;
			case ')': AddToken(TOK_RIGHT_PAREN); break;
			case '{': AddToken(TOK_LEFT_BRACE); break;
			case '}': AddToken(TOK_RIGHT_BRACE); break;
			case ',': AddToken(TOK_COMMA); break;
			case '-': AddToken(TOK_MINUS); break;
			case '+': AddToken(TOK_PLUS); break;
			case '*': AddToken(TOK_STAR); break;
			case '/': AddToken(TOK_SLASH); break;
			case '^': AddToken(TOK_CARET); break;
			//
			// //single or double width operators and symbols
			case '=': if(Peek() == '>') {
								Advance();
								AddToken(TOK_GREATER_EQUAL); // "=>"
							} else if(Peek() == '<') {
								Advance();
								AddToken(TOK_LESS_EQUAL); // "=<"
							} else {
								AddToken(TOK_EQUAL); // "=
							}
							break;
			case '<': if(Peek() == '>') {
									Advance();
									AddToken(TOK_NOT_EQUAL); // "<>"
								} else if(Peek() == '=') {
									Advance();
									AddToken(TOK_LESS_EQUAL); // "<="
								} else {
									AddToken(TOK_LESS); // "=
								}
								break;
			case '>': if(Peek() == '<') {
									Advance();
									AddToken(TOK_NOT_EQUAL); // "><"
								} else if(Peek() == '=') {
									Advance();
									AddToken(TOK_GREATER_EQUAL); // ">="
								} else {
									AddToken(TOK_LESS); // "<"
								}
								break;

			//string literals
			case '"': break;

			//special printing character
			case '?': AddToken(TOK_IDENTIFIER);
								break;

			//Identifiers and Keywords and literals
			default:	if(isalpha(c)) {
									GetIdentifier();
								} else if(c == '.' && isdigit(Peek())) {
									GetNumber(c);
								}	else if(isdigit(c)) {
									GetNumber(c);
								} else { // unrecognized token
									AddToken(TOK_ILLEGAL);
								}
								break; //FIXME: needs to report bad characters maybe add unknown tok?
		}
	}



	void Scanner::Retreat() {
		if(current_ > 0) {
			current_--;
		}
	}

	//consumes current character and returns (stack pop)
	char Scanner::Advance() {
		current_++;
		return source_[current_ -1 ];
	}

	//returns character at current index (stack front Peek)
	char Scanner::Peek() {
		return source_[current_];
	}

	char Scanner::PeekNext() {

		if(current_+1 >= source_.length()) {
			return '\0';
		}
		return source_[current_+1];
	}

	//add literal token
	void Scanner::AddToken(TokenType type) {
		tokens_.push_back(Token(type, source_.substr(start_,current_-start_), line_));
		return;
	}

	//true if at end of source, (stack is empty)
	bool Scanner::IsAtEnd() {
		return current_ >= source_.length();
	}


	void Scanner::GetIdentifier() {
		while(isalpha(Peek()) || isdigit(Peek())) {
			Advance();
		}
		//check map
		std::map<std::string,yambasic::TokenType>::iterator it;
		it = keywords.find(source_.substr(start_,current_-start_));

		if(it == keywords.end()) {
			AddToken(TOK_IDENTIFIER);
		} else if(it->second == TOK_REM) {
			while(Peek() != '\n') {
				Advance();
			}
		} else {
			AddToken(it->second);
		}

	}

	void Scanner::GetNumber(char c) {

		bool isFloat = (c == '.');
		//get whole part
		while(isdigit(Peek())) {
				Advance();
		}
		//get fractional part (if not leading decimal point)
		if(Peek() ==  '.' && isdigit(PeekNext())  && !isFloat) {
			isFloat = true;
			Advance();
			while(isdigit(Peek())) {
				Advance();
			}
		}
		if(isFloat) {
			AddToken(TOK_FLOAT);
		} else {
			AddToken(TOK_INTEGER);
		}

	}

	void Scanner::GetString(){

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
