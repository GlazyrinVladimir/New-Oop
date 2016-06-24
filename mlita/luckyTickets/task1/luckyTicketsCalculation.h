#pragma once

#include "stdafx.h"
const unsigned int TEN = 10;
const unsigned int NINE = 9;

class CLuckyTicketsCalculation
{
public:
	bool ReadTicketNumber(std::string const & name);
	void ReceiveMinNumberOfNextTicket();
	void OutputAnswer();
	
	std::vector<size_t> GetCount()const;
private:
	void DoCalculation();
	size_t HalfCalculation(size_t const & start, size_t const & finish);
	
	size_t m_ticketHalfLength;
	size_t m_position;
	std::vector<size_t> m_count;
	std::vector<unsigned> m_ticket;
	int m_difference;

};
