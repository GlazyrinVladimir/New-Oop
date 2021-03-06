#include "stdafx.h"
#include "DictionaryLogic.h"

using namespace std;

multimap <string, string> CDictionaryLogic::GetDictionary()
{
	return m_dictionary;
}

string CDictionaryLogic::GetFileName()
{
	return m_fileName;
}

void CDictionaryLogic::SetFileName()
{
	cout << "input file name: ";
	getline(cin, m_fileName);
}

string CDictionaryLogic::GetTranslation()
{
	string translatedWord;
	getline(cin, translatedWord);
	return translatedWord;
}

bool CDictionaryLogic::IsHaveEngTranslate(string &wordToTranslate)
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

bool CDictionaryLogic::IsHaveRusTranslate(string &wordToTranslate)
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

void CDictionaryLogic::InputDictionary()
{
	ifstream inputFile(m_fileName);
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

			word = line.substr(0, translatePosition - 2);
			translatedWord = line.substr(translatePosition - 1, line.length());
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

void CDictionaryLogic::SavingNewWordTranslation(string wordToTranslate, string translatedWord)
{
	if (!translatedWord.empty())
		if (int(translatedWord[0]) < 0 && int(translatedWord[0]) >= -32)
			m_dictionary.insert(pair<string, string>(wordToTranslate, translatedWord));
		else
			m_dictionary.insert(pair<string, string>(translatedWord, wordToTranslate));
	else cout << "word was ignored" << endl;
}

void CDictionaryLogic::SaveDictionaryInFile()
{
	ofstream outputFile(GetFileName());
	for (auto it = m_dictionary.begin(); it != m_dictionary.end(); ++it)
	{
		outputFile << it->first << " " << it->second << endl;
	}
	outputFile.flush();
}