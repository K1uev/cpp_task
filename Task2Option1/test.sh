#!/bin/bash

clang++ -o calcbits.exe calcbits.cpp

echo "Тест 1: Проверка нормальной работы"
./calcbits.exe 255
if [[ "$?" -eq 0 ]]; then
    echo "Тест пройден!"
else
    echo "Тест провален!"
fi
echo

echo "Тест 2: Проверка на вывод краткой справки"
./calcbits.exe -h
if [[ "$?" -eq 0 ]]; then
    echo "Тест пройден!"
else
    echo "Тест провален!"
fi
echo

echo "Тест 3: Проверка на ввод значений (Ожидаемый ответ: 2)"
echo "5" | ./calcbits.exe
if [[ "$?" -eq 0 ]]; then
    echo "Тест пройден!"
else
    echo "Тест провален!"
fi
echo

echo "Тест 4: Проверка на значение меньше 0"
./calcbits.exe -1
if [[ "$?" -ne 0 ]]; then
    echo "Тест пройден!"
else
    echo "Тест провален!"
fi
echo

echo "Тест 5: Проверка на неправильное использование"
./calcbits.exe 1 2
if [[ "$?" -ne 0 ]]; then
    echo "Тест пройден!"
else
    echo "Тест провален!"
fi
echo

echo "Тест 6: Проверка на передачу строки в качестве параметра"
./calcbits.exe error
if [[ "$?" -ne 0 ]]; then
    echo "Тест пройден!"
else
    echo "Тест провален!"
fi
echo

rm calcbits.exe
