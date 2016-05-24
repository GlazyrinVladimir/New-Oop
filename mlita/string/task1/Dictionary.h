#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <functional>
#include <vector>
#include <boost/range/algorithm/transform.hpp>
#pragma warning (push, 3)
#include <boost/phoenix.hpp>
#pragma warning (pop)
#include <boost/algorithm/string.hpp>
#include <map>
#include <fstream>
#include <vector>
#include <boost/noncopyable.hpp>
#include <iostream>
#include <sstream>

class CSuprefiksCheck : boost::noncopyable
{
public:
	bool GetWordsAndSuprefiks(std::string const & fileName);
	void CountWordsContainsSuprefiksWords();
	std::vector<std::string> GetWords();
	std::vector<std::string> GetSuprefiks();
	std::vector<int> GetCountOfSuprefiks();
	void WriteNumberOfSuprefiks();
private:
	std::vector<std::string> m_words;
	std::vector<std::string> m_suprefiksWords;
	std::vector<int> m_countOfSuprefiksInWords;
	int m_numberOfWords;
	int m_numberOfSuprefiks;
};

