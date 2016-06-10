#pragma once
#include "stdafx.h"

class CSuprefixCheck : boost::noncopyable
{
public:
	bool GetWordsAndSuprefix(std::string const & fileName);
	void CountNumberOfSuprefixWords();
	std::vector<std::string> GetWords() const;
	std::vector<std::string> GetSuprefix() const;
	std::vector<size_t> GetCountOfSuprefix() const;
	void WriteNumberOfSuprefix();
	void GetWordsFromFile(std::ifstream & inputFile);
	void GetSuprefixFromFile(std::ifstream & inputFile, size_t & count);
	//TODO: suprefix
private:
	std::vector<std::string> m_words;
	std::vector<std::string> m_suprefixWords;
	std::vector<size_t> m_countOfSuprefixInWords;
	size_t m_numberOfWords;
	size_t m_numberOfSuprefix;
};

