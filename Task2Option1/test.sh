#!/bin/bash

clang++ -o calcbits.exe calcbits.cpp

echo "Тест 1: Проверка нормальной работы (Передано: 255; Ожидается: 8)"
result=$(./calcbits.exe 255)
if [[ "$?" -eq 0 && "$result" -eq 8 ]]; then
	echo "Тест пройден! Получено: $result"
else
	echo "Тест провален! Ожидалось: 8, Получено: $result"
fi
echo

echo "Тест 2: Проверка на вывод краткой справки"
result=$(./calcbits.exe -h)
if [[ "$?" -eq 0 ]]; then
	echo "Тест пройден! Получено: $result"
else
	echo "Тест провален!"
fi
echo

echo "Тест 3: Проверка на ввод значений (Передано: 5; Ожидается: 2)"
result=$(echo "5" | ./calcbits.exe)
if [[ "$?" -eq 0 && "$result" -eq 2 ]]; then
	echo "Тест пройден! Получено: $result"
else
	echo "Тест провален! Ожидалось: 2, Получено: $result"
fi
echo

echo "Тест 4: Проверка на значение меньше 0 (Передано: -1)"
result=$(./calcbits.exe -1)
if [[ "$?" -ne 0 ]]; then
	echo "Тест пройден!"
else
	echo "Тест провален!"
fi
echo

echo "Тест 5: Проверка на неправильное использование (Передано: 1 и 2)"
result=$(./calcbits.exe 1 2)
if [[ "$?" -ne 0 ]]; then
	echo "Тест пройден!"
else
	echo "Тест провален!"
fi
echo

echo "Тест 6: Проверка на передачу строки в качестве параметра (Передано: test)"
result=$(./calcbits.exe test)
if [[ "$?" -ne 0 ]]; then
	echo "Тест пройден!"
else
	echo "Тест провален!"
fi
echo

echo "Тест 7: Проверка четного количества единиц (Передано: 10; Ожидается: 2)"
result=$(./calcbits.exe 10)
if [[ "$?" -eq 0 && "$result" -eq 2 ]]; then
	echo "Тест пройден! Получено: $result"
else
	echo "Тест провален! Ожидалось: 2, Получено: $result"
fi
echo

echo "Тест 8: Проверка нечетного количества единиц (Передано: 7; Ожидается: 3)"
result=$(./calcbits.exe 7)
if [[ "$?" -eq 0 && "$result" -eq 3 ]]; then
	echo "Тест пройден! Получено: $result"
else
	echo "Тест провален! Ожидалось: 3, Получено: $result"
fi
echo

echo "Тест 9: Проверка последовательных единиц (Передано: 8; Ожидается: 1)"
result=$(./calcbits.exe 8)
if [[ "$?" -eq 0 && "$result" -eq 1 ]]; then
	echo "Тест пройден! Получено: $result"
else
	echo "Тест провален! Ожидалось: 1, Получено: $result"
fi
echo

echo "Тест 10: Проверка на 0 (Передано: 0; Ожидается: 0)"
result=$(./calcbits.exe 0)
if [[ "$?" -eq 0 && "$result" -eq 0 ]]; then
	echo "Тест пройден! Получено: $result"
else
	echo "Тест провален! Ожидалось: 0, Получено: $result"
fi
echo

echo "Тест 11: Проверка на большое число (Передано: INT_MAX 2147483647)"
result=$(./calcbits.exe 2147483647)
if [[ "$?" -eq 0 ]]; then
	echo "Тест пройден! Получено: $result"
else
	echo "Тест провален!"
fi
echo

echo "Тест 12: Проверка граничного значения (Передано: 256; Ожидается: 0)"
result=$(./calcbits.exe 256)
if [[ "$?" -eq 0 && "$result" -eq 0 ]]; then
	echo "Тест пройден! Получено: $result"
else
	echo "Тест провален! Ожидалось: 0, Получено: $result"
fi
echo

rm calcbits.exe