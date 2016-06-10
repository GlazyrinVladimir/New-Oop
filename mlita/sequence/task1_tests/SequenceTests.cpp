#include "stdafx.h"
#include "..\task1\Sequence.h"

using namespace std;

struct FilesForTests
{
	CSequence seq;
	string firstFile = "test1.txt";
	string secondFile = "test2.txt";
	string thirdFile = "test3.txt";
	string fourthFile = "test5.txt";
};

BOOST_FIXTURE_TEST_SUITE(start_sequence_tests, FilesForTests)

	BOOST_AUTO_TEST_CASE(get_error_when_inputFile_is_not_created)
	{
		BOOST_CHECK(!seq.ReadSequence("test0.txt"));
	}

BOOST_AUTO_TEST_CASE(load_file_when_error_amount_of_numbers)
{
	BOOST_CHECK(!seq.ReadSequence(firstFile));
}

BOOST_AUTO_TEST_CASE(first_test_from_lecture)
{
	BOOST_CHECK(seq.ReadSequence(secondFile));
	seq.CalculationSequence();
	size_t answer = 3;
	BOOST_CHECK_EQUAL(answer, seq.GetCount());
}

BOOST_AUTO_TEST_CASE(second_test_from_lecture)
{
	BOOST_CHECK(seq.ReadSequence(thirdFile));
	seq.CalculationSequence();
	size_t answer = 0;
	BOOST_CHECK_EQUAL(answer, seq.GetCount());
}

BOOST_AUTO_TEST_CASE(test_on_max_bound)
{
	BOOST_CHECK(seq.ReadSequence("test5.txt"));
	seq.CalculationSequence();
	size_t answer = 998001;
	BOOST_CHECK_EQUAL(answer, seq.GetCount());
}

BOOST_AUTO_TEST_SUITE_END()

