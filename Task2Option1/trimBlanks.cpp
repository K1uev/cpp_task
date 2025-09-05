#include <iostream>
#include <string>

std::string TrimBlanks(std::string const& str)
{
	std::string returnStr;
	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] != ' ')
		{
			returnStr.push_back(str[i]);
		}
	}

	return returnStr;
}

int main(int argc, char* argv[])
{
	if (argc > 1)
	{
		std::string input = argv[1];
		std::cout << TrimBlanks(input) << std::endl;
	}
	else
	{
		std::cout << "ERROR" << std::endl;
		return 1;
	}

	return 0;
}