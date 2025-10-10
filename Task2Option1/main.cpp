#include "trimBlanks.h"
#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
    try
    {
        if (argc <= 1)
        {
            throw std::invalid_argument("No arguments");
        }

        std::string input = argv[1];
        std::cout << TrimBlanks(input) << std::endl;
    }
    catch (...)
    {
        std::cout << "ERROR" << std::endl;
        return 1;
    }

    return 0;
}