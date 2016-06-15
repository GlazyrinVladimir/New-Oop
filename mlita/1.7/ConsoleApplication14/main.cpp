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
#include "checkers.h"

using namespace sf;
using namespace std;

int main()
{
	CCheckers checker;
	sf::RenderWindow window(sf::VideoMode(640, 640), "RGR MLITA");
	int matrix[10][10];
	int x, y;
	int way = 0;

	checker.FillMatrixWithZeros(matrix);
	checker.ReadData(matrix, x, y);
	
	checker.SearchMaxWay(matrix, x, y, way, window);
	checker.WriteMaxWay();
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
	}
}