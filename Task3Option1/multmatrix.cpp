#include <array>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

class InvalidMatrixDataException : public std::invalid_argument
{
public:
	InvalidMatrixDataException()
		: std::invalid_argument("Invalid matrix data")
	{
	}
};

class FileOpenException : public std::runtime_error
{
public:
	FileOpenException()
		: std::runtime_error("Failed to open file")
	{
	}
};

class InvalidArgumentsException : public std::runtime_error
{
public:
	InvalidArgumentsException()
		: std::runtime_error("Invalid number of arguments")
	{
	}
};

const int matrixSize = 3;

using Matrix = std::array<std::array<double, matrixSize>, matrixSize>;

void ReadMatrix(std::istream& input, Matrix& matrix)
{
	std::string line;
	int row = 0;

	while (row < matrixSize && std::getline(input, line))
	{
		if (line.empty())
		{
			continue;
		}

		std::istringstream strStream(line);
		int col = 0;
		double value;

		while (col < matrixSize && strStream >> value)
		{
			matrix[row][col] = value;
			col++;
		}

		if (col != matrixSize)
		{
			throw InvalidMatrixDataException();
		}

		row++;
	}

	if (row != matrixSize)
	{
		throw InvalidMatrixDataException();
	}
}

Matrix Multiply(const Matrix& first, const Matrix& second)
{
	Matrix result = { 0 };

	for (int row = 0; row < matrixSize; row++)
	{
		for (int col = 0; col < matrixSize; col++)
		{
			for (int val = 0; val < matrixSize; val++)
			{
				result[row][col] += first[row][val] * second[val][col];
			}
		}
	}

	return result;
}

void PrintMatrix(const Matrix& matrix)
{
	for (int row = 0; row < matrixSize; row++)
	{
		for (int col = 0; col < matrixSize; col++)
		{
			std::cout << std::fixed << std::setprecision(3) << matrix[row][col] << " ";
		}
		std::cout << std::endl;
	}
}

void ReadMatrixFromFile(const std::string& fileName1, const std::string& fileName2, Matrix& matrix1, Matrix& matrix2)
{
	std::ifstream file1(fileName1);
	if (!file1.is_open())
	{
		throw FileOpenException();
	}

	std::ifstream file2(fileName2);
	if (!file2.is_open())
	{
		throw FileOpenException();
	}

	ReadMatrix(file1, matrix1);
	ReadMatrix(file2, matrix2);
}

void ReadMatricesFromStdin(Matrix& matrix1, Matrix& matrix2)
{
	ReadMatrix(std::cin, matrix1);

	if (std::cin.peek() == '\n')
	{
		std::cin.ignore();
	}

	ReadMatrix(std::cin, matrix2);
}

int main(int argc, char* argv[])
{
	try
	{
		Matrix matrix1, matrix2;

		if (argc == 3)
		{
			ReadMatrixFromFile(argv[1], argv[2], matrix1, matrix2);
		}
		else if (argc == 1)
		{
			ReadMatricesFromStdin(matrix1, matrix2);
		}
		else
		{
			throw InvalidArgumentsException();
		}

		Matrix result = Multiply(matrix1, matrix2);
		PrintMatrix(result);

		return 0;
	}
	catch (const InvalidMatrixDataException& e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}
	catch (const FileOpenException& e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}
	catch (const InvalidArgumentsException& e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}
}