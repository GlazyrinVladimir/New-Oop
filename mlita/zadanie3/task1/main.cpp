// task1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include "Dictionary.h"

using namespace std;

int _tmain()
{
	setlocale(LC_ALL, "RUS");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	ifstream inputFile("input.txt");

	int cities;
	int ways;

	inputFile >> cities;
	inputFile >> ways;

	std::vector<std::vector<int> > wayMatrix(cities, vector<int>(ways));
	
	for (size_t i = 0; i < ways; i++)
	{
		int fromPoint;
		int inPoint;
		int way;
		inputFile >> fromPoint;
		inputFile >> inPoint;
		inputFile >> way;
		wayMatrix[fromPoint-1][inPoint-1] = way;
	}

	for (size_t i = 0; i < cities; i++)
	{
		for (size_t j = 0; j < cities; j++)
			cout << wayMatrix[i][j] << " ";
		cout << endl;
	}
			

	return 0;
}

