#include <iostream>
#include <string>

std::string TrimBlanks(std::string const& str)
{
	if (str.empty())
	{
		return str;
	}

	size_t start = 0;
	while (start < str.size() && str[start] == ' ')
	{
		start++;
	}

	size_t end = str.size();
	while (end > start && str[end - 1] == ' ')
	{
		end--;
	}

	return str.substr(start, end - start);
}

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