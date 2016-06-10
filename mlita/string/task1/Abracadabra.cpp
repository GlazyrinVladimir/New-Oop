#include "stdafx.h"
#include "Abracadabra.h"

using namespace std;

void CSuprefixCheck::GetWordsFromFile(ifstream & inputFile)
{
	string storage;
	for (size_t i = 0; i < m_numberOfWords; i++)
	{
		getline(inputFile, storage);
		m_words.push_back(storage);
	}
	std::sort(m_words.begin(), m_words.end());
}

void CSuprefixCheck::GetSuprefixFromFile(std::ifstream & inputFile, size_t & count)
{
	string storage;
	while (!inputFile.eof())
	{
		getline(inputFile, storage);
		m_suprefixWords.push_back(storage);
		m_countOfSuprefixInWords.push_back(0);
		count += 1;
	}
}

bool CSuprefixCheck::GetWordsAndSuprefix(string const & fileName)
{
	// Remove this stream, use normal error check mechanicss
	ifstream inputFile(fileName);
	string storage;
	size_t count = 0;
	getline(inputFile, storage);

	if (atoi(storage.c_str()))
	{
		m_numberOfWords = stoi(storage);
		GetWordsFromFile(inputFile);
		getline(inputFile, storage);
		if (atoi(storage.c_str()))
		{
			m_numberOfSuprefix = stoi(storage);

			GetSuprefixFromFile(inputFile, count);

			if (count != m_numberOfSuprefix)
			{				
				for (size_t i = count; i < m_numberOfSuprefix; i++)
				{
					m_suprefixWords.push_back("");
					m_countOfSuprefixInWords.push_back(0);
				}
			}
			return true;
		}
	}
	return false;
}

std::vector<size_t> CSuprefixCheck::GetCountOfSuprefix() const
{
	return m_countOfSuprefixInWords;
}

std::vector<std::string> CSuprefixCheck::GetWords() const
{
	return m_words;
}

std::vector<std::string> CSuprefixCheck::GetSuprefix() const
{
	return m_suprefixWords;
}

void CSuprefixCheck::CountNumberOfSuprefixWords()
{
	for (size_t i = 0; i < m_numberOfSuprefix; i++)
	{
		string suprefixWord = m_suprefixWords[i];
		bool wasFirstLetterOfSup = false;
		if (suprefixWord != "")
		{
			for (size_t j = 0; j < m_numberOfWords;)
			{
				string word = m_words[j];
				size_t count = 0;

				if (word[0] == suprefixWord[0])
				{
					wasFirstLetterOfSup = true;
					while (word[count] == suprefixWord[count] && count != suprefixWord.length()
						&& word[word.length() - count - 1] == suprefixWord[suprefixWord.length() - count - 1])
					{
						count++; // TODO: add {}
					}
					if (count == suprefixWord.length()) // TODO: add {}
					{
						m_countOfSuprefixInWords[i] += 1;
					}
				}
				else if (wasFirstLetterOfSup)
				{
					j = m_numberOfWords; // TODO: add {}
				}
				j++;
			}
		}
	}
}

void CSuprefixCheck::WriteNumberOfSuprefix()
{
	ofstream outputFile("output.txt");
	for (size_t i = 0; i < m_numberOfSuprefix; i++)
	{
		outputFile << m_countOfSuprefixInWords[i] << endl;
	}
}