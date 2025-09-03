#!/bin/bash

clang++ -o trimBlanks.exe trimBlanks.cpp

echo "Тест 1: 'hello'"
./trimBlanks.exe "hello"
echo

echo "Тест 2: ' hello'"
./trimBlanks.exe " hello"
echo

echo "Тест 3: ' hello '"
./trimBlanks.exe " hello "
echo

echo "Тест 3: '   '"
./trimBlanks.exe "   "
echo

echo "Тест 4: без аргументов"
./trimBlanks.exe
echo

rm trimBlanks.exe
