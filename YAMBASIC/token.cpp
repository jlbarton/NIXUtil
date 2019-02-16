
#include <string>
#include <iostream>
#include <sstream>

#include <token.h>

namespace yambasic {





Token::Token(TokenType type, std::string lexeme, int line) {
	type_ = type;
	lexeme_ = lexeme;
	line_ = line;
}

std::string Token::ToString() {

		std::stringstream token_string;
		token_string << "Type:" << int(type_) << " Lexeme:"
								 << lexeme_ << " Line:" << line_;
		return token_string.str();
}

















}
