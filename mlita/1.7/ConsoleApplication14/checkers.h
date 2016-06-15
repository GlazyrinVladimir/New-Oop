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

class CCheckers
{
public:
	void SearchMaxWay(int m[10][10], int x, int y, int &way, sf::RenderWindow &window);
	bool ReadData(int matrix[10][10], int &x, int &y);
	void FillMatrixWithZeros(int matrix[10][10]);
	void WriteMaxWay();
	std::multimap<int,int> GetBlackPosition()const;
	void LoadObjects();
	void Update(sf::RenderWindow &window, int x, int y);
private:
	int maxWay = 0;
	int whiteX;
	int whiteY;
	std::multimap<int, int> blackCheckersPosition;

	sf::Sprite fon;
	sf::Sprite blackChecker;
	sf::Sprite whiteChecker;
};