#include "stdafx.h"
#include "Student.h"
#include <stdexcept>
#include <string>
#include <sstream>
#include <boost/format.hpp>
#include <math.h>
#include <limits>

using namespace std;

string ConvertIntToString(const int & value)
{
	std::ostringstream age;
	age << value;
	return age.str();
}

namespace
{
	const int & AssureCorrectNumber(const int & value, const string & argName = string())
	{		
		int *badAllocControl;
		badAllocControl = new int[value];
		delete[] badAllocControl;
		if (value >= 14 && value <= 60)
		{
			return value;
		}
		throw std::out_of_range(ConvertIntToString(value) + " is not included in the range.");
	}
}

namespace
{
	const std::string & AssureNotContainInvalidSymbols(const std::string & value, const string & argName = string())
	{
		string *badAllocControl;
		badAllocControl = new string[value.size()];
		delete[] badAllocControl;
		if (value.empty())
		{
			if (argName != "patronymic")
			{
				throw invalid_argument(argName + " is empty.");
			}
		}

		for (size_t i = 0; i < value.length(); i++)
		{
			char symbol[1];
			symbol[0] = value[i];
			if (atoi(symbol) || symbol[0] == ' ')
			{
				throw invalid_argument(argName + " is contained invalid symbols.");
			}
		}
		return value;
	}
}

CStudent::CStudent(std::string name, std::string surname, std::string patronymic, int age)
	: m_name(AssureNotContainInvalidSymbols(name, "name"))
	, m_surname(AssureNotContainInvalidSymbols(surname, "surname"))
	, m_patronymic(AssureNotContainInvalidSymbols(patronymic, "patronymic"))
	, m_age(AssureCorrectNumber(age, "age"))
{
}

void CStudent::Rename(std::string name, std::string surname, std::string patronymic)
{
	AssureNotContainInvalidSymbols(name, "name");
	AssureNotContainInvalidSymbols(surname, "surname");
	AssureNotContainInvalidSymbols(patronymic, "patronymic");
	m_name = name;
	m_surname = surname;
	m_patronymic = patronymic;
}

void CStudent::SetAge(int const & newAge)
{
	AssureCorrectNumber(newAge);
	if (newAge > m_age)
	{
		m_age = newAge;
	}
	else
	{
		throw std::domain_error(ConvertIntToString(newAge) + " is less than current age");
	}
}

std::string CStudent::GetName()const
{
	return m_name;
}
std::string CStudent::GetSurname()const
{
	return m_surname;
}
std::string CStudent::GetPatronymic()const
{
	return m_patronymic;
}

int CStudent::GetAge()const
{
	return m_age;
}