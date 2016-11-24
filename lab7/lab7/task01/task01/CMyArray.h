#pragma once
#include "stdafx.h"
#include "iterator.h"

template<typename T>
class CMyArray
{
public:
	typedef MyIterator<T> iterator;
	typedef MyIterator<const T> const_iterator;

	CMyArray() = default;
	~CMyArray()
	{
		Clear();
	};

	CMyArray(std::initializer_list<T>const & values) :
		m_size(values.size()),
		m_array(std::make_unique<T[]>(values.size()))
	{
		std::copy(values.begin(), values.end(), m_array.get());
	}

	CMyArray<T> & operator=(const CMyArray<T> & arr)
	{
		Clear();
		Resize(arr.GetSize(), 0);
		memcpy(m_array.get(), arr.m_array.get(), m_size * sizeof(m_size));
		return *this;
	}

	CMyArray<T> & operator=(std::initializer_list<T> values)
	{
		Clear();
		Resize(values.size(), 0);
		std::copy(values.begin(), values.end(), m_array.get());
		return *this;
	}

	void Resize(size_t size, T item)
	{
		if (m_size > size)
		{
			m_size = size;
			return;
		}
		std::unique_ptr<T[]> buffer;
		m_array.swap(buffer);
		m_array = std::make_unique<T[]>(size);
		memcpy(m_array.get(), buffer.get(), (m_size)* sizeof(T));
		for (size_t i = m_size; i < size; ++i)
		{
			m_array[i] = item;
		}
		m_size = size;
	}

	void PushBack(T const& m_item)
	{
		try
		{
			std::unique_ptr<T[]> buffer;
			m_array.swap(buffer);
			m_array = std::make_unique<T[]>(m_size + 1);
			memcpy(m_array.get(), buffer.get(), (m_size)* sizeof(T));
			m_array[m_size] = m_item;
			m_size++;
		}
		catch (...)
		{
			Clear();
		}

	}

	bool IsEmpty() const
	{
		return m_size == 0u;
	}

	size_t GetSize() const
	{
		return m_size;
	}

	iterator begin()
	{
		return iterator(m_array.get(), false);
	}
	iterator end()
	{
		return iterator(m_array.get() + m_size, false);
	}

	const const_iterator cbegin() const
	{
		return const_iterator(m_array.get(), false);
	}
	const const_iterator cend() const
	{
		return const_iterator(m_array.get() + m_size, false);
	}

	iterator rbegin()
	{
		return iterator(m_array.get() + m_size - 1, true);
	}
	iterator rend()
	{
		return iterator(m_array.get() - 1, true);
	}

	const const_iterator crbegin() const
	{
		return const_iterator(m_array.get() + m_size - 1, true);
	}
	const const_iterator crend() const
	{
		return const_iterator(m_array.get() - 1, true);
	}

	T & operator[](size_t index)
	{
		if (index >= m_size)
		{
			throw std::out_of_range("index_not_in_range");
		}
		return m_array[index];
	}

	T const & operator[](size_t index) const
	{
		if (index >= m_size)
		{
			throw std::out_of_range("index_not_in_range");
		}
		return m_array[index];
	}

	void Clear()
	{
		m_size = 0;
		m_array.reset();
	}

private:
	size_t m_size = 0;
	std::unique_ptr<T[]> m_array;
};