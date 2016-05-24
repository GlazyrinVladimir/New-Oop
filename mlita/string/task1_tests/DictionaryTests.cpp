#include "stdafx.h"
#include <Windows.h>
#include "..\task1\Dictionary.h"

using namespace std;

struct suprefiksSearch
{
	CSuprefiksCheck suprefiks;
	string firstTestFile = "empty.txt";
	string secondTestFile = "input.txt";
	string thirdTestFile = "tests2.txt";
	string fourthTestFile = "tests3.txt";
};

BOOST_FIXTURE_TEST_SUITE(start_suprefiks_search_tests, suprefiksSearch)

	BOOST_AUTO_TEST_CASE(load_empty_set_of_words)
	{
		suprefiks.GetWordsAndSuprefiks(firstTestFile);
		BOOST_CHECK(suprefiks.GetWords().empty());
		BOOST_CHECK(suprefiks.GetSuprefiks().empty());
	}
	
	BOOST_AUTO_TEST_CASE(first_test)
	{
		vector<int> suprefiksTest = { 4, 2, 0 };
		suprefiks.GetWordsAndSuprefiks(secondTestFile);
		suprefiks.CountWordsContainsSuprefiksWords();
		BOOST_CHECK(suprefiks.GetCountOfSuprefiks() == suprefiksTest);
	}

	BOOST_AUTO_TEST_CASE(second_test)
	{
		vector<int> suprefiksTest = { 200000, 70507};
		suprefiks.GetWordsAndSuprefiks(thirdTestFile);
		suprefiks.CountWordsContainsSuprefiksWords();
		BOOST_CHECK(suprefiks.GetCountOfSuprefiks() == suprefiksTest);
	}

	/*BOOST_AUTO_TEST_CASE(third_test)
	{
		BOOST_CHECK(!suprefiks.GetWordsAndSuprefiks(fourthTestFile));
	}*/
BOOST_AUTO_TEST_SUITE_END()


