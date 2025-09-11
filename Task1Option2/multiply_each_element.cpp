#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

std::vector<double> ReadNumbers(int argc, char* argv[])
{
	std::vector<double> newVector{};

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
			std::cout << "ERROR" << std::endl;
			return std::vector<double>{};
		}
	}

	return newVector;
}

std::vector<double> ProcessNumbers(const std::vector<double>& dValue)
{
	std::vector<double> newVectorUpdated{};

	if (dValue.empty())
	{
		return newVectorUpdated;
	}

	auto minEl = std::min_element(dValue.begin(), dValue.end());
	double minValue = *minEl;

	for (size_t i = 0; i < dValue.size(); i++)
	{
		newVectorUpdated.push_back(dValue[i] * minValue);
	}

	return newVectorUpdated;
}

void PrintSortedNumbers(const std::vector<double>& dValue)
{
	if (dValue.empty())
	{
		std::cout << std::endl;
		return;
	}
	std::vector<double> sortedValue = dValue;
	std::sort(sortedValue.begin(), sortedValue.end());

	for (size_t i = 0; i < sortedValue.size(); i++)
	{
		std::cout << std::fixed << std::setprecision(3) << sortedValue[i] << " ";
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