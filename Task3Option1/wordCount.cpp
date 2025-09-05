#include <iostream>
#include <string>
#include <map>
#include <sstream>

int main()
{
	std::string line;
	std::map<std::string, int> countWordsMap;

	while (std::getline(std::cin, line))
	{
		std::istringstream inputStr(line);
		std::string word;

		while (inputStr >> word)
		{
			countWordsMap[word]++;
		}
	}

	auto mapElemCount = countWordsMap.begin();
	while (mapElemCount != countWordsMap.end())
	{
		std::cout << mapElemCount->first << "->" << mapElemCount->second << std::endl;
		++mapElemCount;
	}

	return 0;
}
