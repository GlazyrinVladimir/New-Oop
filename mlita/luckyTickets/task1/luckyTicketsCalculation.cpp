#include "stdafx.h"
#include "luckyTicketsCalculation.h"

using namespace std;

bool CLuckyTicketsCalculation::ReadTicketNumber(std::string const & name)
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
	return false;
}

size_t CLuckyTicketsCalculation::HalfCalculation(size_t const & start, size_t const & finish)
{
	size_t count = 0;
	for (size_t i = start; i < finish; i++)
	{
		count += m_ticket[i];
	}
	return count;
}

std::vector<size_t> CLuckyTicketsCalculation::GetCount()const
{
	return m_count;
}

void CLuckyTicketsCalculation::OutputAnswer()
{
	size_t i = m_count.size() - 1;
	while (m_count[i] == 0)
	{
		m_count.erase(m_count.begin() + i);
		i--;
	}

	if (m_count.size() == 0)
	{
		cout << "0";
	}
	else
	{
		for (int j = m_count.size() - 1; j >= 0; j--)
		{
			cout << m_count[j];
		}
	}
}

void CLuckyTicketsCalculation::DoCalculation()
{

	m_position = m_ticket.size() - 1;
	size_t countPosition = 0;

	while (m_difference != 0)
	{
		int increase = NINE - m_ticket[m_position];
		if (m_difference > NINE)
		{
			m_ticket[m_position] = m_ticket[m_position] + increase;
			m_difference -= increase;
			m_count[countPosition] += increase;
		}
		else
		{
			if (increase >= m_difference)
			{
				m_count[countPosition] += m_difference;
				m_ticket[m_position] = m_ticket[m_position] + m_difference;
				m_difference = 0;
			}
			else
			{
				m_ticket[m_position] = m_ticket[m_position] + increase;
				m_difference -= increase;
				m_count[countPosition] += increase;
			}
		}
		size_t countForZeroing = countPosition;
		while (m_count[countForZeroing] > NINE)
		{
			m_count[countForZeroing] = m_count[countForZeroing] % TEN;
			m_count[countForZeroing +1]++;
			countForZeroing++;
		}
		m_position--;
		countPosition++;
	}
}

void CLuckyTicketsCalculation::ReceiveMinNumberOfNextTicket()
{
	m_position = m_ticket.size() - 1;
	size_t leftHalf = HalfCalculation(0, m_ticketHalfLength);
	size_t rightHalf = HalfCalculation(m_ticketHalfLength, 2 * m_ticketHalfLength);

	m_difference = leftHalf - rightHalf;

	for (size_t i = 0; i <= m_ticketHalfLength; i++)
	{
		m_count.push_back(0);
	}

	size_t countPosition = 0;
	while (leftHalf < rightHalf)
	{
		m_count[countPosition] += TEN - m_ticket[m_position];
		countPosition++;
		m_count[countPosition] += m_count[countPosition - 1] / TEN;
		m_count[countPosition - 1] = m_count[countPosition - 1] % TEN;
		m_ticket[m_position] = 0;
		m_ticket[m_position - 1]++;
		m_position--;
		leftHalf = HalfCalculation(0, m_ticketHalfLength);
		rightHalf = HalfCalculation(m_ticketHalfLength, 2 * m_ticketHalfLength);
	}
	m_difference = leftHalf - rightHalf;
	DoCalculation();
}