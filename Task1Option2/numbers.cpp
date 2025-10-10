#include "numbers.h"
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
#include <string>

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

void ProcessNumbers(std::vector<double>& dValue)
{
    if (dValue.empty())
    {
        return;
    }

    auto minEl = std::min_element(dValue.begin(), dValue.end());
    double minValue = *minEl;

    std::transform(dValue.begin(), dValue.end(), dValue.begin(),
        [minValue](double x) { return x * minValue; });
}

void PrintSortedNumbers(std::vector<double>& dValue)
{
    if (dValue.empty())
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