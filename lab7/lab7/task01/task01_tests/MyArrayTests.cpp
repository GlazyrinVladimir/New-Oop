#include "stdafx.h"
#include "../task01/CMyArray.h"

struct EmptyArray
{
	CMyArray<int> arr;
};

template<typename T>
void VerifyArray(CMyArray<T> & arr1, std::vector<T> & expectedNumbers)
{
	size_t counter = 0;
	for (auto it = arr1.begin(); it != arr1.end(); it++)
	{
		BOOST_CHECK_EQUAL(*it, expectedNumbers[counter]);
		counter++;
	}
}

BOOST_FIXTURE_TEST_SUITE(MyArray_, EmptyArray)
	BOOST_AUTO_TEST_SUITE(when_created)
		BOOST_AUTO_TEST_CASE(is_empty)
		{
			BOOST_CHECK(arr.IsEmpty());
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(after_push_back_a_number)
		BOOST_AUTO_TEST_CASE(increases_its_size_by_1)
		{
			std::vector<int> numbers;
			auto oldSize = arr.GetSize();
			arr.PushBack(1);
			numbers.push_back(1);
			BOOST_CHECK_EQUAL(arr.GetSize(), oldSize + 1);
			VerifyArray(arr, numbers);
			arr.PushBack(2);
			numbers.push_back(2);
			BOOST_CHECK_EQUAL(arr.GetSize(), oldSize + 2);
			VerifyArray(arr, numbers);
		}

	BOOST_AUTO_TEST_SUITE_END()

	struct when_not_empty : EmptyArray
	{
		when_not_empty()
		{
			arr.PushBack(1);
			arr.PushBack(2);
			arr.PushBack(3);
		}

		std::vector<int> expectedArr = { 1, 2, 3};
	};

	BOOST_FIXTURE_TEST_SUITE(when_not_empty_, when_not_empty)

		BOOST_AUTO_TEST_CASE(can_be_cleared)
	{
		BOOST_CHECK(!arr.IsEmpty());
		arr.Clear();
		BOOST_CHECK(arr.IsEmpty());
	}

	BOOST_AUTO_TEST_CASE(have_iterators_and_const_iterators_at_begin_and_end_of_array)
	{
		size_t counter = 0;
		for (auto it = arr.begin(); it != arr.end(); it++)
		{
			BOOST_CHECK_EQUAL(*it, expectedArr[counter]);
			counter++;
		}

		counter = 0;
		for (auto it = arr.cbegin(); it != arr.cend(); it++)
		{
			BOOST_CHECK_EQUAL(*it, expectedArr[counter]);
			counter++;
		}
	}

	BOOST_AUTO_TEST_CASE(have_reverse_iterators_and_const_revers_iterators_at_begin_and_end_of_array)
	{
		size_t counter = expectedArr.size() - 1;
		for (auto it = arr.rbegin(); it != arr.rend(); it++)
		{
			BOOST_CHECK_EQUAL(*it, expectedArr[counter]);
			counter--;
		}

		counter = expectedArr.size() - 1;
		for (auto it = arr.crbegin(); it != arr.crend(); it++)
		{
			BOOST_CHECK_EQUAL(*it, expectedArr[counter]);
			counter--;
		}
	}

	BOOST_AUTO_TEST_CASE(have_indexed_access_to_the_array_elements)
	{
		BOOST_CHECK_EQUAL(arr[0], expectedArr[0]);
		BOOST_CHECK_EQUAL(arr[1], expectedArr[1]);
		BOOST_CHECK_EQUAL(arr[2], expectedArr[2]);
	}

	BOOST_AUTO_TEST_CASE(throw_with_index_more_array_size)
	{
		BOOST_REQUIRE_THROW(arr[5], std::out_of_range);
	}

	BOOST_AUTO_TEST_CASE(can_use_operator_equality)
	{
		CMyArray<int> arr2;
		std::vector<int> numbers = { 1,2,3 };
		arr2 = arr;
		VerifyArray(arr2, numbers);
		arr2.Clear();
		BOOST_CHECK(arr2.IsEmpty());
		arr2 = { 1,5,8 };
		std::vector<int> numbers2 = { 1,5,8 };
		VerifyArray(arr2, numbers2);
	}

	BOOST_AUTO_TEST_CASE(testing_copy_operator)
	{
		CMyArray<int> arr2;
		std::vector<int> numbers = { 1,2,3 };
		arr2 = arr;
		VerifyArray(arr2, numbers);
		arr2.Clear();
		BOOST_CHECK(arr2.IsEmpty());
		arr2 = { 1,5,8 };
		std::vector<int> numbers2 = { 1,5,8 };
		VerifyArray(arr2, numbers2);
	}

	BOOST_AUTO_TEST_CASE(resize_array_with_start_item)
	{
		arr = { 1,2,3,4,5 };
		std::vector<int> numbers = { 1,2,3,4,5,0,0,0,0,0 };
		arr.Resize(10, 0);
		BOOST_CHECK_EQUAL(arr.GetSize(), 10);
		VerifyArray(arr, numbers);
		arr.Resize(2, 0);
		std::vector<int> numbers2 = { 1,2 };
		VerifyArray(arr, numbers2);	
	}

	BOOST_AUTO_TEST_CASE(can_create_string_array)
	{
		CMyArray<std::string> arr2 = { "vo", "lo", "dya" };
		std::vector<std::string> line = { "vo", "lo", "dya" };
		VerifyArray(arr2, line);
	}

	BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()