// task1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include "Dictionary.h"
#define SIZE 8
using namespace std;

int _tmain()
{
	setlocale(LC_ALL, "RUS");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	ifstream inputFile("input2.txt");

	int cities;
	int ways;

	inputFile >> cities;
	inputFile >> ways;
	int d[50];
	int v[50];
	int temp;
	int minindex, min;
	vector<vector<int> > a(cities, vector<int>(ways));
	
	for (size_t i = 0; i < ways; i++)
	{
		int fromPoint;
		int inPoint;
		int way;
		inputFile >> fromPoint;
		inputFile >> inPoint;
		inputFile >> way;
		a[fromPoint-1][inPoint-1] = way;
	}

	for (size_t i = 0; i < cities; i++)
	{
		for (size_t j = 0; j < cities; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
	cout << endl;

	for (int i = 0;i<cities;i++)
	 {
		d[i] = 10000;
		v[i] = 1;
	}
	d[0] = 0;

	do {
		minindex = 10000;
		min = 10000;
		for (int i = 0; i<SIZE;i++) {
			if ((v[i] == 1) && (d[i]<min)) {
				min = d[i];
				minindex = i;
			}
		}
		if (minindex != 10000) {
			for (int i = 0;i<SIZE;i++) {
				if (a[minindex][i] > 0) {
					temp = min + a[minindex][i];
					if (temp < d[i])
						d[i] = temp;
				}
			}
			v[minindex] = 0;
		}
	} while (minindex < 10000);


	/*do {
		cout << "итерация" << endl;
		minindex = 10000;
		min = 10000;
		for (int i = 0; i<cities;i++)
		{
			if ((v[i] == 1) && (d[i]<min)) {
				min = d[i];
				minindex = i;
			}
			cout << min << " " << minindex << endl;
		}
		if (minindex != 10000) {
			for (int i = 0;i<cities;i++) {
				if (a[minindex][i] > 0) {
					temp = a[minindex][i];
					if (d[i] == 10000)
					{			
						d[i] = temp;
					}
					else
						if (temp > d[i])
							d[i] = temp;
				}
			}
			v[minindex] = 0;
		}
	} while (minindex < 10000);*/

	for (size_t i = 1; i < cities; i++)
		cout << d[i] << " ";
	
	vector<int> maxWayToCity(cities, 0);

	return 0;
}

