// task1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "timber.h"

using namespace std;

int _tmain()
{
	int timberLen = 100000;
	int timberCut = 1;

	CTimber timber;

	timber.CutTimber(timberLen, timberCut);
	
	cout << timber.GetCost();

	return 0;
}

