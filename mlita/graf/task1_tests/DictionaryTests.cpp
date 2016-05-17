#include "stdafx.h"
#include <Windows.h>
#include "..\task1\Dictionary.h"

using namespace std;

struct dictionary
{
	CDictionary dic;
};

BOOST_FIXTURE_TEST_SUITE(start_dictionary_tests, dictionary)

	// Создает пустой вектор из пустого вектора
	BOOST_AUTO_TEST_CASE(load_empty_dictionary)
	{
		ifstream inputFile(dic.SetFileName("tests1.txt"));
		
		dic.InputDictionaryFromFile(inputFile);

		BOOST_CHECK(dic.GetDictionary().empty());
	
	}

	BOOST_AUTO_TEST_CASE(load_not_empty_dictionary)
	{
		ifstream inputFile(dic.SetFileName("tests2.txt"));
	
		dic.InputDictionaryFromFile(inputFile);

		BOOST_CHECK(!dic.GetDictionary().empty());
	}

	BOOST_AUTO_TEST_CASE(can_find_word_in_dictionary)
	{
		ifstream inputFile(dic.SetFileName("tests2.txt"));

		dic.InputDictionaryFromFile(inputFile);
		string word = "hi";
		BOOST_CHECK(!dic.GetDictionary().empty());
		BOOST_CHECK(dic.IsHaveTranslate(word));
		word = "привет";
		BOOST_CHECK(dic.IsHaveTranslate(word));
	}

	BOOST_AUTO_TEST_CASE(can_save_dictionary)
	{
		ifstream inputFile(dic.SetFileName("tests2.txt"));
		dic.InputDictionaryFromFile(inputFile);
		BOOST_CHECK(!dic.GetDictionary().empty());
		multimap <string, string> dictionary = dic.GetDictionary();
		dic.SaveDictionaryInFile();
		dic.InputDictionaryFromFile(inputFile);
		BOOST_CHECK(dic.GetDictionary() == dictionary);
	}

	BOOST_AUTO_TEST_CASE(can_add_word_in_dictionary)
	{
		ifstream inputFile(dic.SetFileName("tests2.txt"));
		dic.InputDictionaryFromFile(inputFile);
		string word = "mother";
		string wordTranslation = "мама";
		BOOST_CHECK(!dic.GetDictionary().empty());
		BOOST_CHECK(!dic.IsHaveTranslate(word));
		dic.SavingNewWordTranslation(word, wordTranslation);
		BOOST_CHECK(dic.IsHaveTranslate(word));
	}

	BOOST_AUTO_TEST_CASE(can_create_empty_dictionary_and_add_some_words)
	{
		ifstream inputFile(dic.SetFileName("tests3.txt"));
		dic.InputDictionaryFromFile(inputFile);
		BOOST_CHECK(dic.GetDictionary().empty());
		string firstWord = "mother";
		string firstWordTranslation = "мама";	
		BOOST_CHECK(!dic.IsHaveTranslate(firstWord));
		dic.SavingNewWordTranslation(firstWord, firstWordTranslation);
		string secondWord = "father";
		string secondWordTranslation = "папа";
		BOOST_CHECK(!dic.IsHaveTranslate(secondWord));
		dic.SavingNewWordTranslation(secondWord, secondWordTranslation);
		multimap <string, string> dictionary = dic.GetDictionary();
		dic.SaveDictionaryInFile();
		dic.InputDictionaryFromFile(inputFile);
		BOOST_CHECK(dic.GetDictionary() == dictionary && !dictionary.empty());
	}

BOOST_AUTO_TEST_SUITE_END()


