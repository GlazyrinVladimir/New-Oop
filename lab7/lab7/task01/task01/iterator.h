#pragma once
#include "stdafx.h"
#include <iterator>

template<typename T>
class CMyArray;

template<typename ValueType>
class MyIterator : public std::iterator<std::random_access_iterator_tag, ValueType>
{
	template<typename T>
	friend class CMyArray;

public:
	MyIterator(ValueType* m_item, bool isReverse) :
		m_item(m_item),
		m_isReverse(isReverse)
	{

	}
	MyIterator(const MyIterator &it, bool isReverse) :
		m_item(it.m_item),
		m_isReverse(isReverse)
	{

	}

	bool operator!=(MyIterator const& other) const
	{
		return m_item != other.m_item;
	}
	bool operator==(MyIterator const& other) const
	{
		return m_item == other.m_item;
	}
	ValueType operator*() const
	{
		return *m_item;
	}
	MyIterator & operator++(int)
	{
		if (m_isReverse)
		{
			m_item--;		
		}
		else
		{
			m_item++;
		}
		return *this;
	}
private:
	ValueType* m_item;
	bool m_isReverse;
};