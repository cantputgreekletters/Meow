#include <fstream>
#include <iostream>
#include <ostream>
#include <string>

#define ERROR_FILE_NOT_FOUND "File not found"

bool ReadFile(std::string file_path)
{
    std::ifstream FILE;
    FILE.open(file_path, std::fstream::in);
    if (!FILE)
    {
        std::cout << ERROR_FILE_NOT_FOUND << std::endl;
        return false;
    }
    std::string line;
    while (getline(FILE, line))
    {
        std::cout << line << '\n';
    }
    FILE.close();
    return true;
}

bool WriteToFile(std::string file_path, std::string contents)
{
    std::ofstream FILE;
    FILE.open(file_path, std::ofstream::out);
    if (! FILE) {
        std::cout << ERROR_FILE_NOT_FOUND << std::endl;
        return false;
    }
    FILE << contents << std::endl;
    FILE.close();
    return true;
}

bool AppendToFile(std::string file_path, std::string contents)
{
    std::ofstream FILE;
    FILE.open(file_path, std::ofstream::app);
    if (!FILE)
    {
        std::cout << ERROR_FILE_NOT_FOUND << std::endl;
        return -1;
    }
    FILE << contents << std::endl;
    FILE.close();
    return true;
}

unsigned int ProcessArgument(std::string arg)
{
    if(arg[0] != '-')
    {
        return 0;
    }
    switch (arg[1])
    {
    case 'w':
        return 1;
        break;

    case 'a':
        return 2;
        break;
    }
    return 0;
}
int main(int argc, char * argv[])
{
    if (argc < 2) {
        std::cout << "No path was given" << std::endl;
        return 0;
    }

    bool result;
    std::string file_path;
    if (argc == 4)
    {
        unsigned int op_idx = ProcessArgument(argv[1]);
        file_path = argv[2];
        std::string contents = argv[3];
        switch (op_idx)
        {
        case 0:
            std::cout << "Argument '"<< argv[1] << "' is not valid!!\n";
            return -1;
            break;
        case 1:
            result = WriteToFile(file_path, contents);
            break;
        case 2:
            result = AppendToFile(file_path, contents);
            break;
        }
        if(!result)
        {
            return -1;
        }
        return 0;
    }
    file_path = argv[1];
    result = ReadFile(file_path);
    if(!result)
    {
        return -1;
    }
    return 0;
}
