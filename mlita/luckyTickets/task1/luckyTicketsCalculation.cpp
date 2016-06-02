#include "stdafx.h"
#include "luckyTicketsCalculation.h"

using namespace std;

bool luckyTicketsCalculation::GetTicketNumber(std::string name)
{
	ifstream inputFile(name);
	if (inputFile.is_open())
	{
		string ticketNumber;
		inputFile >> ticketHalfLength;
		inputFile >> ticketNumber;

		if (ticketNumber.empty())
		{
			return false;
		}

		for (size_t i = 0; i < 2 * ticketHalfLength; i++)
		{
			char numeral = ticketNumber[i];
			ticket.push_back(numeral - 48);
		}
		return true;
	}
	else return false;
}

size_t luckyTicketsCalculation::HalfCalculation(size_t start, size_t finish)
{
	size_t count = 0;
	for (size_t i = start; i < finish; i++)
	{
		count += ticket[i];
	}
	return count;
}

size_t luckyTicketsCalculation::GetMinNumberOfNextTickets()
{
	position = ticket.size() - 1;
	size_t leftHalf = HalfCalculation(0, ticketHalfLength);
	size_t rightHalf = HalfCalculation(ticketHalfLength, 2 * ticketHalfLength);
	size_t count = 0;
	while (leftHalf != rightHalf)
	{
		count++;
		ticket[position] += 1;

		while (ticket[position] == 10)
		{
			ticket[position] = 0;
			position--;
			ticket[position]++;

			if (ticket[0] > 9)
			{
				ticket[0] = ticket[0] % 10;
			}
		}
		position = ticket.size() - 1;

		leftHalf = HalfCalculation(0, ticketHalfLength);
		rightHalf = HalfCalculation(ticketHalfLength, 2 * ticketHalfLength);
	}

	return count;
}