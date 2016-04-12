#include <boost/algorithm/string.hpp>
#include <map>
#include <fstream>
#include <iostream>
#include <boost/noncopyable.hpp>

class CDictionaryLogic : boost::noncopyable
{
public:
	std::string GetFileName();
	void SetFileName();
	std::multimap <std::string, std::string> GetDictionary();
	bool IsHaveRusTranslate(std::string &wordToTranslate);
	bool IsHaveEngTranslate(std::string &wordToTranslate);
	std::string GetTranslation();
	void InputDictionary();
	void SavingNewWordTranslation(std::string wordToTranslate, std::string translatedWord);
	void SaveDictionaryInFile();
private:
	std::string m_fileName;
	std::multimap <std::string, std::string> m_dictionary;
};