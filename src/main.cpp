#include <iostream>
#include <string>
#include <vector>
#include "include/tokenizer.hpp"
#include "include/interpreter.hpp"

int main(int argc, char * argv[])
{
    if (argc == 1)
    {
        return -1;
    }
    std::string args[argc - 1] = {};
    for (int i = 1; i < argc; i++)
    {
        args[i - 1] = argv[i];
    }
    Tokenizer tokenizer(args, argc - 1);
    std::vector<Token> token_list = tokenizer();
    Interpreter interpreter(token_list);
    interpreter();
    return 0;
}
