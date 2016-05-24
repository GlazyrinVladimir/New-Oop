#pragma once
#include "stdafx.h"


template<typename T>
T ArraySum(std::vector<T> const &arr)
{
	T arraySum = T();
	for (auto it : arr)
	{
		arraySum += it;
	}
	return arraySum;
}