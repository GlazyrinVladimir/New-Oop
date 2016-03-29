#include "stdafx.h"
#include "Car.h"
#include "CarSet.h"
#include <boost/range/algorithm/transform.hpp>

using namespace std;
using namespace std::placeholders;

CCarControl::CCarControl(CCarSet & car, std::istream & input, std::ostream & output)
	: m_car(car)
	, m_input(input)
	, m_output(output)
	, m_actionMap({
		{ "engineon", bind(&CCarControl::TurnOnEngine, this, _1) },
		{ "engineoff", bind(&CCarControl::TurnOffEngine, this, _1) },
		{ "info", bind(&CCarControl::GetInfo, this, _1) },
		{ "setgear", bind(&CCarControl::SetGear, this, _1) },
		{ "setspeed", bind(&CCarControl::SetSpeed, this, _1)},
})
{
}

bool CCarControl::GetInfo(std::istream & args)const
{
	cout << "engine is turned ";
	if (m_car.IsTurnedOn())
		cout << "on; ";
	else cout << "off; ";

	cout << "direction of movement is " << m_car.GetMovement() << "; ";
	
	cout << "speed = " << m_car.GetSpeed() << "; ";

	cout << "gear = " << m_car.GetGear() << endl;

	return true;
}

bool CCarControl::HandleCommand()
{
	string commandLine;
	getline(m_input, commandLine);
	transform(commandLine.begin(), commandLine.end(), commandLine.begin(), tolower);
	istringstream strm(commandLine);
	string action;
	strm >> action;
	if ((action == "setspeed" || action == "setgear"))
	{
		string value;
		strm >> value;

		if (action == "setspeed")
			m_newSpeed = stoi(value);
		else
			if (action == "setgear")
				m_newGear = stoi(value);
	}
	else
		if (action == "info" || action == "engineoff" || action == "engineon");
		else
			return 0;

	auto it = m_actionMap.find(action);
	if (it != m_actionMap.end())
	{
		it->second(strm);
	}
	else 
		return false;

	return true;
}

bool CCarControl::TurnOnEngine(std::istream & args)
{
	m_car.TurnOn();
	m_output << "Engine is turned on" << endl;
	return true;
}
bool CCarControl::TurnOffEngine(std::istream & args)
{
	if (m_car.TurnOff())
		m_output << "Engine is turned off" << endl;
	else m_output << "error, lose speed and use neutral gear" << endl;
	return true;
}

bool CCarControl::SetSpeed(std::istream & args)
{
	if (m_car.SelectSpeed(m_newSpeed))
		m_output << "Speed changed" << endl;
	else 
		m_output << "error speed" << endl;
	return true;
}

bool CCarControl::SetGear(std::istream & args)
{
	
	if (m_car.SelectGear(m_newGear))
		m_output << "Gear changed" << endl;
	else
		m_output << "error gear" << endl;
	return 0;
}