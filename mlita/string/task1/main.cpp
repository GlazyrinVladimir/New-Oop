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

	CSuprefiksCheck suprefiks;
	suprefiks.GetWordsAndSuprefiks("tests2.txt");
	suprefiks.CountWordsContainsSuprefiksWords();
	suprefiks.WriteNumberOfSuprefiks();

	
	return 0;
}

