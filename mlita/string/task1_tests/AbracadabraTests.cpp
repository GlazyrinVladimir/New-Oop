#include "stdafx.h"
#include <Windows.h>
#include "..\task1\Abracadabra.h"

using namespace std;

struct suprefixSearch
{
	CSuprefixCheck suprefix;
	string firstTestFile = "empty.txt";
	string secondTestFile = "input.txt";
	string thirdTestFile = "tests2.txt";
	string fourthTestFile = "tests3.txt";
};

BOOST_FIXTURE_TEST_SUITE(start_suprefix_search_tests, suprefixSearch)

	BOOST_AUTO_TEST_CASE(load_empty_set_of_words)
	{
		suprefix.GetWordsAndSuprefix(firstTestFile);
		BOOST_CHECK(suprefix.GetWords().empty());
		BOOST_CHECK(suprefix.GetSuprefix().empty());
	}
	
	BOOST_AUTO_TEST_CASE(trivial_test)
	{
		vector<size_t> suprefixTest = { 4, 2, 0 };
		suprefix.GetWordsAndSuprefix(secondTestFile);
		suprefix.CountNumberOfSuprefixWords();
		BOOST_CHECK(suprefix.GetCountOfSuprefix() == suprefixTest);
	}

	BOOST_AUTO_TEST_CASE(max_of_words)
	{
		vector<size_t> suprefixTest = { 200000, 70507};
		suprefix.GetWordsAndSuprefix(thirdTestFile);
		suprefix.CountNumberOfSuprefixWords();
		BOOST_CHECK(suprefix.GetCountOfSuprefix() == suprefixTest);
	}

	BOOST_AUTO_TEST_CASE(error_input_number_of_words)
	{
		BOOST_CHECK(!suprefix.GetWordsAndSuprefix(fourthTestFile));
	}

	BOOST_AUTO_TEST_CASE(error_input_number_of_suprefix)
	{
		BOOST_CHECK(!suprefix.GetWordsAndSuprefix(fourthTestFile));
	}
BOOST_AUTO_TEST_SUITE_END()


