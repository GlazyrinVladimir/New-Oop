#pragma once
#include "stdafx.h"

const unsigned int WALL = 5;
const unsigned int TIMETOUPDATETIMER = 40000;
const unsigned int RESOLUTIONOFSCREEN = 640;
const unsigned int NUMBEROFSERIES = 8;

class CCheckers
{
public:
	CCheckers(std::string fonImage, std::string blackImage, std::string whiteImage);

	void SearchMaxWay(sf::RenderWindow &window, sf::Text  text);
	bool ReadData();
	void FillMatrixWithZeros();
	void WriteMaxWay();
	void Update(sf::RenderWindow &window, sf::Text text);
private:
	void DoNextStep(sf::RenderWindow &window, int x, int y, sf::Text text);
	int m_maxWay = 0;
	int m_currentWay = 0;
	int m_matrix[10][10];
	int whiteX;
	int whiteY;
	double updateTimer = 0;
	std::multimap<int, int> blackCheckersPosition;

	sf::Sprite fon;
	sf::Sprite blackChecker;
	sf::Sprite whiteChecker;
};