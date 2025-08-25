#!/bin/bash

clang++ -o multmatrix.exe multmatrix.cpp

echo "Тест 1: Умножение матрицы на единичную матрицу"
./multmatrix.exe test1.txt test2.txt
echo

echo "Тест 2: Ошибка чтения файла"
./multmatrix.exe nonexistent.txt test2.txt
echo

echo "Тест 3: Ошибка формата матрицы"
./multmatrix.exe test_empty.txt test2.txt
echo

echo "Тест 4: Ввод через stdin"
echo -e "1 2 3\n4 5 6\n7 8 9\n\n1 0 0\n0 1 0\n0 0 1" | ./multmatrix.exe
echo

echo "Тест 5: Ошибка ввода через stdin"
echo -e "1 2\n4 5 6\n7 8 9" | ./multmatrix.exe

rm multmatrix.exe
