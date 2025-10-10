#include "crossSet.h"
#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
    try
    {
        if (argc == 2 && std::string(argv[1]) == "-h")
        {
            std::cout << "Программа возвращает два множества:\n"
                << "Первое множество – множество чисел от 1 до N, делящихся без остатка на сумму своих цифр;\n"
                << "Второе множество – множество целых чисел от 1 до N, сумма цифр которых является четной.\n"
                << "Необходимо передать положительное число или \"-h\" для получения справки"
                << std::endl;
            return 0;
        }

        std::string input;
        int lastNum;

        if (argc == 2)
        {
            input = argv[1];
            if (input.empty())
            {
                throw CustomException("Empty input");
            }

            lastNum = std::stoi(input);
            if (lastNum <= 0)
            {
                throw CustomException("Non-positive number");
            }
        }
        else if (argc == 1)
        {
            std::getline(std::cin, input);
            if (input.empty())
            {
                throw CustomException("Empty input");
            }

            lastNum = std::stoi(input);
            if (lastNum <= 0)
            {
                throw CustomException("Non-positive number");
            }
        }
        else
        {
            throw CustomException("Too many arguments");
        }

        std::set<int> setDivisibleByDigitSum = CreateSetDivisibleByDigitSum(lastNum);
        std::set<int> setEvenDigitSum = CreateSetEvenDigitSum(lastNum);
        std::set<int> intersection = CrossSet(setDivisibleByDigitSum, setEvenDigitSum);

        PrintSet(setDivisibleByDigitSum);
        PrintSet(setEvenDigitSum);
        PrintSet(intersection);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
        return 1;
    }

    return 0;
}