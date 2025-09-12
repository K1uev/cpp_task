#!/bin/bash

clang++ -o wordCount.exe wordCount.cpp

checkResults() {
	expectedValue="$1"
	result="$2"

	if [ "$(echo "$expectedValue" | xargs)" = "$(echo "$result" | xargs)" ]; then
		echo "Тест пройден"
	else
		echo "Ошибка"
		echo "Ожидаемое значение:"
		echo "$expectedValue"
		echo "Полученное значение:"
		echo "$result"
	fi
}

echo "Тест 1: Передача строки 'яблоко яблоко груша'"
expectedValue="груша->1
яблоко->2"
result=$(echo -e "яблоко яблоко груша" | ./wordCount.exe)
checkResults "$expectedValue" "$result"
echo

echo "Тест 2: Передача строки 'груша дыня Яблоко яблоко груша'"
expectedValue="Яблоко->1
груша->2
дыня->1
яблоко->1"
result=$(echo -e "груша дыня Яблоко яблоко груша" | ./wordCount.exe)
checkResults "$expectedValue" "$result"
echo

echo "Тест 3: Передача строки '3 1 2 3 2 3'"
expectedValue="1->1
2->2
3->3"
result=$(echo -e "3 1 2 3 2 3" | ./wordCount.exe)
checkResults "$expectedValue" "$result"
echo

echo "Тест 4: пустая строка"
expectedValue=""
result=$(echo -e "" | ./wordCount.exe)
checkResults "$expectedValue" "$result"
echo

echo "Тест 5: Пустые строки и пробелы"
expectedValue=""
result=$(echo -e "     \n\t  \n   " | ./wordCount.exe)
checkResults "$expectedValue" "$result"
echo

rm wordCount.exe