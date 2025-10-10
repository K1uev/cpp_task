#include "WordCount.h"
#include <iostream>
#include <map>
#include <string>

WordCountMap CountWordsFromStream(std::istream& input)
{
    WordCountMap wordCountMap{};
    std::string word{};

    while (input >> word)
    {
        wordCountMap[word]++;
    }

    return wordCountMap;
}

void PrintWordCount(const WordCountMap& wordCountMap)
{
    auto mapElemCount = wordCountMap.begin();
    while (mapElemCount != wordCountMap.end())
    {
        std::cout << mapElemCount->first << "->" << mapElemCount->second << std::endl;
        ++mapElemCount;
    }
}