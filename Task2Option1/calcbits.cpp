#include <climits>
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <string>

class NegativeValueException : public std::invalid_argument
{
public:
	NegativeValueException()
		: std::invalid_argument("Negative value")
	{
	}
};

class InvalidInputException : public std::invalid_argument
{
public:
	InvalidInputException()
		: std::invalid_argument("Invalid input")
	{
	}
};

class OutOfRangeException : public std::out_of_range
{
public:
	OutOfRangeException()
		: std::out_of_range("Number too large")
	{
	}
};

class TooManyArgumentsException : public std::runtime_error
{
public:
	TooManyArgumentsException()
		: std::runtime_error("Too many arguments")
	{
	}
};

bool CheckArgValueHelp(int argc, char* argv[])
{
	if (argc == 2 && strcmp(argv[1], "-h") == 0)
	{
		std::cout << "Приложение выполняет подсчет и вывод количества единичных битов в байте\nПередача происходит следующим образом:\ncalcbits.exe <byte>" << std::endl;
		return true;
	}
	return false;
}

void CheckPositivityValue(int value)
{
	if (value < 0)
	{
		throw NegativeValueException();
	}
}

int CountLastBits(int value)
{
	int count = 0;
	unsigned char byteValue = value & 0xFF;

	while (byteValue)
	{
		count += byteValue & 1;
		byteValue >>= 1;
	}

	return count;
}

void GetBitCountFromValue(int value)
{
	CheckPositivityValue(value);
	int bitCount = CountLastBits(value);
	std::cout << bitCount << std::endl;
}

void GetBitCountFromInput()
{
	int cinValue;
	if (std::cin >> cinValue)
	{
		GetBitCountFromValue(cinValue);
	}
	else
	{
		throw InvalidInputException();
	}
}

void GetBitCountFromArg(char* arg)
{
	try
	{
		int paramValue = std::stoi(arg);
		GetBitCountFromValue(paramValue);
	}
	catch (const std::invalid_argument&)
	{
		throw InvalidInputException();
	}
	catch (const std::out_of_range&)
	{
		throw OutOfRangeException();
	}
}

int main(int argc, char* argv[])
{
	try
	{
		if (CheckArgValueHelp(argc, argv))
		{
			return 0;
		}

		if (argc == 1)
		{
			GetBitCountFromInput();
		}
		else if (argc == 2)
		{
			GetBitCountFromArg(argv[1]);
		}
		else if (argc > 2)
		{
			throw TooManyArgumentsException();
		}

		return 0;
	}
	catch (const NegativeValueException& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	catch (const InvalidInputException& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	catch (const OutOfRangeException& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	catch (const TooManyArgumentsException& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
}