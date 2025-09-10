#!/bin/bash

clang++ -o multmatrix.exe multmatrix.cpp

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

echo "Тест 1: Умножение матрицы на единичную матрицу"
expectedValue="1.000 2.000 3.000
4.000 5.000 6.000
7.000 8.000 9.000"
result=$(./multmatrix.exe test1.txt test2.txt)
checkResults "$expectedValue" "$result"
echo

echo "Тест 2: Умножение нулевой матрицы"
expectedValue="0.000 0.000 0.000 
0.000 0.000 0.000 
0.000 0.000 0.000"
result=$(./multmatrix.exe test_zero.txt test1.txt)
checkResults "$expectedValue" "$result"
echo

echo "Тест 3: Умножение нулевой на нулевую"
expectedValue="0.000 0.000 0.000 
0.000 0.000 0.000 
0.000 0.000 0.000"
result=$(./multmatrix.exe test_zero.txt test_zero.txt)
checkResults "$expectedValue" "$result"
echo

echo "Тест 4: Ошибка чтения файла"
expectedValue="Failed to open file"
result=$(./multmatrix.exe no_file.txt test_zero.txt)
checkResults "$expectedValue" "$result"
echo

echo "Тест 5: Ошибка формата матрицы"
expectedValue="Invalid matrix data"
result=$(./multmatrix.exe test_error_matrix.txt test1.txt 2>&1)
checkResults "$expectedValue" "$result"
echo

echo "Тест 6: Ввод через stdin"
expectedValue="1.000 2.000 3.000 
4.000 5.000 6.000 
7.000 8.000 9.000"
result=$(echo -e "1 2 3\n4 5 6\n7 8 9\n\n1 0 0\n0 1 0\n0 0 1" | ./multmatrix.exe)
checkResults "$expectedValue" "$result"
echo

echo "Тест 7: Ошибка ввода через stdin"
expectedValue="Invalid matrix data"
result=$(echo -e "1 2\n4 5 6\n7 8 9" | ./multmatrix.exe 2>&1)
checkResults "$expectedValue" "$result"
echo

echo "Тест 8: Неверное количество аргументов"
expectedValue="Invalid number of arguments"
result=$(./multmatrix.exe test1.txt)
checkResults "$expectedValue" "$result"
echo

rm multmatrix.exe