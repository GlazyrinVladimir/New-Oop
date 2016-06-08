#include "stdafx.h"
#include "../FindMaxEx/ArraySum.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(FindMaxEx)

BOOST_AUTO_TEST_CASE(return_value_T_type_when_get_empty_array)
{
	vector<string> testArray = {};
	BOOST_CHECK_EQUAL("", ArraySum(testArray));
}

BOOST_AUTO_TEST_CASE(can_count_up_some_integer_numbers)
{
	vector<int> testArray = { 1,2,3 };
	BOOST_CHECK_EQUAL(6, ArraySum(testArray));
}

BOOST_AUTO_TEST_CASE(can_count_up_some_float_numbers)
{
	vector<double> testArray = { 1.0,2.2,3.95 };
	BOOST_CHECK_EQUAL(7.15, ArraySum(testArray));
}

BOOST_AUTO_TEST_CASE(can_concatenate_some_words)
{
	vector<string> testArray = { "hello"," ","world","!" };
	BOOST_CHECK_EQUAL("hello world!", ArraySum(testArray));
}

BOOST_AUTO_TEST_SUITE_END()