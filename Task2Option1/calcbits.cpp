#include <iostream>
#include <string>
#include <cstring>
#include <bitset>
#include <stdexcept>

int main(int argc, char* argv[])
{
    if (argc > 2) {
        std::cerr << "Нельзя передать больше 1 параметра" << std::endl;
        return 1;
    }

    if (argc == 2 && strcmp(argv[1], "-h") == 0) {
        std::cout << "Приложение выполняет подсчет и вывод количества единичных битов в байте\nПередача происходит следующим образом:\ncalcbits.exe <byte>" << std::endl;
        return 0;
    }

    if (argc == 1) {
		int cinValue; 
		std::cin >> cinValue;

		if (cinValue < 0) {
			std::cerr << "Число должно быть большое 0" << std::endl;
			return 1;
		}

		std::string binaryCinValue = std::bitset<8>(cinValue).to_string();
		
		int binarySum = 0;
		for (int i = 0; i < binaryCinValue.length(); i++)
		{
			if (binaryCinValue[i] == '1')
			{
				binarySum++;
			}
		}
		std::cout << binarySum << std::endl;

		return 0;
    }

    if (argc == 2) {
        try {
            int paramValue = std::stoi(argv[1]);

				if (paramValue < 0) {
					std::cerr << "Число должно быть большое 0" << std::endl;
					return 1;
				}
            
            std::string binaryCinValue = std::bitset<8>(paramValue).to_string();
				int binarySum = 0;
				for (int i = 0; i < binaryCinValue.length(); i++)
				{
					if (binaryCinValue[i] == '1')
					{
						binarySum++;
					}
				}
				std::cout << binarySum << std::endl;
            return 0;
        }
        catch (const std::exception& e) {
            std::cerr << "Аргумент должен быть числом" << std::endl;
            return 1;
        }
    }


    return 0;
}