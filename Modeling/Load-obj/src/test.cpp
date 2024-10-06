#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

int main()
{
    std::string path = "G:\\OpenGL\\Modeling\\Modeling\\resources\\models\\cornellbox\\floor.obj";
    std::ifstream file(path, std::ios::in);
    if (file.is_open() == false)
    {
        std::cerr << "Failed to load obj: " << path << std::endl;
        return -1;
    }

    std::string line;
    while (getline(file, line))
    {
        std::istringstream iss(line);
        std::string prefix;
        iss >> prefix;

        if (prefix == "v")
        {

        }
    }

    return 0;
}

