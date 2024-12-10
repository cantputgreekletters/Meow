#if !defined(__TOKENS_HPP__)
#define __TOKENS_HPP__

#include <string>
#include <vector>

typedef enum
{
    Parameter,
    Value
} TokenType;

typedef struct
{
    TokenType type;
    std::string value;
} Token;

std::string TokenToString(Token tk);
std::string TokenListToString(std::vector<Token> tk_list);
Token NewToken(TokenType type, std::string value);
#endif // __TOKENS_HPP__
