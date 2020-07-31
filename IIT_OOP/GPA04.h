#pragma once
#include <vector>
#include <algorithm> 
using namespace std;
void royale(int N, int W, vector<int>& money, bool& flag)
{
	if (N > 100 || N < 1 || W>100 || W < 1)
	{
		cout << "Please use valid inputs for W,N." << endl;
		return;
	}

	//Find max 2 elements of money
	vector<int>::iterator maxEl = max_element(money.begin(), money.end());
	int LeftVal = 0;
	if (maxEl + 1 != money.end()) { int LeftVal = *max_element(maxEl + 1, money.end()); }
	int RightVal = *max_element(money.begin(), maxEl);
	int max2val = (LeftVal < RightVal) ? RightVal : LeftVal;
	int maxval = *maxEl;
	if (maxval > 299) { cout << "All starting money values must be less than 300."<<endl; return; }

	int count = 0;
	for (vector<int>::iterator it = money.begin();it != money.end();it++)
	{
		if ((maxval - *it) % (W + 1) != 0)
		{
			count++;
			if (count == 2) { break; }
		}
	}
	if (count < 2) { cout << "YES" << endl; flag = true; return; }
	else
	{
		count = 0;
		for (vector<int>::iterator it = money.begin();it != money.end();it++)
		{
			if ((max2val - *it) % (W + 1) != 0 && (max2val - *it) > 0)
			{
				count++;
				if (count == 1) { break; }
			}
		}
		if (count < 1) { cout << "YES" << endl; flag = true; return; }
		else { cout << "NO" << endl; flag = false; return; }
	}


}