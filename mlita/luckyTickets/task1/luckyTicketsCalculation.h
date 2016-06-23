#pragma once

#include "stdafx.h"
const unsigned int TEN = 10;
const unsigned int NINE = 9;

class CLuckyTicketsCalculation
{
public:
	bool GetTicketNumber(std::string const & name);
	void GetMinNumberOfNextTicket();
	void OutputAnswer();
	void DoCalculation();
	std::vector<size_t> GetCount()const;
private:
	size_t HalfCalculation(size_t const & start, size_t const & finish);

	std::vector<int> m_ticket;
	size_t m_ticketHalfLength;
	size_t m_position;
	std::vector<size_t> m_count;
	int m_difference;

};
