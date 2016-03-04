#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <cassert>
#include <cstdint>
#include <winsock.h>
#include <stdio.h>

using namespace std;

void TransferToAnotherNumberSystem(int number, int methodOfByte[8])
{
	int countOfByte = 7;
	while (number != 1)
	{
		methodOfByte[countOfByte] = number % 2;
		countOfByte--;
		number = number / 2;
	}
	methodOfByte[countOfByte] = number;
}

void CountTheNumber(int methodOfByte[8], int &outputNumber)
{
	const int scaleOfNotation = 2;
	for (int i = 0; i < 8; i++)
	{
		if (methodOfByte[i] == 1)
		{
			outputNumber += int(pow(scaleOfNotation, i));
		}
	}
}

void WriteData(int outputNumber, ofstream &outputFile, bool errorInputNumber)
{
	if (outputFile.is_open())
	{
		if (errorInputNumber)
		{
			outputFile << "error in input" << endl;
		}
		else
		{
			outputFile << outputNumber << endl;
		}
		
		if (!outputFile)
		{
			cout << "An error occurred when writing outputFile" << endl;
		}
	}
	else
	{
		cout << "Failed to open output.txt for writing" << endl;
	}
	outputFile.flush();
	if (!outputFile.is_open())
	{
		cout << "outputFile closed" << endl;
	}
}

void OutputAndTransformToNewnumber(int inputNumber, ofstream &outputFile)
{
	int methodOfByte[8] = { 0,0,0,0,0,0,0,0 };
	int outputNumber = 0;
	bool errorInputNumber = false;

	if (inputNumber > 0 && inputNumber <= 255)
	{
		TransferToAnotherNumberSystem(inputNumber, methodOfByte);
		CountTheNumber(methodOfByte, outputNumber);
		WriteData(outputNumber, outputFile, errorInputNumber);
	}
	else
	{
		if (inputNumber != 0)
		{
			errorInputNumber = true;
		}
		WriteData(outputNumber, outputFile, errorInputNumber);
	}
}

int main(int argc, char * argv[])
{
	int inputNumber;

	setlocale(LC_ALL, "");

	if (argc <= 2)
	{
		printf("ERROR! Usage: flipbyte.exe outputFile <inputByte> \n");
		return 1;
	}
	else if (argc > 3)
	{
		printf("ERROR! Usage: flipbyte.exe outputFile <inputByte> \n");
		return 1;
	}

	ofstream outputFile(argv[1]);
	inputNumber = atoi(argv[2]);

	OutputAndTransformToNewnumber(inputNumber, outputFile);
	return 0;
}