#pragma once
#include "stdafx.h"


template<typename T>
T ArraySum(std::vector<T> const &arr) 
{
	try
	{
		T arraySum = T();
		for (auto it : arr)
		{
			arraySum += it;
		}
		return arraySum;
	}
	catch (std::exception const &e)
	{
		std::cout << e.what() << std::endl;
	}
}