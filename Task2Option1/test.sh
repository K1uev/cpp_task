#!/bin/bash

clang++ -o trimBlanks.exe trimBlanks.cpp

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

echo "Тест 1: Передача строки 'hello'"
expectedValue="hello"
result=$(./trimBlanks.exe "hello")
checkResults "$expectedValue" "$result"
echo

echo "Тест 2: Передача строки ' hello'"
expectedValue="hello"
result=$(./trimBlanks.exe " hello")
checkResults "$expectedValue" "$result"
echo

echo "Тест 3: Передача строки ' hello '"
expectedValue="hello"
result=$(./trimBlanks.exe " hello ")
checkResults "$expectedValue" "$result"
echo

echo "Тест 4: Передача строки '   '"
expectedValue=""
result=$(./trimBlanks.exe "   ")
checkResults "$expectedValue" "$result"
echo

echo "Тест 5: без аргументов"
expectedValue="ERROR"
result=$(./trimBlanks.exe)
checkResults "$expectedValue" "$result"
echo

rm trimBlanks.exe