#include "stdafx.h"
#include <stdio.h>
#include <io.h>
#include <fcntl.h>
#include <stdlib.h>
#include "Dictionary.h"

using namespace std;

void CSuprefiksCheck::GetWordsAndSuprefiks(string const & fileName)
{
	ifstream inputFile(fileName);
	string storage;
	int count = 0;
	getline(inputFile, storage);
	if (storage != "")
	{
		m_numberOfWords = stoi(storage);
		for (size_t i = 0; i < m_numberOfWords; i++)
		{
			getline(inputFile, storage);
			m_words.push_back(storage);
		}
		std::sort(m_words.begin(), m_words.end());
		getline(inputFile, storage);
		if (storage != "")
		{
			m_numberOfSuprefiks = stoi(storage);

			while (!inputFile.eof())
			{
				getline(inputFile, storage);
				m_suprefiksWords.push_back(storage);
				m_countOfSuprefiksInWords.push_back(0);
				count += 1;
			}

			if (count != m_numberOfSuprefiks)
				for (size_t i = count; i < m_numberOfSuprefiks; i++)
				{
					m_suprefiksWords.push_back("");
					m_countOfSuprefiksInWords.push_back(0);
				}
		}
	}
}

std::vector<int> CSuprefiksCheck::GetCountOfSuprefiks()
{
	return m_countOfSuprefiksInWords;
}

std::vector<std::string> CSuprefiksCheck::GetWords()
{
	return m_words;
}

std::vector<std::string> CSuprefiksCheck::GetSuprefiks()
{
	return m_suprefiksWords;
}

void CSuprefiksCheck::CountWordsContainsSuprefiksWords()
{
	for (size_t i = 0; i < m_numberOfSuprefiks; i++)
	{
		string suprefiksWord = m_suprefiksWords[i];
		//cout << suprefiksWord << endl;
		if (suprefiksWord != "")
		for (size_t j = 0; j < m_numberOfWords; j++)
		{ 
			string word = m_words[j];
			int count = 0;
			while (word[count] == suprefiksWord[count] && count != suprefiksWord.length())
				count++;
			if (count == suprefiksWord.length())
			{
				count = 0;
				
					while (count != suprefiksWord.length() && word[word.length() - count - 1] == suprefiksWord[suprefiksWord.length() - count - 1])
						count++;
					if (count == suprefiksWord.length())
						m_countOfSuprefiksInWords[i] += 1;
			}
		}
	}
}

void CSuprefiksCheck::WriteNumberOfSuprefiks()
{
	for (size_t i = 0; i < m_numberOfSuprefiks; i++)
	{
		cout << m_countOfSuprefiksInWords[i] << endl;
	}
}