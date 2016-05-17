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
#include "DictionaryLogic.h"

using namespace std;

class CDictionary : boost::noncopyable
{
public:
	string GetWordToTranslate();
	void SaveDictionaryInFile();
	void DialogBeforeFinishWithUser();
	void StartWorkWithDictionary();
	bool IsHaveTranslate(string &wordToTranslate);
	void InputDictionaryFromFile();
	
	void SavingNewWordTranslation(string wordToTranslate, string translatedWord);
private:
	CDictionaryLogic logic;
	//multimap <string, string> m_dictionary;
//private:
	
};

