#include "stdafx.h"
#include "timber.h"

using namespace std;

size_t CTimber::GetCost()const
{
	return m_cost;
}

void CTimber::CutTimber(unsigned timberLen, unsigned numberOfCuts)
{
	if (numberOfCuts > 0 || timberLen < numberOfCuts)
	{
		m_cost = timberLen;
		size_t place;

		if (timberLen / 2 > numberOfCuts)
		{
			if (numberOfCuts > 1)
				m_cuts.push_back(numberOfCuts);
			if ((timberLen - numberOfCuts) > 1)
				m_cuts.push_back(timberLen - numberOfCuts);

		}
		else
		{
			int firstHalfOfCut = timberLen / 2;		
			int secondHalfOfCut = timberLen - firstHalfOfCut;

			if (firstHalfOfCut > 1)
				m_cuts.push_back(firstHalfOfCut);
			if ((secondHalfOfCut) > 1)
				m_cuts.push_back(secondHalfOfCut);

			if (firstHalfOfCut > secondHalfOfCut)
			{
	
				int x = secondHalfOfCut / 2;
				int y = secondHalfOfCut - x;
				m_cuts.push_back(x);
				m_cuts.push_back(y);
			}
			else
			{
				int x = firstHalfOfCut / 2;
				int y = firstHalfOfCut - x;
				m_cuts.push_back(x);
				m_cuts.push_back(y);

			}

		}
		std::sort(m_cuts.begin(), m_cuts.end());

		/*for (size_t i = 0; i < m_cuts.size(); i++)
			cout << m_cuts[i] << endl;*/

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
			place = m_cuts.size();
			std::sort(m_cuts.begin(), m_cuts.end());

		}
	}
}