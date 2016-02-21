#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <cassert>
#include <cstdint>
#include <winsock.h>
#include <cstring>
#include <stdio.h>
#include <conio.h>
#include <locale.h>

using namespace std;

void SearchDeterminant(double &determinant, double matrix[3][3])
{
	double firstPartOfDeterminant = matrix[0][0] * matrix[1][1] * matrix[2][2] + matrix[2][0] * matrix[0][1] * matrix[1][2] + matrix[1][0] * matrix[2][1] * matrix[0][2];
	double secondPartOfDeterminant = matrix[2][0] * matrix[1][1] * matrix[0][2] + matrix[0][0] * matrix[2][1] * matrix[1][2] + matrix[1][0] * matrix[0][1] * matrix[2][2];
	determinant = firstPartOfDeterminant - secondPartOfDeterminant;
}

void SearchMatrixOfCofactors(double matrix[3][3], double cofactorsMatrix[3][3])
{
	cofactorsMatrix[0][0] = matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1];
	cofactorsMatrix[0][1] = -1 * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]);
	cofactorsMatrix[0][2] = matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0];
	cofactorsMatrix[1][0] = -1 * (matrix[0][1] * matrix[2][2] - matrix[0][2] * matrix[2][1]);
	cofactorsMatrix[1][1] = matrix[0][0] * matrix[2][2] - matrix[0][2] * matrix[2][0];
	cofactorsMatrix[1][2] = -1 * (matrix[0][0] * matrix[2][1] - matrix[0][1] * matrix[2][0]);
	cofactorsMatrix[2][0] = matrix[0][1] * matrix[1][2] - matrix[0][2] * matrix[1][1];
	cofactorsMatrix[2][1] = -1 * (matrix[0][0] * matrix[1][2] - matrix[0][2] * matrix[1][0]);
	cofactorsMatrix[2][2] = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
}

void SearchTranspositionMatrix(double cofactorsMatrix[3][3])
{
	double storage;

	for (int i = 0; i < 3; ++i)
	{
		for (int j = i; j < 3; ++j)
		{
			storage = cofactorsMatrix[i][j];
			cofactorsMatrix[i][j] = cofactorsMatrix[j][i];
			cofactorsMatrix[j][i] = storage;
		}
	}
}

void WriteData(double cofactorsMatrix[3][3], double determinant, ofstream &outputFile)
{
	outputFile << "coefficient of the resulting matrix = " << "1/" << determinant << endl;
	outputFile << "inverse matrix:" << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			outputFile << cofactorsMatrix[i][j] << " ";
		}
		outputFile << endl;
	}
	outputFile.flush();
	if (!outputFile.is_open())
	{
		cout << "outputFile closed" << endl;
	}
}

void multipliedTranspositionMatrixOnDeterminant(double cofactorsMatrix[3][3], double determinant)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cofactorsMatrix[i][j] = cofactorsMatrix[i][j] * 1/determinant;
		}
	}
}

void SearchAndOutputInverseMatrix(double matrix[3][3], ofstream &outputFile)
{
	double determinant;
	double cofactorsMatrix[3][3];
	SearchDeterminant(determinant, matrix);
	if (determinant == 0)
	{
		cout << "Determinant = 0, inverse matrix not exist" << endl;
	}
	else
	{
		SearchMatrixOfCofactors(matrix, cofactorsMatrix);
		SearchTranspositionMatrix(cofactorsMatrix);
		multipliedTranspositionMatrixOnDeterminant(cofactorsMatrix, determinant);
		WriteData(cofactorsMatrix, determinant, outputFile);
	}
}

void ReadData(double matrix[3][3], ifstream &inputFile)
{
	if (inputFile.is_open())
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				inputFile >> matrix[i][j];
			}
		}
	}
	else
	{
		cout << "Failed to open input file for reading" << endl;
	}
}

int main(int argc, char * argv[])
{
	setlocale(LC_ALL, "");

	double matrix[3][3];

	if (argc < 3)
	{
		printf("Ошибка! Не хватает аргументов для работы программы. Параметры командной строки: inputFile outputFile\n");
		return 1;
	}

	else if (argc > 3)
	{
		printf("Ошибка! Слишком много аргументов для работы программы. Параметры командной строки: inputFile outputFile\n");
		return 1;
	}

	ifstream inputFile(argv[1]);
	ofstream outputFile(argv[2]);

	ReadData(matrix, inputFile);
	SearchAndOutputInverseMatrix(matrix, outputFile);

	return 1;
}