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

void SearchAndReplaceSubStrWithOutputLine(string line, const string subStrForChange, const string subStrForSearch, ofstream &outputFile)
{
	for (size_t i = 0; i <= line.length();)
	{
		if (subStrForSearch[0] == line[i] && subStrForSearch == line.substr(i, subStrForSearch.length()))
		{	
			outputFile << subStrForChange;
			i += subStrForSearch.length();			
		}
		else 
		{
			outputFile << line[i];
			i++;
		} 
		
	}
	outputFile << "\n";
}

void ReadDataFromFileAndChangeSubstr(const string subStrForSearch, const string subStrForChange, ifstream &inputFile, ofstream &outputFile)
{
	string line;
	
	if ( inputFile.is_open() && outputFile.is_open())
	{
		while (getline(inputFile, line))
		{
			SearchAndReplaceSubStrWithOutputLine(line, subStrForChange, subStrForSearch, outputFile);
		}
	}
	else
	{
		cout << "Failed to open input file or output file for reading" << endl;
	}
	outputFile.flush();
	if (!outputFile.is_open()) 
	{
		cout << "outputFile closed" << endl;
	}
}

int main(int argc, char * argv[])
{	
	setlocale(LC_ALL, "");

	if ( argc < 5)
	{
		printf("Ошибка! Не хватает аргументов для работы программы. Параметры командной строки: replace.exe inputFile outputFile searchString replaceString \n");
		return 1;
	}

	else if ( argc > 5)
	{
		printf("Ошибка! Слишком много аргументов для работы программы. Параметры командной строки: replace.exe inputFile outputFile searchString replaceString \n");
		return 1;
	}

	const string subStrForSearch = argv[3];
	const string subStrForChange = argv[4];

	ifstream inputFile(argv[1]);
	ofstream outputFile(argv[2]);

	ReadDataFromFileAndChangeSubstr(subStrForSearch, subStrForChange, inputFile, outputFile);
	return 1;
}