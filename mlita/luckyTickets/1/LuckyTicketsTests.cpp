#include "stdafx.h"
#include <Windows.h>
#include "..\task1\luckyTicketsCalculation.h"

using namespace std;

struct filesForTicketsTests
{
	luckyTicketsCalculation ticket;
	string emptyFile = "empty.txt";
	string errorFile = "test0.txt";
	string firstTestFile = "test1.txt";
	string secondTestFile = "test2.txt";
	string thirdTestFile = "test3.txt";
	string fourthTestFile = "test4.txt";
	string fifthTestFile = "test5.txt";
};

BOOST_FIXTURE_TEST_SUITE(start_suprefiks_search_tests, filesForTicketsTests)

	BOOST_AUTO_TEST_CASE(load_error_file_name)
	{
		BOOST_CHECK(!ticket.GetTicketNumber(errorFile));
	}

	BOOST_AUTO_TEST_CASE(is_not_crashing_when_file_empty)
	{
		BOOST_CHECK(!ticket.GetTicketNumber(emptyFile));
	}

	BOOST_AUTO_TEST_CASE(first_test_from_task)
	{
		size_t answer = 12;
		BOOST_CHECK(ticket.GetTicketNumber(firstTestFile));
		BOOST_CHECK_EQUAL(ticket.GetMinNumberOfNextTickets(), answer);
	}

	BOOST_AUTO_TEST_CASE(second_test_from_task)
	{
		size_t answer = 5;
		BOOST_CHECK(ticket.GetTicketNumber(secondTestFile));
		BOOST_CHECK_EQUAL(ticket.GetMinNumberOfNextTickets(), answer);
	}

	BOOST_AUTO_TEST_CASE(third_test_from_task)
	{
		size_t answer = 0;
		BOOST_CHECK(ticket.GetTicketNumber(thirdTestFile));
		BOOST_CHECK_EQUAL(ticket.GetMinNumberOfNextTickets(), answer);
	}
	
	BOOST_AUTO_TEST_CASE(fifth_test_for_max_N)
	{
		size_t answer = 1;
		BOOST_CHECK(ticket.GetTicketNumber(fifthTestFile));
		BOOST_CHECK_EQUAL(ticket.GetMinNumberOfNextTickets(), answer);
	}

BOOST_AUTO_TEST_SUITE_END()


