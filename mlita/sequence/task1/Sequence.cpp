#include "stdafx.h"
#include "Sequence.h"

using namespace std;

bool CSequence::ReadSequence(std::string const & name)
{
	ifstream inputFile(name);
	if (inputFile.is_open())
	{
		size_t amountOfNumbers;
		inputFile >> amountOfNumbers;

		if (amountOfNumbers > LEFT_BORDER && amountOfNumbers < RIGHT_BORDER)
		{
			for (size_t i = 0; i < amountOfNumbers; i++)
			{
				size_t storage;
				inputFile >> storage;
				m_numbers.push_back(storage);
			}

			sort(m_numbers.begin(), m_numbers.end());
			return true;
		}
	}
	return false;
}

void CSequence::CalculationSequence()
{
	for (size_t i = 2; i < m_numbers.size(); i++)
	{
		for (size_t firstNumber = 0; firstNumber < i - 1; firstNumber++)
		{
			for (size_t secondNumber = firstNumber + 1; secondNumber < i; secondNumber++)
			{
				if (m_numbers[firstNumber] + m_numbers[secondNumber] == m_numbers[i])
				{
					m_count++;
				}
			}
		}
	}
}

int CSequence::GetCount()const
{
	return m_count;
}