#include <iostream>
#include <map>
#include <string>

using wordCountMap = std::map<std::string, int>;

wordCountMap CountWordsFromStream(std::istream& input)
{
	wordCountMap wordCountMap;
	std::string word;

	while (input >> word)
	{
		wordCountMap[word]++;
	}

	return wordCountMap;
}

void PrintWordCount(const wordCountMap& wordCountMap)
{
	auto mapElemCount = wordCountMap.begin();
	while (mapElemCount != wordCountMap.end())
	{
		std::cout << mapElemCount->first << "->" << mapElemCount->second << std::endl;
		++mapElemCount;
	}
}

int main()
{
	try
	{
		wordCountMap wordCountMap = CountWordsFromStream(std::cin);
		PrintWordCount(wordCountMap);
	}
	catch (...)
	{
		std::cout << "ERROR" << std::endl;
		return 1;
	}

	return 0;
}