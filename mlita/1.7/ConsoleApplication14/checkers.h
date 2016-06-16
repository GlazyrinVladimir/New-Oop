#pragma once
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <cassert>
#include <cstdint>
#include <winsock.h>
#include <cstring>
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <vector>
#include <list>
#include <SFML/Graphics.hpp>
#include <map>

const unsigned int WALL = 5;
const unsigned int TIMETOUPDATETIMER = 30000;
class CCheckers
{
public:
	CCheckers(std::string fonImage, std::string blackImage, std::string whiteImage);

	void SearchMaxWay(sf::RenderWindow &window);
	bool ReadData();
	void FillMatrixWithZeros();
	void WriteMaxWay();
	std::multimap<int,int> GetBlackPosition()const;
	void Update(sf::RenderWindow &window);
private:
	void DoNextStep(sf::RenderWindow &window, int x, int y);
	
	int m_maxWay = 0;
	int m_currentWay;
	int m_matrix[10][10];
	int whiteX;
	int whiteY;
	double updateTimer = 0;
	std::multimap<int, int> blackCheckersPosition;

	sf::Sprite fon;
	sf::Sprite blackChecker;
	sf::Sprite whiteChecker;
};