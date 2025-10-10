#include "crossSet.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <stdexcept>
#include <string>

int SumOfDigits(int num)
{
    int sum = 0;
    while (num > 0)
    {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

std::set<int> CreateSetDivisibleByDigitSum(int lastNum)
{
    std::set<int> setDivisibleByDigitSum{};
    for (int i = 1; i <= lastNum; i++)
    {
        int sum = SumOfDigits(i);
        if (sum != 0 && i % sum == 0)
        {
            setDivisibleByDigitSum.insert(i);
        }
    }
    return setDivisibleByDigitSum;
}

std::set<int> CreateSetEvenDigitSum(int lastNum)
{
    std::set<int> setEvenDigitSum{};
    for (int i = 1; i <= lastNum; i++)
    {
        if (SumOfDigits(i) % 2 == 0)
        {
            setEvenDigitSum.insert(i);
        }
    }
    return setEvenDigitSum;
}

void PrintSet(const std::set<int>& printedSet)
{
    for (auto i = printedSet.begin(); i != printedSet.end(); i++)
    {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
}

std::set<int> CrossSet(const std::set<int>& set1, const std::set<int>& set2)
{
    std::set<int> setCross{};
    std::set_intersection(set1.begin(), set1.end(),
        set2.begin(), set2.end(),
        std::inserter(setCross, setCross.begin()));
    return setCross;
}