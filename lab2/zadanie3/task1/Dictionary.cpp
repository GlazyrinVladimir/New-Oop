#include "stdafx.h"
#include "Dictionary.h"

using namespace std;

void SaveDictionaryInFile(multimap <string, string> const dictionary, string inputFileName)
{
	ofstream outputFile(inputFileName);
	for (auto it = dictionary.begin(); it != dictionary.end(); ++it)
	{
		outputFile << it->first << " " << it->second << endl;
	}
}

string GetWordToTranslate()
{
	string word;
	string wordToTranslate;
	cout << "input word to translate:";
	getline(cin, wordToTranslate);
	transform(wordToTranslate.begin(), wordToTranslate.end(), wordToTranslate.begin(), tolower);
	return wordToTranslate;
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
	cout << "dictionary does not have a given word" << endl << "enter the translation or press enter to skip:";

	getline(cin, translatedWord);

	if (!translatedWord.empty())
		if (int(translatedWord[0]) < 0 && int(translatedWord[0]) >= -32)
			dictionary.insert(pair<string, string>(wordToTranslate, translatedWord));
		else
			dictionary.insert(pair<string, string>(translatedWord, wordToTranslate));
	else cout << "word was ignored" << endl;
}

void InputDictionaryFromFile(multimap <string, string> &dictionary, string inputFileName)
{
	ifstream inputFile(inputFileName);
	if (inputFile.is_open())
	{
		string word;
		string translatedWord;
		string line;
		while (getline(inputFile, line))
		{
			size_t translatePosition;
			bool isFindTranslateWord = false;

			transform(line.begin(), line.end(), line.begin(), tolower);

			for (translatePosition = 0; !isFindTranslateWord; translatePosition++)
			{
				if (int(line[translatePosition]) >= -32 && int(line[translatePosition]) < 0) isFindTranslateWord = true;
			}

			word = line.substr(0, translatePosition-2);
			translatedWord = line.substr(translatePosition-1, line.length());
			dictionary.insert(pair<string, string>(word, translatedWord));
		}
	}
	else
	{
		cout << "input file is not opened" << endl;
		ofstream outputFile(inputFileName);
	}
}