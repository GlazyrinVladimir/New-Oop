#pragma once

#include "stdafx.h"

class luckyTicketsCalculation
{
public:
	bool GetTicketNumber(std::string name);
	size_t GetMinNumberOfNextTickets();
private:
	size_t HalfCalculation(size_t start, size_t finish);

	std::vector<int> ticket;
	size_t ticketHalfLength;
	size_t position;
};
