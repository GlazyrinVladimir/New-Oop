#pragma once
#include <iostream>
#include <string>

using namespace std;

class CCarSet
{
public:
	bool IsTurnedOn()const;
	bool TurnOn();
	bool TurnOff();
	int GetGear()const;
	bool SelectGear(int channel);
	int GetSpeed()const;
	bool SelectSpeed(int speed);
	string GetMovement()const;
	bool SetMovement(int speed, int gear);

private:
	bool m_isOn = false;
	int m_currentGear = 0;
	int m_currentSpeed = 0;
	string m_movement = "stay";
};