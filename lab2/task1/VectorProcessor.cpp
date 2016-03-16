#include "stdafx.h"
#include "VectorProcessor.h"
#include <algorithm>
#include <numeric>
#include <functional>
#include <boost/range/algorithm/transform.hpp>
#pragma warning (push, 3)
#include <boost/phoenix.hpp>
#pragma warning (pop)

using namespace std;
using namespace std::placeholders;
using namespace boost::phoenix::placeholders;
using namespace boost::phoenix;
using boost::transform;

void Sort(std::vector<double> & numbers)
{
	std::sort(numbers.begin(), numbers.end());
}

void ProcessVector(std::vector<double> & numbers)
{
	if (numbers.size())
	{
		double minElem = numbers[0];

		auto addIfTheMostMinElem = [&minElem](double acc, double current)
		{
			if (minElem > current)
			{
				minElem = current;
			}
			return 0;
		};

		accumulate(numbers.begin(), numbers.end(), 0.0, addIfTheMostMinElem);

		boost::transform(numbers, numbers.begin(), arg1 * minElem);
	}
}