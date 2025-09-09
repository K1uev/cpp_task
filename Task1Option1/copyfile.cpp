#include <fstream>
#include <iostream>
#include <string>
#include <unistd.h>

bool CheckCorrectUsage(int argc, char* argv[])
{
	if (argc != 3)
	{
		std::cerr << "Правильное использование: " << argv[0] << " <input file name> <output file name>" << std::endl;
		return false;
	}
	return true;
}

bool OpenInputFile(std::ifstream& inFile, const std::string& inputFilename)
{
	inFile.open(inputFilename);
	if (!inFile.is_open())
	{
		std::cerr << "Ошибка открытия файла: " << inputFilename << std::endl;
		return false;
	}
	return true;
}

bool OpenOutputFile(std::ofstream& outFile, const std::string& outputFilename)
{
	outFile.open(outputFilename);
	if (!outFile.is_open())
	{
		std::cerr << "Ошибка создания файла: " << outputFilename << std::endl;
		return false;
	}
	return true;
}

void CopyFile(std::ifstream& inFile, std::ofstream& outFile)
{
	std::string line;
	while (std::getline(inFile, line))
	{
		outFile << line << std::endl;
	}
}

int main(int argc, char* argv[])
{
	if (!CheckCorrectUsage(argc, argv))
	{
		return 1;
	}

	const std::string inputFilename(argv[1]);
	const std::string outputFilename(argv[2]);

	std::ifstream inFile;
	if (!OpenInputFile(inFile, inputFilename))
	{
		return 1;
	}

	std::ofstream outFile;
	if (!OpenOutputFile(outFile, outputFilename))
	{
		inFile.close();
		return 1;
	}

	CopyFile(inFile, outFile);

	inFile.close();
	outFile.close();

	std::cout << "Копирование '" << inputFilename << "' в '" << outputFilename << "' прошло успешно" << std::endl;
	return 0;
}