#include "WordCount.h"
#include <iostream>

int main()
{
    try
    {
        WordCountMap wordCountMap = CountWordsFromStream(std::cin);
        PrintWordCount(wordCountMap);
    }
    catch (...)
    {
        std::cout << "ERROR" << std::endl;
        return 1;
    }

    return 0;
}