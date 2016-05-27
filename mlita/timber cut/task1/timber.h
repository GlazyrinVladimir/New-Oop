#pragma once
#include "stdafx.h"

class CTimber
{
public:
	void CutTimber(unsigned timberLen, unsigned numberOfCuts);
	size_t GetCost()const;
private:
	std::vector<int> m_cuts;
	size_t m_cost = 0;
};