#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Правильное использование: copyfile.exe <input file name> <output file name>" << std::endl;
        return 1;
    }

    const std::string inputFilename(argv[1]);
    const std::string outputFilename(argv[2]);

    std::ifstream inFile(inputFilename);
    if (!inFile.is_open()) {
        std::cerr << "Ошибка открытия файла: " << inputFilename << std::endl;
        return 1;
    }

    std::ofstream outFile(outputFilename);
    if (!outFile.is_open()) {
        std::cerr << "Ошибка создания файла: " << outputFilename << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inFile, line)) {
        outFile << line << std::endl;
    }

    std::cout << "Копирование '" << inputFilename << "' в '" << outputFilename << "' прошло успешно" << std::endl;
    return 0;
}