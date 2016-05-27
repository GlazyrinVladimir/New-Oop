#include "stdafx.h"
#include <Windows.h>
#include "..\task1\timber.h"

using namespace std;

struct timberCut
{
	CTimber timber;
};

BOOST_FIXTURE_TEST_SUITE(START_CUT_TIMBER, timberCut);

	BOOST_AUTO_TEST_CASE(when_zero_cut)
	{
		timber.CutTimber(100, 0);
		unsigned cost = 0;
		BOOST_CHECK(timber.GetCost() == cost);
	}
	
	BOOST_AUTO_TEST_CASE(return_zero_when_length_less_numberOfCuts)
	{
		timber.CutTimber(0, 1);
		unsigned cost = 0;
		BOOST_CHECK(timber.GetCost() == cost);
	}

	BOOST_AUTO_TEST_CASE(test_from_example)
	{
		timber.CutTimber(100, 3);
		unsigned cost = 105;
		BOOST_CHECK(timber.GetCost() == cost);
	}

	BOOST_AUTO_TEST_CASE(test_from_example2)
	{
		timber.CutTimber(10, 4);
		unsigned cost = 18;
		BOOST_CHECK(timber.GetCost() == cost);
	}

	BOOST_AUTO_TEST_CASE(return_timber_length_when_one_cut)
	{
		timber.CutTimber(100000, 1);
		unsigned cost = 100000;
		BOOST_CHECK(timber.GetCost() == cost);
	}

	BOOST_AUTO_TEST_CASE(second_test)
	{
		timber.CutTimber(100000, 10);
		unsigned cost = 100034;
		BOOST_CHECK(timber.GetCost() == cost);
	}

BOOST_AUTO_TEST_SUITE_END()


