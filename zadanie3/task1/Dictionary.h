#pragma once
#include <string>
#include <iostream>
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

using namespace std;

void GetWordToTranslate(string &wordToTranslate);
void SaveDictionaryInFile(multimap <string, string> const dictionary, ofstream &outputFile);
bool IsHaveRusTranslate(multimap <string, string> &dictionary, string &wordToTranslate);
bool IsHaveEngTranslate(multimap <string, string> &dictionary, string &wordToTranslate);
bool IsHaveTranslate(multimap <string, string> &dictionary, string &wordToTranslate);
string InputDictionaryFromFile(multimap <string, string> &dictionary);
void SavingNewWordTranslation(multimap <string, string> &dictionary, string wordToTranslate);