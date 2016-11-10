// FindMaxEx.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "FindMaxEx.h"

using namespace std;

struct Athlete
{
	string name;
	string surname;
	string middleName;
	double weight;
	double growth;
};

void PrintExampleInput()
{
	std::cout << "input parameters of athlete (firstName SecondName weight growth)" << std::endl;
	std::cout << "Vasya Pupkin 70 170" << std::endl;
}

void PrintInfoAboutAthlete(Athlete const & athlete)
{
	cout << "Name " << athlete.name << endl;
	cout << "Middle name " << athlete.middleName << endl;
	cout << "Surname " << athlete.surname << endl;
	cout << "Weight" << athlete.weight << endl;
	cout << "Growth " << athlete.growth << endl;;
}

Athlete SetAthlete(string const & str)
{
	istringstream strm(str);
	Athlete athlete;

	strm >> athlete.name;
	strm >> athlete.middleName;
	strm >> athlete.surname;
	strm >> athlete.weight;
	strm >> athlete.growth;
	return athlete;
}

int main()
{
	PrintExampleInput();
	vector<Athlete> athletes;
	string inputStr;
	while (getline(cin, inputStr) && inputStr != "0")
	{
		athletes.push_back(SetAthlete(inputStr));
	}

	Athlete athleteWithMaxWeight;

	if (FindMax(athletes, athleteWithMaxWeight, [](Athlete const & first, Athlete const & second) {
		return first.weight < second.weight;
	}))
	{
		PrintInfoAboutAthlete(athleteWithMaxWeight);
	}

	Athlete athleteWithMaxGrowth;
	if (FindMax(athletes, athleteWithMaxGrowth, [](Athlete const & first, Athlete const & second) {
		return first.growth < second.growth;
	}))
	{
		PrintInfoAboutAthlete(athleteWithMaxGrowth);
	}
    return 0;
}

