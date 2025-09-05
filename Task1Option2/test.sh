#!/bin/bash

clang++ -o multiply_each_element.exe multiply_each_element.cpp

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

echo "Тест 1: Передача строки 2.0 4 -1.5"
expectedValue="-6.000 -3.000 2.250"
result=$(./multiply_each_element.exe 2.0 4 -1.5)
checkResults "$expectedValue" "$result"
echo

echo "Тест 2: Передача строки 10 7 4"
expectedValue="16.000 28.000 40.000"
result=$(./multiply_each_element.exe 10 7 4)
checkResults "$expectedValue" "$result"
echo

echo "Тест 3: Передача строки -1.5 -2.0 -3.0"
expectedValue="4.500 6.000 9.000"
result=$(./multiply_each_element.exe -1.5 -2.0 -3.0)
checkResults "$expectedValue" "$result"
echo

echo "Тест 4: Передача нечислового значения abc 4.5 7"
expectedValue="ERROR"
result=$(./multiply_each_element.exe abc 4.5 7)
checkResults "$expectedValue" "$result"
echo

echo "Тест 5: Передача без аргументов"
expectedValue=""
result=$(./multiply_each_element.exe )
checkResults "$expectedValue" "$result"
echo

rm multiply_each_element.exe