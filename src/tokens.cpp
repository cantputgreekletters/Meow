#include "include/tokens.hpp"
#include <iostream>


std::string TokenTypeToString(TokenType type)
{
    std::string tk_type;
    if (type == TokenType::Parameter)
    {
        tk_type = "Parameter";
    } else if(type == TokenType::Value)
    {
        tk_type = "Value";
    }else{
        tk_type = "Error";
    }
    return tk_type;
}

std::string TokenToString(Token tk)
{
    std::cout  << "Asdsad\n";
    std::string text;
    //seg fault at tk.value
    text = "Type: " + TokenTypeToString(tk.type) + ", Value: " + tk.value + '\n';
    std::cout  << "bobobo\n";
    return text;
}

std::string TokenListToString(std::vector<Token> tk_list)
{
    std::string text = "";
    
    for(Token current_token:tk_list)
    {
        text += TokenToString(current_token);
        text += ", ";
    }
    return text;
}

Token NewToken(TokenType type, std::string value)
{   
    Token new_tk;
    new_tk.type = type;
    new_tk.value = value;
    return new_tk;
}
