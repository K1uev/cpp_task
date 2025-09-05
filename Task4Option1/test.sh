#!/bin/bash

clang++ -o crossSet.exe crossSet.cpp

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

echo "Тест 1: Переданное значение (режим stdin): 10"
expectedValue="1 2 3 4 5 6 7 8 9 10 
2 4 6 8 
2 4 6 8"
result=$(echo -e "10" | ./crossSet.exe)
checkResults "$expectedValue" "$result"
echo

echo "Тест 2: Переданное значение (режим stdin): 5"
expectedValue="1 2 3 4 5 
2 4 
2 4"
result=$(echo -e "5" | ./crossSet.exe)
checkResults "$expectedValue" "$result"
echo

echo "Тест 3: Переданное значение (режим stdin): 20"
expectedValue="1 2 3 4 5 6 7 8 9 10 12 18 20 
2 4 6 8 11 13 15 17 19 20 
2 4 6 8 20"
result=$(echo -e "20" | ./crossSet.exe)
checkResults "$expectedValue" "$result"
echo

echo "Тест 4: Переданное значение (режим stdin): 1"
expectedValue="1"
result=$(echo -e "1" | ./crossSet.exe)
checkResults "$expectedValue" "$result"
echo

echo "Тест 5: Переданное значение (режим stdin): 50"
expectedValue="1 2 3 4 5 6 7 8 9 10 12 18 20 21 24 27 30 36 40 42 45 48 50 
2 4 6 8 11 13 15 17 19 20 22 24 26 28 31 33 35 37 39 40 42 44 46 48 
2 4 6 8 20 24 40 42 48"
result=$(echo -e "50" | ./crossSet.exe)
checkResults "$expectedValue" "$result"
echo

echo "Тест 6: Переданное значение (режим командной строки): 15"
expectedValue="1 2 3 4 5 6 7 8 9 10 12 
2 4 6 8 11 13 15 
2 4 6 8"
result=$(./crossSet.exe 15)
checkResults "$expectedValue" "$result"
echo

echo "Тест 7: Переданное значение: -h"
expectedValue="Программа возвращает два множества:
Первое множество – множество чисел от 1 до N, делящихся без остатка на сумму своих цифр;
Второе множество – множество целых чисел то 1 до N, сумма цифр которых является четной.
Необходимо передать положительное число или \"-h\" для получения справки"
result=$(./crossSet.exe -h)
checkResults "$expectedValue" "$result"
echo

echo "Тест 8: Переданное значение (режим stdin): пустая строка"
expectedValue="ERROR"
result=$(echo -e "" | ./crossSet.exe)
checkResults "$expectedValue" "$result"
echo

echo "Тест 9: Переданное значение (режим stdin): test"
expectedValue="ERROR"
result=$(echo -e "test" | ./crossSet.exe)
checkResults "$expectedValue" "$result"
echo

echo "Тест 10: Переданное значение (режим командной строки): test"
expectedValue="ERROR"
result=$(./crossSet.exe test)
checkResults "$expectedValue" "$result"
echo

echo "Тест 11: Переданное значение (режим командной строки): -1"
expectedValue="ERROR"
result=$(./crossSet.exe -1)
checkResults "$expectedValue" "$result"
echo

echo "Тест 12: Переданное значение (режим командной строки): 0"
expectedValue=""
result=$(./crossSet.exe 0)
checkResults "$expectedValue" "$result"
echo

echo "Тест 13: Переданное значение (режим командной строки): 1 2"
expectedValue="ERROR"
result=$(./crossSet.exe 1 2)
checkResults "$expectedValue" "$result"
echo

rm crossSet.exe