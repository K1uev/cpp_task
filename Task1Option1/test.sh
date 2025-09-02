#!/bin/bash

clang++ -o copyfile.exe copyfile.cpp

echo "Тест 1: Проверка нормальной работы"
touch test-output.txt
./copyfile.exe test-input.txt test-output.txt
diff test-input.txt test-output.txt && echo "Тест пройден!"
rm test-output.txt
echo

echo "Тест 2: Копирование пустого файла"
touch test-output.txt
./copyfile.exe empty-file.txt test-output.txt
if [[ -s test-output.txt ]]; then
    echo "Тест провален!"
else
    diff empty-file.txt test-output.txt && echo "Тест пройден!"
fi
rm test-output.txt
echo

echo "Тест 3: Тестирование файла без прав доступа"
touch test-output.txt
echo "Unavailable value" > unavailable-file.txt
chmod 000 unavailable-file.txt
./copyfile.exe unavailable-file.txt test-output.txt
if [[ "$?" -ne 0 ]]; then
    echo "Тест пройден!"
else
    echo "Тест провален!"
fi
chmod 644 unavailable-file.txt
rm unavailable-file.txt
rm test-output.txt
echo

echo "Тест 4: Тестирование отсутствующего входного файла"
touch test-output.txt
./copyfile.exe nofile.txt test-output.txt
if [[ "$?" -ne 0 ]]; then
    echo "Тест пройден!"
else
    echo "Тест провален!"
fi
rm test-output.txt
echo

echo "Тест 5: Тестирование неправильного использования"
./copyfile.exe
if [[ "$?" -ne 0 ]]; then
    echo "Тест пройден!"
else
    echo "Тест провален!"
fi
echo

rm copyfile.exe