#pragma once
#include "stdafx.h"

struct Athlete
{
	std::string name;
	std::string surname;
	std::string middleName;
	double weight;
	double growth;
};
 
Athlete SetAthlete(std::string const & str)
{
	std::istringstream strm(str);
	Athlete athlete;
	strm >> athlete.name;
	strm >> athlete.middleName;
	strm >> athlete.surname;
	strm >> athlete.weight;
	strm >> athlete.growth;
	return athlete;
}

template<typename T, typename Less>
bool FindMax(std::vector<T>const & arr, T & maxValue, Less const &less)
{
	if (arr.empty())
	{
		return false;
	}
	size_t maxValueIndex = 0;
	for (size_t i = 1u; i < arr.size(); ++i)
	{
		if (less(arr[maxValueIndex], arr[i]))
		{
			maxValueIndex = i;
		}
	}
	maxValue = arr[maxValueIndex];

	return true;
}