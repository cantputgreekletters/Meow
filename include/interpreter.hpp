#if !defined(__INTERPRETER_HPP__)
#define __INTERPRETER_HPP__

#define EMPTY_STRING "NoThIngHeReBoZo"

#include <string>
#include <vector>
#include "include/tokens.hpp"
#include "include/file_handling.hpp"
class Interpreter
{
    private:
        bool read_mode = false;
        bool write_mode = false;
        bool append_mode = false;
        std::string file_path = EMPTY_STRING;
        std::string file_input = EMPTY_STRING;
        std::vector<Token> tk_list;
        bool check_for_path = false;

        void process_parameter(Token tk)
        {
            //Maybe check if some modes are already true and then throw an error
            for (char letter:tk.value)
            {
                switch (letter)
                {
                case '-':
                    // ignore
                    break;
                case 'p':
                    check_for_path = true;
                    break;
                case 'w':
                    write_mode = true;
                    break;
                case 'a':
                    append_mode = true;
                    break;
                case 'r':
                    read_mode = true;
                    break;
                default:
                    /*shoud throw error message*/
                    std::cout << "Parameter " << letter << " is not valid" << std::endl;
                    break;
                }
            }
            
        }
        void process_value(Token tk)
        {
            if ((write_mode || append_mode) && file_input == EMPTY_STRING)
            {
                file_input = tk.value;
            }else if(check_for_path && file_path == EMPTY_STRING)
            {
                file_path = tk.value;
            }
        }
        void filter_parameters()
        {
            for (Token tk:tk_list)
            {
                if (tk.type == TokenType::Value)
                {
                    process_value(tk);
                }else if(tk.type == TokenType::Parameter)
                {
                    process_parameter(tk);
                } else
                {
                    /*should throw error here*/
                }
            }
            
        }
    //returns true if should go ahead
    bool filter_results()
    {
        if(append_mode + write_mode == 2)
        {
            return false;
        }
        if(file_path == EMPTY_STRING && tk_list.size() > 0)
        { 
            if (tk_list[0].type == TokenType::Parameter)
            {
                return false;
            }
            
            file_path = tk_list[0].value;
        } else if(file_path == EMPTY_STRING && tk_list.size() == 0)
        {
            return false;
        }
        if(write_mode + append_mode + read_mode == 0)
        {
            read_mode = true;
        }
        return true;
    }

    void Operate()
    {
        if (append_mode)
        {
            if (file_input == EMPTY_STRING)
            {
                std::cout << "Appending empty string" << std::endl;
            }
            
            AppendToFile(file_path, file_input);
        }
        else if (write_mode)
        {
            WriteToFile(file_path, file_input);
            if (file_input == EMPTY_STRING)
            {
                std::cout << "Writing empty string" << std::endl;
            }
        }
        if (read_mode)
        {
            ReadFile(file_path);
        }
    }
    public:

        Interpreter(std::vector<Token> List)
        {
            tk_list = List;
        }
        void operator()()
        {
            filter_parameters();
            if (! filter_results())
            {
                return;
            }
            Operate();
        }
        void PrintValues()
        {
            std::cout << "read mode = " << read_mode << std::endl;
            std::cout << "write mode = " << write_mode << std::endl;
            std::cout << "append mode = " << append_mode << std::endl;
            std::cout << "file path: " << file_path << std::endl;
            std::cout << "file input: " << file_input << std::endl;
            std::cout << "check for path = " << check_for_path << std::endl;
        }
};

#endif // __INTERPRETER_HPP__
