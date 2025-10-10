#pragma once
#include <iostream>
#include <map>
#include <string>

using WordCountMap = std::map<std::string, int>;

WordCountMap CountWordsFromStream(std::istream& input);
void PrintWordCount(const WordCountMap& wordCountMap);