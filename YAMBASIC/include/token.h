#ifndef YAMBASIC_TOKEN_H
#define YAMBASIC_TOKEN_H
namespace yambasic{

#include <string>


enum TokenType {

	//Single Characters
	LEFT_PAREN, RIGHT_PAREN, LEFT_BRACE, RIGHT_BRACE, COMMA, DOT, MINUS, PLUS,
	SEMICOLON, SLASH, START

	//Single or Double Character
	EQUAL, NOT_EQUAL, GREATER, GREATER_EQUAL, LESS, LESS_EQUAL,

	//Literals
	IDENTIFIER, STRING, NUMBER,

	//Reserved Keywords

	//operators
	AND, OR, NOT,

	//control
	GOTO, IF, THEN, FOR, TO, NEXT, GOSUB, RETURN, POP, STOP, CON, END,

	//built in functions
	FUNC,

	//endings and markers
	EOS, // end of statement
	EOF, // end of file
	REM, // comment

}

}

class Token {

private:

public:
	TokenType type;
	string lexeme;
	void * literal;
	int line;


	Token(TokenType type, string lexeme, void * literal, int line);

	




}




#endif
