// task1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include "Dictionary.h"
#include <ctime>

using namespace std;

int _tmain()
{
	srand(time(0));
	setlocale(LC_ALL, "RUS");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	CSuprefiksCheck suprefiks;
	suprefiks.GetWordsAndSuprefiks("input.txt");
	suprefiks.CountWordsContainsSuprefiksWords();
	suprefiks.WriteNumberOfSuprefiks();
	cout << "runtime = " << clock() / 1000.0 << endl; // גנולÿ נאבמעû ןנמדנאללû 
	return 0;
}

