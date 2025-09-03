#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>


std::vector<double> ReadNumbers(int argc, char* argv[])
{
	std::vector<double> newVector;
	
	if (argc <= 1)
	{
		return newVector;
	}

	for (int i = 1; i < argc; i++)
	{
		try
		{
			double num = std::stod(argv[i]);
			newVector.push_back(num);
		}
		catch (const std::exception& e)
		{
			std::cerr << "ERROR" << std::endl;
			return std::vector<double> {};
		}
	}

	return newVector;
} 

std::vector<double> ProcessNumbers(std::vector<double> dValue)
{
	std::vector<double> newVectorUpdated;

	if(dValue.size() == 0)
	{
		return newVectorUpdated;
	}

	auto minIt = std::min_element(dValue.begin(), dValue.end());
	double minValue = *minIt;
	
	
	for (size_t i = 0; i < dValue.size(); i++)
	{
		newVectorUpdated.push_back(dValue[i] * minValue);
	}

	return newVectorUpdated;
}

void PrintSortedNumbers(std::vector<double> dValue)
{
	if(dValue.size() == 0)
	{
		std::cout << std::endl;
		return;
	}

	std::sort(dValue.begin(), dValue.end());

	for (size_t i = 0; i < dValue.size(); i++)
	{
		std::cout << std::fixed << std::setprecision(3) << dValue[i] << " ";
	}
	std::cout << std::endl;
}

int main(int argc, char* argv[])
{
	std::vector<double> readNumbers = ReadNumbers(argc, argv);
	std::vector<double> processNumbers = ProcessNumbers(readNumbers);
	PrintSortedNumbers(processNumbers);
	return 0;
}



/*
Выводится результат в порядке убывания, но по заданию должен выводиться в порядке неубывания

Пример 2
Ввод:

10 7 4
Вывод:

40.000 28.000 16.000
Объяснение: минимальный элемент - 4, умножаем каждый элемент массива на 4.
*/