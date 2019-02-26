#ifndef YAMBASIC_TOKEN_H
#define YAMBASIC_TOKEN_H
#include <string>
namespace yambasic{

enum TokenType {
	//Single Characters
	TOK_LEFT_PAREN, TOK_RIGHT_PAREN, TOK_LEFT_BRACE, TOK_RIGHT_BRACE, TOK_COMMA,
	TOK_DOT, TOK_MINUS, TOK_PLUS, TOK_SLASH, TOK_STAR, TOK_CARET,
	//Single or Double Character
	TOK_EQUAL, TOK_NOT_EQUAL, TOK_GREATER, TOK_GREATER_EQUAL, TOK_LESS,
	TOK_LESS_EQUAL,
	//Literals
	// note variable names only read the first 2 characters as IDENTIFIER
	TOK_IDENTIFIER, TOK_STRING, TOK_FLOAT, TOK_INTEGER,
	//Reserved Keywords
	//operators
	TOK_AND, TOK_OR, TOK_NOT,
	//control
	TOK_GOTO, TOK_IF, TOK_THEN, TOK_FOR, TOK_TO, TOK_NEXT, TOK_GOSUB, TOK_RETURN,
	TOK_POP, TOK_STOP, TOK_CONT, TOK_END,

	//endings and markers
	TOK_REM, // comment
	TOK_EOS, // end of statement
	TOK_EOL, // end of line
	TOK_EOF, // end of file
	TOK_ILLEGAL // illegal or unknown token/character
};



class Token {

private:

public:
	TokenType type_;
	std::string lexeme_;
	int line_;

	Token(TokenType type, std::string lexeme, int line);
	std::string ToString();

};



}
#endif
