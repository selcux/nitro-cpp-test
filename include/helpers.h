#ifndef ASSIGNMENT1_HELPERS_H
#define ASSIGNMENT1_HELPERS_H

#include <string>
#include <fstream>

inline std::string read_json(char file_path[])
{
    std::ifstream ifs(file_path);
    std::string content((std::istreambuf_iterator<char>(ifs)),
            std::istreambuf_iterator<char>());

    return content;
}

#endif //ASSIGNMENT1_HELPERS_H
