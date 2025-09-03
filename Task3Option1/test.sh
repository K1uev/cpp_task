#!/bin/bash

clang++ -o wordCount.exe wordCount.cpp

echo "Тест 1: 'яблоко яблоко груша'"
echo -e "яблоко яблоко груша" | ./wordCount.exe
echo

echo "Тест 2: 'груша дыня Яблоко яблоко груша'"
echo -e "груша дыня Яблоко яблоко груша" | ./wordCount.exe
echo

echo "Тест 3: '3 1 2 3 2 3'"
echo -e "3 1 2 3 2 3" | ./wordCount.exe
echo

echo "Тест 4: пустая строка"
echo -e "" | ./wordCount.exe
echo

rm wordCount.exe
