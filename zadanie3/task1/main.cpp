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
	string wordToTranslate;
	string inputFileName = InputDictionaryFromFile(dictionary);
	ifstream inputFile(inputFileName);
	ofstream outputFile(inputFileName);
	
	while (wordToTranslate != "...")
	{	
		GetWordToTranslate(wordToTranslate);
		if (!IsHaveTranslate(dictionary, wordToTranslate) && wordToTranslate != "...")
		{
			SavingNewWordTranslation(dictionary, wordToTranslate);
		}
	}
	SaveDictionaryInFile(dictionary, outputFile);

	return 0;
}

