#include <iostream>
#include <fstream>
#include <array>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>

const int MATRIX_SIZE = 3;

using Matrix = std::array<std::array<double, MATRIX_SIZE>, MATRIX_SIZE>;

bool readMatrix(std::istream& input, Matrix& matrix)
{
	std::string line;
	int row = 0;

	while (row < MATRIX_SIZE && std::getline(input, line))
	{
		if (line.empty())
		{
			continue;
		}

		std::istringstream strStream(line);
		std::vector <double> values;
		double value;

		while (strStream >> value)
		{
			values.push_back(value);
		}

		if (values.size() != MATRIX_SIZE)
		{
			return false;
		}

		for (int col = 0; col < MATRIX_SIZE; col++)
		{
			matrix[row][col] = values[col];
		}
		
		row++;
	}
    
	return row == MATRIX_SIZE;
}

Matrix multiply(Matrix& a, Matrix& b) 
{
	Matrix result = {0};

	for (int row = 0; row < MATRIX_SIZE;  row++)
	{
		for (int col = 0; col < MATRIX_SIZE;  col++)
		{
			for (int val = 0; val < MATRIX_SIZE; val++)
			{
				result[row][col] += a[row][val] * b[val][col];
			}
		}
	}

	return result;
}

void printMatrix(const Matrix& matrix)
{
	for (int row = 0; row < MATRIX_SIZE;  row++)
	{
		for (int col = 0; col < MATRIX_SIZE;  col++)
		{
			std::cout << std::fixed << std::setprecision(3) << matrix[row][col] << " ";
		}
		std::cout << std::endl;
	}
}

bool readMatrixFromFile(int argc, char* argv[], Matrix& matrix1, Matrix& matrix2)
{
    std::ifstream file1(argv[1]);
    std::ifstream file2(argv[2]);

    if (!file1.is_open() || !file2.is_open())
    {
        return 0;
    }
    
    return readMatrix(file1, matrix1) && readMatrix(file2, matrix2);
}

bool readMatricesFromStdin(Matrix& matrix1, Matrix& matrix2)
{
    if (!readMatrix(std::cin, matrix1))
    {
        return 0;
    }

    std::string emptyLine;
    if (std::cin.peek() == '\n')
    {
        std::cin.get();
    }

    return readMatrix(std::cin, matrix2);
}

int main(int argc, char* argv[])
{
	Matrix matrix1, matrix2;

	if (argc == 3)
	{
        if (!readMatrixFromFile(argc, argv, matrix1, matrix2))
        {
            std::cout << "ERROR" << std::endl;
            return 1;
        }
	}
	else if (argc == 1)
	{
        if (!readMatricesFromStdin(matrix1, matrix2))
        {
            std::cout << "ERROR" << std::endl;
            return 1;
        }
    }
	else
	{
		std::cout << "ERROR" << std::endl;
		return 1;
	}

	Matrix result = multiply(matrix1, matrix2);
	printMatrix(result);

	return 0;
}