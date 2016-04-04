#include "stdafx.h"
#include "Dictionary.h"

using namespace std;

void CDictionary::StartWorkWithDictionary()
{
	ifstream inputFile(GetFileName());
	InputDictionaryFromFile(inputFile);
	string wordToTranslate;
	while (wordToTranslate != "...")
	{
		wordToTranslate = GetWordToTranslate();
		if (!IsHaveTranslate(wordToTranslate) && wordToTranslate != "...")
		{
			SavingNewWordTranslation(wordToTranslate);
		}
	}
}

void CDictionary::DialogBeforeFinishWithUser()
{
	string AnswerWord;

	while (AnswerWord != "y" && AnswerWord != "n")
	{
		cout << "do you want to save dictionary? y/n:";
		getline(cin, AnswerWord);
		if (AnswerWord == "y")
			SaveDictionaryInFile();
	}
}

string CDictionary::GetFileName()
{
	cout << "input file name: ";
	getline(cin, m_fileName);
	return m_fileName;
}

void CDictionary::SaveDictionaryInFile()
{
	ofstream outputFile(m_fileName);
	for (auto it = m_dictionary.begin(); it != m_dictionary.end(); ++it)
	{
		outputFile << it->first << " " << it->second << endl;
	}
	outputFile.flush();
}

string CDictionary::GetWordToTranslate()
{
	string wordToTranslate;
	cout << "input word to translate:";
	getline(cin, wordToTranslate);
	transform(wordToTranslate.begin(), wordToTranslate.end(), wordToTranslate.begin(), tolower);
	return wordToTranslate;
}

bool CDictionary::IsHaveEngTranslate(string &wordToTranslate)
{
	bool isTranslated = false;

	for (auto it = m_dictionary.begin(); it != m_dictionary.end(); ++it)
	{
		if (it->second == wordToTranslate)
		{
			isTranslated = true;
			cout << "translate:" << it->first << " " << endl;
		}
	}
	
	return isTranslated;
}

bool CDictionary::IsHaveRusTranslate(string &wordToTranslate)
{
	bool isTranslated = false;

	for (auto it = m_dictionary.begin(); it != m_dictionary.end(); ++it)
	{
		if (it->first == wordToTranslate)
		{
			isTranslated = true;
			cout << "translate:" << it->second << " " << endl;
		}
	}

	return isTranslated;
}

bool CDictionary::IsHaveTranslate(string &wordToTranslate)
{
	if (IsHaveRusTranslate(wordToTranslate))
		return 1; 
	else 
		return IsHaveEngTranslate(wordToTranslate);
}

void CDictionary::SavingNewWordTranslation(string wordToTranslate)
{
	string translatedWord;
	cout << "dictionary does not have a given word" << endl << "enter the translation or press enter to skip:";
	getline(cin, translatedWord);
	if (!translatedWord.empty())
		if (int(translatedWord[0]) < 0 && int(translatedWord[0]) >= -32)
			m_dictionary.insert(pair<string, string>(wordToTranslate, translatedWord));
		else
			m_dictionary.insert(pair<string, string>(translatedWord, wordToTranslate));
	else cout << "word was ignored" << endl;
}

void CDictionary::InputDictionaryFromFile(ifstream &inputFile)
{
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
			m_dictionary.insert(pair<string, string>(word, translatedWord));
		}
	}
	else
	{
		cout << "input file is not opened" << endl;
		ofstream outputFile(m_fileName);
		outputFile.flush();
	}
}