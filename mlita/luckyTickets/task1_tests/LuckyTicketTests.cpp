#include "stdafx.h"
#include "..\task1\luckyTicketsCalculation.h"

using namespace std;

bool CheckEqualVector(vector<size_t> v1, vector<size_t> v2)
{
	for (size_t i = 0; i < v1.size(); i++)
	{
		if (v1[i] != v2[i])
		{
			return false;
		}
	}
	return true;
}

struct FilesForTests
{
	CLuckyTicketsCalculation ticket;
	string firstFile = "test1.txt";
	string secondFile = "test2.txt";
	string thirdFile = "test3.txt";
	string fourthFile = "test5.txt";
	string fifthtFile = "empty.txt";
};

BOOST_FIXTURE_TEST_SUITE(Check_engine, FilesForTests)

	BOOST_AUTO_TEST_CASE(can_load_empty_file)
	{
		BOOST_CHECK(!ticket.GetTicketNumber(fifthtFile));
	}

BOOST_AUTO_TEST_CASE(first_test_from_lecture)
{
	BOOST_CHECK(ticket.GetTicketNumber(firstFile));
	vector<size_t> answer = { 2,1 };
	ticket.GetMinNumberOfNextTickets();
	vector<size_t> count = ticket.GetCount();
	BOOST_CHECK(CheckEqualVector(answer, count));
}

BOOST_AUTO_TEST_CASE(second_test_from_lecture)
{
	BOOST_CHECK(ticket.GetTicketNumber(secondFile));
	vector<size_t> answer = { 5 };
	ticket.GetMinNumberOfNextTickets();
	vector<size_t> count = ticket.GetCount();
	BOOST_CHECK(CheckEqualVector(answer, count));
}

BOOST_AUTO_TEST_CASE(third_test_from_lecture)
{
	BOOST_CHECK(ticket.GetTicketNumber(thirdFile));
	vector<size_t> answer = { 0 };
	ticket.GetMinNumberOfNextTickets();
	vector<size_t> count = ticket.GetCount();
	BOOST_CHECK(CheckEqualVector(answer, count));
}

BOOST_AUTO_TEST_CASE(test_on_max_bound)
{
	BOOST_CHECK(ticket.GetTicketNumber(fourthFile));
	vector<size_t> answer (250, 9);
	ticket.GetMinNumberOfNextTickets();
	vector<size_t> count = ticket.GetCount();
	BOOST_CHECK(CheckEqualVector(answer, count));
}

BOOST_AUTO_TEST_SUITE_END()

