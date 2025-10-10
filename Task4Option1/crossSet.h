#pragma once
#include <set>
#include <string>
#include <stdexcept>

class CustomException : public std::runtime_error
{
public:
    CustomException(const std::string& message)
        : std::runtime_error(message)
    {
    }
};

int SumOfDigits(int num);
std::set<int> CreateSetDivisibleByDigitSum(int lastNum);
std::set<int> CreateSetEvenDigitSum(int lastNum);
void PrintSet(const std::set<int>& printedSet);
std::set<int> CrossSet(const std::set<int>& set1, const std::set<int>& set2);