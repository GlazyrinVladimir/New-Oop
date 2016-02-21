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
#include <vector>

using namespace std;

void WriteLabirinth(ofstream &outputFile, int matrixOfLabirinth[100][100], int maxWidth, int length, vector <int> coordination)
{
	
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < maxWidth; j++)
		{
			if (matrixOfLabirinth[i][j] == -1)
				outputFile << "#";
			else
				if (matrixOfLabirinth[i][j] == 1)		
					outputFile << "A";
				else 
					if (i == coordination[2] && j == coordination[3])
						outputFile << "B";
					else
						if (matrixOfLabirinth[i][j] == -2 )
							outputFile << "-";
						else 
							outputFile << " ";
		
		}
		outputFile << "\n";
	}
	outputFile.flush();
	if (!outputFile.is_open())
	{
		cout << "outputFile closed" << endl;
	}
}

void ReadLabirinth(ifstream &inputFile, int matrixOfLabirinth[100][100], int &maxWidth, int &length, vector <int> &coordination)
{
	string lineOfMatrix;
	int width;
	while (getline(inputFile, lineOfMatrix))
	{
		for (width = 0; width < lineOfMatrix.length(); width++)
		{
			if (lineOfMatrix[width] == 'A')
			{
				coordination[0] = length; coordination[1] = width;
			}
			else 
				if (lineOfMatrix[width] == 'B')
				{
					matrixOfLabirinth[length][width] = 0;
					coordination[2] = length; coordination[3] = width;
				}
				else
					if (lineOfMatrix[width] == '#')
						matrixOfLabirinth[length][width] = -1;
					else 
						matrixOfLabirinth[length][width] = 0;
		}
		if (width > maxWidth) { maxWidth = width; }
		length++;
	}
}

void SearchExitFromLabirinth(int matrix[100][100], int maxWidth, int length, vector <int> coordination)
{
	matrix[coordination[0]][coordination[1]] = 1;
	int number = 0;
	bool doOneMoreIteration = true;
	while (doOneMoreIteration)
	{
		doOneMoreIteration = false;
		number += 1;
		for (int i = 0; i < length; i++)
		{
			for (int j = 0; j < maxWidth - 1; j++)
			{
				if (matrix[i][j] > 0)
				{
					if ((matrix[i + 1][j] == 0 || matrix[i + 1][j] > matrix[i][j] + 1))
					{
						matrix[i + 1][j] = matrix[i][j] + 1;
						doOneMoreIteration = true;
					}
					if ((matrix[i - 1][j] == 0 || matrix[i - 1][j] > matrix[i][j] + 1))
					{
						matrix[i - 1][j] = matrix[i][j] + 1;
						doOneMoreIteration = true;
					}
					if ((matrix[i][j + 1] == 0 || matrix[i][j + 1] > matrix[i][j] + 1))
					{
						matrix[i][j + 1] = matrix[i][j] + 1;
						doOneMoreIteration = true;
					}
					if ((matrix[i][j - 1] == 0 || matrix[i][j - 1] > matrix[i][j] + 1))
					{
						matrix[i][j - 1] = matrix[i][j] + 1;
						doOneMoreIteration = true;
					}
				}
			}
		}
	}
}

void RenderingOutputPath(int matrix[100][100], vector <int> coordination)
{
	int pathX, pathY;
	pathX = coordination[2]; pathY = coordination[3];
	if (matrix[pathX][pathY] > 0)
	while (pathX != coordination[0] || pathY != coordination[1])
	{	
		if (matrix[pathX + 1][pathY] == (matrix[pathX][pathY] - 1))
		{
			matrix[pathX][pathY] = -2;
			pathX += 1; 
		}
		if (matrix[pathX - 1][pathY] == (matrix[pathX][pathY] - 1))
		{
			matrix[pathX][pathY] = -2;
			pathX -= 1;
		}
		if (matrix[pathX][pathY + 1] == (matrix[pathX][pathY] - 1))
		{
			matrix[pathX][pathY] = -2;
			pathY += 1;
		}
		if (matrix[pathX][pathY - 1] == (matrix[pathX][pathY] - 1))
		{
			matrix[pathX][pathY] = -2;
			pathY -= 1;
		}
	}
}

void StartProgram(ifstream &inputFile, ofstream &outputFile)
{
	int matrixOfLabirinth[100][100];
	int maxWidth = 0;
	int length = 0;
	vector <int> coordination(4);
	if (inputFile.is_open() && outputFile.is_open())
	{
		ReadLabirinth(inputFile, matrixOfLabirinth, maxWidth, length, coordination);
		SearchExitFromLabirinth(matrixOfLabirinth, maxWidth, length, coordination);
		RenderingOutputPath(matrixOfLabirinth, coordination);
		WriteLabirinth(outputFile, matrixOfLabirinth, maxWidth, length, coordination);
	}
	else
	{
		cout << "Failed to open input file or output file for reading" << endl;
	}
}

int main(int argc, char * argv[])
{	
	setlocale(LC_ALL, "");

	if ( argc < 3)
	{
		printf("Ошибка! Не хватает аргументов для работы программы. Параметры командной строки: labirinth.exe inputFile outputFile \n");
		return 1;
	}

	else if ( argc > 3)
	{
		printf("Ошибка! Слишком много аргументов для работы программы. Параметры командной строки: labirinth.exe inputFile outputFile \n");
		return 1;
	}

	ifstream inputFile(argv[1]);
	ofstream outputFile(argv[2]);
	
	StartProgram(inputFile, outputFile);
	return 1;
}