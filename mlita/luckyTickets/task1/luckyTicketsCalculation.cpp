#include "stdafx.h"
#include "luckyTicketsCalculation.h"

using namespace std;

bool luckyTicketsCalculation::GetTicketNumber(std::string const & name)
{
	ifstream inputFile(name);
	if (inputFile.is_open())
	{
		string ticketNumber;
		inputFile >> m_ticketHalfLength;
		inputFile >> ticketNumber;

		if (ticketNumber.empty())
		{
			return false;
		}

		for (size_t i = 0; i < 2 * m_ticketHalfLength; i++)
		{
			char numeral = ticketNumber[i];
			m_ticket.push_back(numeral - 48);
		}
		return true;
	}
	else return false;
}

size_t luckyTicketsCalculation::HalfCalculation(size_t const & start, size_t const & finish)
{
	size_t count = 0;
	for (size_t i = start; i < finish; i++)
	{
		count += m_ticket[i];
	}
	return count;
}

size_t luckyTicketsCalculation::GetMinNumberOfNextTickets()
{
	m_position = m_ticket.size() - 1;
	size_t leftHalf = HalfCalculation(0, m_ticketHalfLength);
	size_t rightHalf = HalfCalculation(m_ticketHalfLength, 2 * m_ticketHalfLength);
	size_t count = 0;
	while (leftHalf != rightHalf)
	{
		count++;
		m_ticket[m_position] += 1;

		while (m_ticket[m_position] == DECIMAL)
		{
			m_ticket[m_position] = 0;
			m_position--;
			m_ticket[m_position]++;

			if (m_ticket[0] > 9)
			{
				m_ticket[0] = m_ticket[0] % DECIMAL;
			}
		}
		m_position = m_ticket.size() - 1;

		leftHalf = HalfCalculation(0, m_ticketHalfLength);
		rightHalf = HalfCalculation(m_ticketHalfLength, 2 * m_ticketHalfLength);
	}

	return count;
}