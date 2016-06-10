#pragma once

#include "stdafx.h"
const unsigned int LEFT_BORDER = 3;
const unsigned int RIGHT_BORDER = 2001;

class CSequence
{
public:
	bool ReadSequence(std::string const & name);
	void CalculationSequence();
	int GetCount()const;
private:
	std::vector<unsigned int> m_numbers;
	size_t m_count = 0;
};
