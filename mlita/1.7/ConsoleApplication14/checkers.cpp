#include "checkers.h"

using namespace std;
using namespace sf;

void CCheckers::FillMatrixWithZeros(int matrix[10][10])
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			matrix[i][j] = 5;
}

std::multimap<int, int> CCheckers::GetBlackPosition()const
{
	return blackCheckersPosition;
}

void CCheckers::WriteMaxWay()
{
	ofstream outputFile("output.txt");
	outputFile << maxWay << endl;
}

void CCheckers::LoadObjects()
{
	Image fonImage;
	fonImage.loadFromFile("files/fon.png");
	Texture fontexture;
	fontexture.loadFromImage(fonImage);
	fon.setTexture(fontexture);

	Image blackCheckImage;
	blackCheckImage.loadFromFile("files/black.png");
	Texture blackCheckTexture;
	blackCheckTexture.loadFromImage(blackCheckImage);
	blackChecker.setTexture(blackCheckTexture);
	blackChecker.setScale(2.0f, 2.0f);

	Image whiteCheckImage;
	whiteCheckImage.loadFromFile("files/white.png");
	Texture whiteCheckTexture;
	whiteCheckTexture.loadFromImage(whiteCheckImage);
	whiteChecker.setTexture(whiteCheckTexture);
}

void CCheckers::Update(sf::RenderWindow &window, int x, int y)
{
	window.clear();
	Image fonImage;
	fonImage.loadFromFile("files/fon.png");
	Texture fontexture;
	fontexture.loadFromImage(fonImage);
	fon.setTexture(fontexture);

	Image blackCheckImage;
	blackCheckImage.loadFromFile("files/black.png");
	Texture blackCheckTexture;
	blackCheckTexture.loadFromImage(blackCheckImage);
	blackChecker.setTexture(blackCheckTexture);
	blackChecker.setScale(2.0f, 2.0f);

	Image whiteCheckImage;
	whiteCheckImage.loadFromFile("files/white.png");
	Texture whiteCheckTexture;
	whiteCheckTexture.loadFromImage(whiteCheckImage);
	whiteChecker.setScale(2.0f, 2.0f);
	whiteChecker.setTexture(whiteCheckTexture);
	whiteChecker.setPosition((x - 1) * 80, (y - 1) * 80);
	double time = 0;
	while (time < 10000)
	{
		time += 0.00025;
	}
	window.draw(fon);
	for (auto it = blackCheckersPosition.begin(); it != blackCheckersPosition.end(); ++it)
	{
		
		blackChecker.setPosition(80 * (it->second - 1), 80 * (it->first - 1));
		window.draw(blackChecker);
	}
	window.draw(whiteChecker);
	window.display();
}

bool CCheckers::ReadData(int matrix[10][10], int &x, int &y)
{
	ifstream inputFile("input.txt");
	if (inputFile.is_open())
	{
		LoadObjects();
		char storage;
		for (int i = 1; i < 9; i++)
		{
			for (int j = 1; j < 9; j++)
			{
				inputFile >> storage;
				if (storage == '1')
				{
					matrix[i][j] = 1;			
					blackCheckersPosition.insert(pair<int, int>(i, j));
				}
				if (storage == '2')
				{
					matrix[i][j] = 0;
					y = i;
					x = j;
				}
				if (storage == '0')
				{
					matrix[i][j] = 0;
				}
			}
		}
	}
	else 
	{
		return false;
	} 
	return true;
}

void CCheckers::SearchMaxWay(int m[10][10], int x, int y, int &way, sf::RenderWindow &window)
{
	Update(window, x, y);
	if (way > maxWay) maxWay = way;

	if (m[y - 1][x + 1] != 5)
		if (m[y - 1][x + 1] == 1 && m[y - 2][x + 2] == 0)
		{
			way += 1;
			m[y - 1][x + 1] = 0;
			SearchMaxWay(m, x + 2, y - 2, way, window);
			m[y - 1][x + 1] = 1;
			way -= 1;
		}
	Update(window, x, y);
	if (m[y + 1][x + 1] != 5)
		if (m[y + 1][x + 1] == 1 && m[y + 2][x + 2] == 0)
		{
			way += 1;
			m[y + 1][x + 1] = 0;
			SearchMaxWay(m, x + 2, y + 2, way, window);
			m[y + 1][x + 1] = 1;
			way -= 1;
		}
	Update(window, x, y);
	if (m[y + 1][x - 1] != 5)
		if (m[y + 1][x - 1] == 1 && m[y + 2][x - 2] == 0)
		{
			way += 1;
			m[y + 1][x - 1] = 0;
			SearchMaxWay(m, x - 2, y + 2, way, window);
			m[y + 1][x - 1] = 1;
			way -= 1;
		}
	Update(window, x, y);
	if (m[y - 1][x - 1] != 5)                                    
		if (m[y - 1][x - 1] == 1 && m[y - 2][x - 2] == 0)
		{
			way += 1;
			m[y - 1][x - 1] = 0;
			SearchMaxWay(m, x - 2, y - 2, way, window);
			way -= 1;
			m[y - 1][x - 1] = 1;
		}
	Update(window, x, y);
}