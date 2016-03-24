#include "stdafx.h"
#include "Dictionary.h"

using namespace std;

void SaveDictionaryInFile(multimap <string, string> const dictionary, ofstream &outputFile)
{
	for (auto it = dictionary.begin(); it != dictionary.end(); ++it)
	{
		outputFile << it->first << " " << it->second << endl;
	}
}

void GetWordToTranslate(string &wordToTranslate)
{
	string word;
	cout << "input word to translate:";
	cin >> word;
	getline(cin, wordToTranslate);
	wordToTranslate = word + wordToTranslate;
	transform(wordToTranslate.begin(), wordToTranslate.end(), wordToTranslate.begin(), tolower);
}

bool IsHaveEngTranslate(multimap <string, string> &dictionary, string &wordToTranslate)
{
	bool isTranslated = false;

	for (auto it = dictionary.begin(); it != dictionary.end(); ++it)
	{
		if (it->second == wordToTranslate)
		{
			isTranslated = true;
			cout << "translate:" << it->first << " " << endl;
		}
	}
	
	return isTranslated;
}

bool IsHaveRusTranslate(multimap <string, string> &dictionary, string &wordToTranslate)
{
	bool isTranslated = false;

	for (auto it = dictionary.begin(); it != dictionary.end(); ++it)
	{

		if (it->first == wordToTranslate)
		{
			isTranslated = true;
			cout << "translate:" << it->second << " " << endl;
		}
	}

	return isTranslated;
}

bool IsHaveTranslate(multimap <string, string> &dictionary,string &wordToTranslate)
{
	if (IsHaveRusTranslate(dictionary, wordToTranslate)) 
		return 1; 
	else 
		return IsHaveEngTranslate(dictionary, wordToTranslate);
}

void SavingNewWordTranslation(multimap <string, string> &dictionary, string wordToTranslate)
{
	string translatedWord;
	string word;
	cout << "dictionary does not have a given word" << endl << "enter the translation:";
	cin >> word;
	getline(cin, translatedWord);
	translatedWord = word + translatedWord;
	if (int(translatedWord[0]) < 0)
		dictionary.insert(pair<string, string>(wordToTranslate, translatedWord));
	else
		dictionary.insert(pair<string, string>(translatedWord, wordToTranslate));
}

string InputDictionaryFromFile(multimap <string, string> &dictionary)
{
	string inputFileName;
	cout << "input file name: ";
	cin >> inputFileName;

	ifstream inputFile(inputFileName);

	if (inputFile.is_open())
	{
		string word;
		string translatedWord;
		string line;
		while (getline(inputFile, line))
		{
			int kek = static_cast<unsigned int> (static_cast<unsigned char> ('а'));
			int kek2 = static_cast<unsigned int> (static_cast<unsigned char> ('я'));
			cout << "char: " << kek << " " << kek2 << endl;
			int translatePosition;
			transform(line.begin(), line.end(), line.begin(), tolower);
			for (translatePosition = 0; int(line[translatePosition]) >= 0; translatePosition++);
			word = line.substr(0, translatePosition-1);
			translatedWord = line.substr(translatePosition, line.length());

			dictionary.insert(pair<string, string>(word, translatedWord));
		}
	}
	else
	{
		cout << "input file is not opened" << endl;
		ofstream outputFile(inputFileName);
	}
	return inputFileName;
}