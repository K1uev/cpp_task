#include <iostream>
#include <string>
#include <cstring>
#include <stdexcept>
#include <climits>

bool checkArgCount(int argc, char* argv[]) {
	if (argc > 2) {
		std::cerr << "Передано 2 или более параметров" << std::endl;
		return false;
	}
	return true;
}

bool checkArgValueHelp(int argc, char* argv[]) {
	if (argc == 2 && strcmp(argv[1], "-h") == 0) {
		std::cout << "Приложение выполняет подсчет и вывод количества единичных битов в байте\nПередача происходит следующим образом:\ncalcbits.exe <byte>" << std::endl;
		return true;
	}
	return false;
}

void checkPositivityValue(int value) {
	if (value < 0) {
		throw std::invalid_argument("Negative value");
	}
}

int countLastBits(int value) {
	int count = 0;
	unsigned char byteValue = value & 0xFF;
	
	while (byteValue) {
		count += byteValue & 1;
		byteValue >>= 1;
	}
	
	return count;
}

void getBitCountFromValue(int value) {
	checkPositivityValue(value);
	
	int bitCount = countLastBits(value);
	std::cout << bitCount << std::endl;
}

void getBitCountFromInput() {
	int cinValue;
	if (std::cin >> cinValue) {
		getBitCountFromValue(cinValue);
	} else {
		std::cerr << "Введено не число" << std::endl;
		throw std::invalid_argument("Invalid input");
	}
}

void getBitCountFromArg(char* arg) {
	try {
		int paramValue = std::stoi(arg);
		getBitCountFromValue(paramValue);
	}
	catch (const std::invalid_argument& e) {
		std::cerr << "Аргумент должен быть числом" << std::endl;
		throw;
	}
	catch (const std::out_of_range& e) {
		std::cerr << "Число слишком большое" << std::endl;
		throw;
	}
}

int main(int argc, char* argv[])
{
	if (checkArgValueHelp(argc, argv)) {
		return 0;
	}
	
	if (!checkArgCount(argc, argv)) {
		return 1;
	}

	try {
		if (argc == 1) {
			getBitCountFromInput();
		} else if (argc == 2) {
			getBitCountFromArg(argv[1]);
		}
		return 0;
	}
    catch (const std::invalid_argument& e) {
        if (std::strcmp(e.what(), "Negative value") == 0) {
            std::cerr << "Число должно быть больше 0" << std::endl;
        }
        return 1;
    }
    catch (const std::exception& e) {
        return 1;
    }
}