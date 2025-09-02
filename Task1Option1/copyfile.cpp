#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>

bool checkCorrectUsage(int argc, char* argv[]) {
	if (argc != 3) {
		std::cerr << "Правильное использование: " << argv[0] << " <input file name> <output file name>" << std::endl;
		return false;
	}
	return true;
}

bool checkFileAccess(const std::string& filename) {
	if (access(filename.c_str(), F_OK) != 0) {
		std::cerr << "Файл '" << filename << "' не существует" << std::endl;
		return false;
	}

	if (access(filename.c_str(), R_OK) != 0) {
		std::cerr << "Нет прав на чтнение файла '" << filename << "'" << std::endl;
		return false;
	}
	return true;
}

bool checkOpenedInputFile(std::ifstream& inFile, const std::string& inputFilename) {
	if (!checkFileAccess(inputFilename)) {
		return false;
	}

	inFile.open(inputFilename);
	if (!inFile.is_open()) {
		std::cerr << "Ошибка открытия файла: " << inputFilename << std::endl;
		return false;
	}
	return true;
}

bool checkOpenedOutputFile(std::ofstream& outFile, const std::string& outputFilename) {
	outFile.open(outputFilename);
	if (!outFile.is_open()) {
		std::cerr << "Ошибка создания файла: " << outputFilename << std::endl;
		return false;
	}
	return true;
}

void copyFile(std::ifstream& inFile, std::ofstream& outFile) {
	std::string line;
	while (std::getline(inFile, line)) {
		outFile << line << std::endl;
	}
}

int main(int argc, char* argv[]) {
	if (!checkCorrectUsage(argc, argv)) {
		return 1;
	}

	const std::string inputFilename(argv[1]);
	const std::string outputFilename(argv[2]);

	std::ifstream inFile;
	if (!checkOpenedInputFile(inFile, inputFilename)) {
		return 1;
	}

	std::ofstream outFile;
	if (!checkOpenedOutputFile(outFile, outputFilename)) {
		return 1;
	}

	copyFile(inFile, outFile);

	inFile.close();
	outFile.close();

	std::cout << "Копирование '" << inputFilename << "' в '" << outputFilename << "' прошло успешно" << std::endl;
	return 0;
}