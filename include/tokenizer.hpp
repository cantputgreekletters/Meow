#if !defined(__TOKENIZER_HPP__)
#define __TOKENIZER_HPP__

#include <iostream>
#include <string>
#include <vector>
#include "include/tokens.hpp"

class Tokenizer
{
    private:
        std::string * input;
        unsigned int length;
        int current_tk_idx = -1;
        std::string * current_text_ptr;
        std::vector<Token> token_list;
        //add error

        void Next()
        {
            current_tk_idx ++;
            if (current_tk_idx >= length) {
                current_text_ptr = NULL;
            }
            else{
                current_text_ptr = &input[current_tk_idx];
            }
        }
    public:

        Tokenizer(std::string * Input, unsigned int len)
        {
            input = Input;
            length = len;
        }

        std::vector<Token> operator()()
        {
            Next();
            while (current_text_ptr) {
                if ((*current_text_ptr)[0] == '-')
                {
                    token_list.push_back(NewToken(TokenType::Parameter, *current_text_ptr));
                } else
                {
                    token_list.push_back(NewToken(TokenType::Value, *current_text_ptr));
                }
                Next();
            }
            return token_list;
        }
};


#endif // __TOKENIZER_HPP__
