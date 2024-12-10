#if !defined(FILE_HANDLING_HPP)
#define FILE_HANDLING_HPP

#include <fstream>
#include <ostream>
#include <iostream>

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


#endif // FILE_HANDLING_HPP
