#include "stdafx.h"
#include "CarSet.h"

const vector<int> maxSpeedInGear = { 20, 0, 30, 50, 60, 90, 150 };
const vector<int> minSpeedInGear = { 0, 0, 0, 20, 30, 40, 50 };
const int amountOfGear = 7;

bool CCarSet::IsTurnedOn()const
{
	return m_isOn;
}

bool CCarSet::TurnOn()
{
	m_isOn = true;
	return true;
}

bool CCarSet::TurnOff()
{
	if (m_currentSpeed == 0 && m_currentGear == 0)
	{
		m_isOn = false;
		return true;
	}
	return false;
}

int CCarSet::GetGear()const
{
	return m_currentGear;
}

bool CCarSet::SelectGear(int gear)
{
	bool isAvailableGear = (gear >= -1) && (gear <= 5);

	if (isAvailableGear && m_isOn)
	{
		if (gear == -1)
		{
			if (m_currentSpeed == 0)
			{
				m_currentGear = gear;
				return true;
			}
			else
				return false;
		}

		if (m_currentGear != 0 && gear == 0)
		{
			m_currentGear = gear;
			return true;
		}

		if (m_currentGear == -1)
		{
			if (m_currentSpeed == 0 && (gear == 0 || gear == 1))
			{
				m_currentGear = gear;
				return true;
			}
			else
				return false;
		}

		if (m_currentGear == 0)
			if (m_movement == "back" && (gear != 0 || gear != -1))
				return false;
			else
			{
				m_currentGear = gear;
				return true;
			}

		for (int i = -1; i < amountOfGear; i++)
		{
			if (gear == i && m_currentSpeed <= maxSpeedInGear[i + 1] && m_currentSpeed >= minSpeedInGear[i + 1])
			{
				m_currentGear = gear;
				return true;
			}
		}
	}
	return false;
}

int CCarSet::GetSpeed()const
{
	return m_currentSpeed;
}

bool CCarSet::SelectSpeed(int speed)
{
	bool isAvailableSpeed = (speed >= 0) && (speed <= 150);

	if (isAvailableSpeed && m_isOn)
	{
		for (int i = -1; i < amountOfGear; i++)
		{
			if (m_currentGear == i && speed <= maxSpeedInGear[i + 1] && speed >= minSpeedInGear[i + 1])
			{
				m_currentSpeed = speed;
				SetMovement(m_currentSpeed, m_currentGear);
				return true;
			}
		}
	}
	return false;
}

string CCarSet::GetMovement()const
{
	return m_movement;
}

bool CCarSet::SetMovement(int speed, int gear)
{
	if (m_isOn)
		if (speed == 0)
		{
			m_movement = "stay";
		}
		else
			if (gear == -1 && speed <= maxSpeedInGear[0] && speed >= minSpeedInGear[0])
			{
				m_movement = "back";
			}
			else	
				m_movement = "forward";

	return true;
}