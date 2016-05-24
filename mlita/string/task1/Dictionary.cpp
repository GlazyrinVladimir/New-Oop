#include "stdafx.h"
#include <stdio.h>
#include <io.h>
#include <fcntl.h>
#include <stdlib.h>
#include "Dictionary.h"

using namespace std;

bool CSuprefiksCheck::GetWordsAndSuprefiks(string const & fileName)
{
	ifstream inputFile(fileName);
	string storage;
	int count = 0;
	getline(inputFile, storage);
	std::stringstream isStringNumber;
	isStringNumber << storage;
	isStringNumber >> count;

	if (storage != "" && isStringNumber)
	{
		isStringNumber.clear();
		m_numberOfWords = stoi(storage);
		for (size_t i = 0; i < m_numberOfWords; i++)
		{
			getline(inputFile, storage);
			m_words.push_back(storage);
		}
		std::sort(m_words.begin(), m_words.end());
		getline(inputFile, storage);
		isStringNumber << storage;
		isStringNumber >> count;
		if (storage != "" && isStringNumber)
		{
			isStringNumber.clear();

			m_numberOfSuprefiks = stoi(storage);

			while (!inputFile.eof())
			{
				getline(inputFile, storage);
				m_suprefiksWords.push_back(storage);
				m_countOfSuprefiksInWords.push_back(0);
				count += 1;
			}

			if (count != m_numberOfSuprefiks)
			{
				
				for (size_t i = count; i < m_numberOfSuprefiks; i++)
				{
					cout << "kek";
					m_suprefiksWords.push_back("");
					m_countOfSuprefiksInWords.push_back(0);
				}
			}
		}
		return false;
	}
	else return false;
	return true;
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
		bool wasFirstLetterOfSup = false;
		if (suprefiksWord != "")
		for (size_t j = 0; j < m_numberOfWords;)
		{ 
			string word = m_words[j];
			int count = 0;
			
			if (word[0] == suprefiksWord[0])
			{
				wasFirstLetterOfSup = true;
				while (word[count] == suprefiksWord[count] && count != suprefiksWord.length() && word[word.length() - count - 1] == suprefiksWord[suprefiksWord.length() - count - 1])
					count++;

				if (count == suprefiksWord.length())
					m_countOfSuprefiksInWords[i] += 1;
			}
			else
				if (wasFirstLetterOfSup)
					j == m_numberOfWords;
			j++;
		}
	}
}

void CSuprefiksCheck::WriteNumberOfSuprefiks()
{
	ofstream outputFile("output.txt");
	for (size_t i = 0; i < m_numberOfSuprefiks; i++)
	{
		outputFile << m_countOfSuprefiksInWords[i] << endl;
	}
}