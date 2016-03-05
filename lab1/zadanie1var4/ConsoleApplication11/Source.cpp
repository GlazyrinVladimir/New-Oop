#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void SearchAndReplaceSubStrWithOutputLine(string &line, const string &subStrForChange, const string &subStrForSearch, ofstream &outputFile)
{
	for (size_t i = 0; i < line.length();)
	{
		if ((line.length() - i) >= (subStrForSearch.length()) && equal(subStrForSearch.begin(), subStrForSearch.end(), line.substr(i, subStrForSearch.length()).begin()))
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
}

void ReadDataFromFileAndChangeSubstr(const string &subStrForSearch, const string &subStrForChange, ifstream &inputFile, ofstream &outputFile)
{
	string line;
	bool isFirstFileLine = true;
	
	if ( inputFile.is_open() && outputFile.is_open())
	{
		while (getline(inputFile, line))
		{
			if (isFirstFileLine)
			{
				isFirstFileLine = false;
				SearchAndReplaceSubStrWithOutputLine(line, subStrForChange, subStrForSearch, outputFile);
			}				
			else
			{
				outputFile << endl;
				SearchAndReplaceSubStrWithOutputLine(line, subStrForChange, subStrForSearch, outputFile);
			}
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
		printf("ERROR! Usage: replace.exe inputFile outputFile searchString replaceString \n");
		return 1;
	}

	else if ( argc > 5)
	{
		printf("ERROR! Usage: replace.exe inputFile outputFile searchString replaceString \n");
		return 1;
	}

	const string subStrForSearch = argv[3];
	const string subStrForChange = argv[4];

	ifstream inputFile(argv[1]);
	ofstream outputFile(argv[2]);

	ReadDataFromFileAndChangeSubstr(subStrForSearch, subStrForChange, inputFile, outputFile);
	return 0;
}