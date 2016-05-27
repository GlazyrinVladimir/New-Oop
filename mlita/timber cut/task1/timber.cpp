#include "stdafx.h"
#include "timber.h"

using namespace std;

size_t CTimber::GetCost()const
{
	return m_cost;
}

void CTimber::CutTimber(unsigned timberLen, unsigned numberOfCuts)
{
	if (numberOfCuts > 0 || timberLen<numberOfCuts)
	{
		m_cost = timberLen;
		m_cuts.push_back(numberOfCuts);
		m_cuts.push_back(timberLen - numberOfCuts);
		std::sort(m_cuts.begin(), m_cuts.end());

		for (size_t i = 0; i < numberOfCuts - 1; i++)
		{
			int firstHalfOfCut = m_cuts[0] / 2;
			int secondHalfOfCut = m_cuts[0] - firstHalfOfCut;

			m_cost += m_cuts[0];
			m_cuts.erase(m_cuts.begin());

			if (firstHalfOfCut != 1)
			{
				m_cuts.push_back(firstHalfOfCut);
			}

			if (secondHalfOfCut != 1)
			{
				m_cuts.push_back(secondHalfOfCut);
			}
			std::sort(m_cuts.begin(), m_cuts.end());

		}
	}
}