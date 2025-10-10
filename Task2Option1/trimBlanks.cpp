#include "trimBlanks.h"
#include <string>

std::string TrimBlanks(std::string const& str)
{
    if (str.empty())
    {
        return str;
    }

    size_t start = str.find_first_not_of(" \t\n\r\f\v");

    if (start == std::string::npos)
    {
        return "";
    }

    size_t end = str.find_last_not_of(" \t\n\r\f\v");

    size_t length = end - start + 1;

    return str.substr(start, length);
}