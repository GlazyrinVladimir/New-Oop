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
	
	multimap <string, string> dictionary;
	string saveWord;
	string wordToTranslate;
	string inputFileName;
	cout << "input file name: ";
	getline(cin, inputFileName);

	InputDictionaryFromFile(dictionary, inputFileName);
	
	while (wordToTranslate != "...")
	{	
		wordToTranslate = GetWordToTranslate();
		if (!IsHaveTranslate(dictionary, wordToTranslate) && wordToTranslate != "...")
		{
			SavingNewWordTranslation(dictionary, wordToTranslate);
		}
	}
	
	while (saveWord != "y" && saveWord != "n")
	{
		cout << "do you want to save dictionary? y/n:";
		getline(cin, saveWord);
		if (saveWord == "y")
			SaveDictionaryInFile(dictionary, inputFileName);
	}
	return 0;
}

