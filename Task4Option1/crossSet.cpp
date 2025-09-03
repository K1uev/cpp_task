#include <iostream>
#include <set>
#include <algorithm>
#include <string>
#include <sstream>
#include <iterator>

bool isValidInput(const std::string& input) {
	if (input.empty()) {
	return false;
	}
	
	for (char inputChar : input) {
		if (!std::isdigit(inputChar)) {
		return false;
		}
	}

	return true;
}

int sumEachNum(int num) {
	int sum = 0;
	
	while (num > 0) {
		sum += num % 10;
		num /= 10;
	}

	return sum;
}

std::set<int> createSetEachNumDevideSumNum(int lastNum) {
	std::set<int> setDevideSumNum;
	for (int i = 1; i <= lastNum; ++i) {
		int sum = sumEachNum(i);
		if (sum != 0 && i % sum == 0) {
			setDevideSumNum.insert(i);
		}
	}

	return setDevideSumNum;
}

std::set<int> createSetSumEven(int lastNum) {
	std::set<int> setSumEven;
	for (int i = 1; i <= lastNum; ++i) {
		if (sumEachNum(i) % 2 == 0) {
			setSumEven.insert(i);
		}
	}
	
	return setSumEven;
}

bool checkEmptySet(const std::set<int>& printedSet) {
	if(printedSet.empty()) {
		return false;
	}

	return true;
}

void printSet(const std::set<int>& printedSet) {
	if(checkEmptySet(printedSet)) {
		for (auto i = printedSet.begin(); i != printedSet.end(); ++i) {
			std::cout << *i << " ";
		}
		std::cout << std::endl;
	}
}

std::set<int> findSetCross(std::set<int> const& set1, std::set<int> const& set2) {
	std::set<int> setCross;
	std::set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), std::inserter(setCross, setCross.begin()));

	return setCross;
}

int main(int argc, char* argv[]) {
	if (argc == 2 && std::string(argv[1]) == "-h") {
		std::cout << "Программа возвращает два множества:\nПервое множество – множество чисел от 1 до N, делящихся без остатка на сумму своих цифр;\nВторое множество – множество целых чисел то 1 до N, сумма цифр которых является четной.\nНеобходимо передать положительное число или \"-h\" для получения справки" << std::endl;

		return 0;
	}

	std::string input;
	int lastNum;
	
	if (argc == 2) {
		input = argv[1];
		if (!isValidInput(input)) {
			std::cerr << "ERROR" << std::endl;
			return 1;
		}
		lastNum = std::stoi(input);
	}
	else if (argc == 1) {
		std::getline(std::cin, input);
		if (!isValidInput(input)) {
			std::cerr << "ERROR" << std::endl;
			return 1;
		}
		lastNum = std::stoi(input);
	}
	else {
		std::cerr << "ERROR" << std::endl;
		return 1;
	}
	
	std::set<int> setEachNumDevideSumNum = createSetEachNumDevideSumNum(lastNum);
	std::set<int> setSumEven = createSetSumEven(lastNum);
	std::set<int> intersection = findSetCross(setEachNumDevideSumNum, setSumEven);
	
	printSet(setEachNumDevideSumNum);
	printSet(setSumEven);
	printSet(intersection);
	
	return 0;
}