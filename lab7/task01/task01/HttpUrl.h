#pragma once

#include <new>
#include <algorithm>
#include <stdexcept>
#include <memory.h>
#include <memory>

/*template <typename T>
class CMyIterator : public std::iterator<std::input_iterator_tag, T>
{
	friend class CMyArray;
private:
	CMyIterator(T* p)
		:p(p)
	{}
public:
/*	CMyIterator(const CMyIterator &it)
		:p(it.p)
	{}

	T & GetData()
	{
		return *p;
	}
	const T & GetData() const
	{
		return *p;
	}
	bool operator!=(CMyIterator const& other) const
	{
		return p != other.p;
	}
	bool operator==(CMyIterator const& other) const
	{
		return p == other.p;
	}

	typename CMyIterator::reference operator*() const
	{
		return *p;
	}
	CMyIterator& operator++()
	{
		++p;
		return *this;
	}

	T & begin() const
	{
		return m_array[0];
	}

private:
	T* p;
};*/

template <typename T>
class CMyArray
{
public:
/*	typedef CMyIterator<T> iterator;
	typedef CMyIterator<const T> const_iterator;
	*/


	CMyArray() 
	{ 
	}

	CMyArray(CMyArray<T> && arr) :
		m_size(arr.m_size)
	{
		m_array.swap(arr.m_array);
	}

	CMyArray(std::initializer_list<T> values) :
		m_size(values.size()),
		m_array(std::make_unique<T[]>(m_size))
	{
		std::copy(values.begin(), values.end(), m_array.get());

	}

	//~CMyArray() {  }

	size_t GetSize() const
	{
		return m_size;
	}

	void PushBack(T const& item) 
	{ 
		std::unique_ptr<T[]> buffer;

		m_array.swap(buffer);
		m_array = std::make_unique<T[]>(m_size+1);
		memcpy(m_array.get(), buffer.get(), (m_size) * sizeof(T));
		m_array[m_size] = item;
		++m_size;
	}

	void PushFront(T const& item)
	{
		std::unique_ptr<T[]> buffer;
		m_array.swap(buffer);
		m_array = std::make_unique<T[]>(m_size+1);
		memcpy(m_array.get()+1, buffer.get(), (m_size)* sizeof(T));
		m_array[0] = item;
		++m_size;
	}

	T & operator[](size_t index) const
	{
		if (index >= m_size)
		{
			throw std::out_of_range("index_not_in_range");
		}
		return m_array[index];
	}

	void Clear()
	{
		m_array.reset();
		m_size = 0;
	}

	CMyArray<T> & operator=(const CMyArray<T> & arr)
	{	
		Clear();
		Resize(arr.GetSize());
		memcpy(arr.m_array.get(), m_array.get(), m_size * sizeof(m_size));
	//	memcpy(m_array.get(), arr.m_array.get(), m_size * sizeof(m_size));
		return *this;
	}

	void Resize(unsigned newSize) { }

	CMyArray(CMyArray const&) 
	{ 
	}
	
/*	CMyArray<T> operator=(CArray const& arr) 	
	{
		std::copy(arr.begin(), arr.end(), m_array.get());
	}*/
private:
	size_t m_size = 0;
	const size_t m_size_it = 0;
	std::unique_ptr<T[]> m_array;
};


