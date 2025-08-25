#!/bin/bash

clang++ -o copyfile.exe copyfile.cpp

echo "Тест 1: Проверка нормальной работы"
./copyfile.exe test-input.txt test-output.txt
diff test-input.txt test-output.txt && echo "Тест пройден!"
rm test-output.txt
echo

echo "Тест 2: Тестирование отсутствующего входного файла..."
./copyfile.exe nofile.txt test-output.txt
if [[ "$?" -ne 0 ]]; then
    echo "Тест пройден!"
else
    echo "Тест провален!"
fi
echo

echo "Тест 3: Тестирование неправильного использования..."
./copyfile.exe
if [[ "$?" -ne 0 ]]; then
    echo "Тест пройден!"
else
    echo "Тест провален!"
fi
echo

rm copyfile.exe