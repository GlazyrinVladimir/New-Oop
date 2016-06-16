#include "checkers.h"

using namespace std;
using namespace sf;

CCheckers::CCheckers(std::string fonImage, std::string blackImage, std::string whiteImage)
{
	sf::RenderWindow window(sf::VideoMode(640, 640), "RGR MLITA");
	Texture fonTexture;
	fonTexture.loadFromFile(fonImage);
	fon.setTexture(fonTexture);
	Texture blackCheckerTexture;
	blackCheckerTexture.loadFromFile(blackImage);
	blackChecker.setTexture(blackCheckerTexture);
	Texture whiteCheckerTexture;
	whiteCheckerTexture.loadFromFile(whiteImage);
	whiteChecker.setTexture(whiteCheckerTexture);

	blackChecker.setScale(2.0f, 2.0f);
	whiteChecker.setScale(2.0f, 2.0f);
	
	FillMatrixWithZeros();
	ReadData();
	SearchMaxWay(window);
	WriteMaxWay();
}



void CCheckers::FillMatrixWithZeros()
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			m_matrix[i][j] = WALL;
}

std::multimap<int, int> CCheckers::GetBlackPosition()const
{
	return blackCheckersPosition;
}

void CCheckers::WriteMaxWay()
{
	ofstream outputFile("output.txt");
	outputFile << m_maxWay << endl;

}

void CCheckers::Update(sf::RenderWindow &window)
{
	window.clear();

	whiteChecker.setPosition(float((whiteX - 1) * 80), float((whiteY - 1) * 80));

	while (updateTimer < TIMETOUPDATETIMER)
	{
		updateTimer += 0.00025;
	}
	updateTimer = 0;
	window.draw(fon);

	for (auto it = blackCheckersPosition.begin(); it != blackCheckersPosition.end(); ++it)
	{
		
		blackChecker.setPosition(float(80 * (it->second - 1)),float(80 * (it->first - 1)));
		window.draw(blackChecker);
	}
	window.draw(whiteChecker);
	window.display();
}

bool CCheckers::ReadData()
{
	ifstream inputFile("test.txt");
	if (inputFile.is_open())
	{
		char storage;
		for (int i = 1; i < 9; i++)
		{
			for (int j = 1; j < 9; j++)
			{
				inputFile >> storage;
				if (storage == '1')
				{
					m_matrix[i][j] = 1;
					blackCheckersPosition.insert(pair<int, int>(i, j));
				}
				if (storage == '2')
				{
					m_matrix[i][j] = 0;
					whiteY = i;
					whiteX = j;
				}
				if (storage == '0')
				{
					m_matrix[i][j] = 0;
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

void CCheckers::DoNextStep(sf::RenderWindow &window, int x, int y)
{
	m_currentWay += 1;
	m_matrix[whiteY + y][whiteX + x] = 0;
	whiteX += 2 * x;
	whiteY += 2 * y;
	SearchMaxWay(window);
	whiteX += -2 * x;
	whiteY += -2 * y;
	m_matrix[whiteY + y][whiteX + x] = 1;
	m_currentWay -= 1;
	Update(window);
}

void CCheckers::SearchMaxWay(sf::RenderWindow &window)
{
	Update(window);
	if (m_currentWay > m_maxWay) m_maxWay = m_currentWay;
	{
		if (m_matrix[whiteY - 1][whiteX + 1] != WALL)
			if (m_matrix[whiteY - 1][whiteX + 1] == 1 && m_matrix[whiteY - 2][whiteX + 2] == 0)
			{
				DoNextStep(window, 1, -1);
			}
	}
	if (m_matrix[whiteY + 1][whiteX + 1] != WALL)
	{
		if (m_matrix[whiteY + 1][whiteX + 1] == 1 && m_matrix[whiteY + 2][whiteX + 2] == 0)
		{
			DoNextStep(window, 1, 1);
		}
	}
	if (m_matrix[whiteY + 1][whiteX - 1] != WALL)
	{
		if (m_matrix[whiteY + 1][whiteX - 1] == 1 && m_matrix[whiteY + 2][whiteX - 2] == 0)
		{
			DoNextStep(window, -1, 1);
		}
	}

	if (m_matrix[whiteY - 1][whiteX - 1] != WALL)
	{
		if (m_matrix[whiteY - 1][whiteX - 1] == 1 && m_matrix[whiteY - 2][whiteX - 2] == 0)
		{
			DoNextStep(window, -1, -1);
		}
	}
}