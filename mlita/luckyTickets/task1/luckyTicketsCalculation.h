#pragma once

#include "stdafx.h"
#define DECIMAL 10

class luckyTicketsCalculation
{
public:
	bool GetTicketNumber(std::string const & name);
	size_t GetMinNumberOfNextTickets();
private:
	size_t HalfCalculation(size_t const & start, size_t const & finish);

	std::vector<int> m_ticket;
	size_t m_ticketHalfLength;
	size_t m_position;
};
