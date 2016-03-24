#include "stdafx.h"
#include "Dictionary.h"

using namespace std;

bool isHaveTranslate(multimap <string, string> &dictionary,string &wordToTranslate)
{
	bool isTranslated = false;
	string word;
	cout << "input word to translate:";
	cin >> word;
	getline(cin, wordToTranslate);
	wordToTranslate = word + wordToTranslate;
	if (wordToTranslate != "...")
		for (auto it = dictionary.begin(); it != dictionary.end(); ++it)
		{

			if (it->first == wordToTranslate)
			{
				isTranslated = true;
				cout << "translate:" << it->second << " " << endl;
			}
		}
	else return 1;
	if (isTranslated) return 1; 
	else return 0;
}

void SavingNewWordTranslation(multimap <string, string> &dictionary, string wordToTranslate)
{
	string translatedWord;
	string word;
	cout << "dictionary does not have a given word" << endl << "enter the translation:";
	cin >> word;
	getline(cin, translatedWord);
	translatedWord = word + translatedWord;
	dictionary.insert(pair<string, string>(wordToTranslate, translatedWord));
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
			int kek = line[6];
			cout << line << endl;
			cout << "ascii:" << kek << endl;
		//	inputFile >> word;
			//inputFile >> translatedWord;
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