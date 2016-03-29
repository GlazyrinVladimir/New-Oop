#pragma once
#include <string>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <functional>
#include <vector>
#include <boost/range/algorithm/transform.hpp>
#pragma warning (push, 3)
#include <boost/phoenix.hpp>
#pragma warning (pop)
#include <boost/algorithm/string.hpp>
#include <map>
#include <boost/noncopyable.hpp>
#include <fstream>
#include "CarSet.h"

using namespace std;


class CCarControl : boost::noncopyable
{
public:
	CCarControl(CCarSet & m_car, std::istream & input, std::ostream & output);
	bool HandleCommand();
	
private: 
	bool TurnOnEngine(std::istream & args);
	bool TurnOffEngine(std::istream & args);
	bool SetGear(std::istream & args);
	bool SetSpeed(std::istream & args);
	bool GetInfo(std::istream & input)const;

private:
	typedef std::map<std::string, std::function<bool(std::istream & args)>> ActionMap;

	int m_newSpeed;
	int m_newGear;

	CCarSet m_car;
	std::istream & m_input;
	std::ostream & m_output;

	const ActionMap m_actionMap;

};
