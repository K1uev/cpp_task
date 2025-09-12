#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>

class InvalidInputException : public std::runtime_error
{
public:
	InvalidInputException(const std::string& message)
		: std::runtime_error(message)
	{
	}
};

class EmptyValueException : public std::runtime_error
{
public:
	EmptyValueException(const std::string& message)
		: std::runtime_error(message)
	{
	}
};

class InvalidArgumentException : public std::runtime_error
{
public:
	InvalidArgumentException(const std::string& message)
		: std::runtime_error(message)
	{
	}
};

void IsValidInput(const std::string& input)
{
	if (input.empty())
	{
		throw EmptyValueException("Empty input");
	}

	for (char inputChar : input)
	{
		if (!std::isdigit(inputChar))
		{
			throw InvalidArgumentException("None digits in input");
		}
	}
}

void IsPositiveNum(const int& input)
{
	if (input <= 0)
	{
		throw InvalidArgumentException("None positive number");
	}
}

int SumEachNum(int num)
{
	int sum = 0;

	while (num > 0)
	{
		sum += num % 10;
		num /= 10;
	}

	return sum;
}

std::set<int> CreateSetEachNumDevideSumNum(int lastNum)
{
	std::set<int> setDevideSumNum{};
	for (int i = 1; i <= lastNum; i++)
	{
		int sum = SumEachNum(i);
		if (sum != 0 && i % sum == 0)
		{
			setDevideSumNum.insert(i);
		}
	}

	return setDevideSumNum;
}

std::set<int> CreateSetSumEven(int lastNum)
{
	std::set<int> setSumEven{};
	for (int i = 1; i <= lastNum; i++)
	{
		if (SumEachNum(i) % 2 == 0)
		{
			setSumEven.insert(i);
		}
	}

	return setSumEven;
}

void PrintSet(const std::set<int>& printedSet)
{
	if (printedSet.empty())
	{
		std::cout << std::endl;
	}

	for (auto i = printedSet.begin(); i != printedSet.end(); i++)
	{
		std::cout << *i << " ";
	}
	std::cout << std::endl;
}

std::set<int> CrossSet(std::set<int> const& set1, std::set<int> const& set2)
{
	std::set<int> setCross{};
	std::set_intersection(set1.begin(), set1.end(),
		set2.begin(), set2.end(),
		std::inserter(setCross, setCross.begin()));

	return setCross;
}

int main(int argc, char* argv[])
{
	try
	{
		if (argc == 2 && std::string(argv[1]) == "-h")
		{
			std::cout << "Программа возвращает два множества:\n"
					  << "Первое множество – множество чисел от 1 до N, делящихся без остатка на сумму своих цифр;\n"
					  << "Второе множество – множество целых чисел то 1 до N, сумма цифр которых является четной.\n"
					  << "Необходимо передать положительное число или \"-h\" для получения справки"
					  << std::endl;

			return 0;
		}

		std::string input;
		int lastNum;

		if (argc == 2)
		{
			input = argv[1];
			IsValidInput(input);
			lastNum = std::stoi(input);
			IsPositiveNum(lastNum);
		}
		else if (argc == 1)
		{
			std::getline(std::cin, input);
			IsValidInput(input);
			lastNum = std::stoi(input);
			IsPositiveNum(lastNum);
		}
		else
		{
			throw InvalidInputException("Too many arguments");
		}

		std::set<int> setEachNumDevideSumNum = CreateSetEachNumDevideSumNum(lastNum);
		std::set<int> setSumEven = CreateSetSumEven(lastNum);
		std::set<int> intersection = CrossSet(setEachNumDevideSumNum, setSumEven);

		PrintSet(setEachNumDevideSumNum);
		PrintSet(setSumEven);
		PrintSet(intersection);
	}
	catch (const EmptyValueException& e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}
	catch (const InvalidInputException& e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}
	catch (const InvalidArgumentException& e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}
	catch (...)
	{
		std::cout << "ERROR" << std::endl;
		return 1;
	}

	return 0;
}