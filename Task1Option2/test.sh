#!/bin/bash

clang++ -o multiply_each_element.exe multiply_each_element.cpp

echo "Тест 1: Передача строки 2.0 4 -1.5"
./multiply_each_element.exe 2.0 4 -1.5
echo 

echo "Тест 2: Передача строки 10 7 4"
./multiply_each_element.exe 10 7 4
echo

echo "Тест 3: Передача строки -1.5 -2.0 -3.0"
./multiply_each_element.exe -1.5 -2.0 -3.0
echo

echo "Тест 4: Передача нечислового значения abc 4.5 7"
./multiply_each_element.exe abc 4.5 7
echo

echo "Тест 5: Передача пустой строки"
./multiply_each_element.exe
echo

rm multiply_each_element.exe
