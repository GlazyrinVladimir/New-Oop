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
#include <boost/noncopyable.hpp>

using namespace std;

class CDictionary : boost::noncopyable
{
public:
	string GetFileName();
	string GetWordToTranslate();
	void SaveDictionaryInFile();
	void DialogBeforeFinishWithUser();
	void StartWorkWithDictionary();
	bool IsHaveRusTranslate(string &wordToTranslate);
	bool IsHaveEngTranslate(string &wordToTranslate);
	bool IsHaveTranslate(string &wordToTranslate);
	void InputDictionaryFromFile(ifstream & inputFile);
	void SavingNewWordTranslation(string wordToTranslate);
private:
	std::string m_fileName;
	multimap <string, string> m_dictionary;
//private:
	
};

