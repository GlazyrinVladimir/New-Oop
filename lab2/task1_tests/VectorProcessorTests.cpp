#include "stdafx.h"
#include "..\task1\VectorProcessor.h"

using namespace std;

bool VectorsAreEqual(vector<double> const& x, vector<double> const& y)
{
	return x == y;
}

// Функция ProcessVector
BOOST_AUTO_TEST_SUITE(ProcessVector_function)

	// Создает пустой вектор из пустого вектора
	BOOST_AUTO_TEST_CASE(makes_empty_vector_from_empty_vector)
	{
		vector<double> emptyVector;
		ProcessVector(emptyVector);
		BOOST_CHECK(emptyVector.empty());
	}

	// при обработке вектора с несколькими одинаковыми элементами
	BOOST_AUTO_TEST_CASE(processing_a_vector_with_several_elements)
	{
		vector<double> numbers = { 2, 2, 2 };
		const double minElem = 2;
		ProcessVector(numbers);
		BOOST_CHECK(VectorsAreEqual(numbers,
		{ (2 * minElem), (2 * minElem), (2 * minElem) }
		));
	}

	// при обработке вектора с одним отрицательным
	BOOST_AUTO_TEST_SUITE(when_processing_a_vector_with_one_negative_number)
		// должен умножить на это число каждый элемент вектора
		BOOST_AUTO_TEST_CASE(should_multiply_this_number_to_each_element)
		{
			vector<double> numbers = { -1, 3.5, 4 };
			ProcessVector(numbers);

			BOOST_CHECK(VectorsAreEqual( numbers, 
				{ (-1 * -1), (3.5 * -1), (4 * -1)}
			));
		}
	BOOST_AUTO_TEST_SUITE_END()

	// 
	BOOST_AUTO_TEST_SUITE(when_processing_a_vector_with_only_positive_elements)
		// должен умножить на минимальное число каждый элемент вектора
		BOOST_AUTO_TEST_CASE(should_multiply_min_number_to_each_element)
		{
			vector<double> numbers = { 4, 1, 2, 3 };
			ProcessVector(numbers);
			const double minElem = 1;

			BOOST_CHECK(VectorsAreEqual(numbers,
			{ (4 * minElem), (1 * minElem), (2 * minElem), (3 * minElem) }
			));
		}
	BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()


