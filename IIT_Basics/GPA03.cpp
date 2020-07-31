// GPA03.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<iomanip>
#include "GPA03.h"
using namespace std;

int main()
{
	int audience[10][2] = {
	{6,13},
	{5,3},
	{43,2},
	{3,8},
	{7,23},
	{5,3},
	{9,92},
	{5,3},
	{11,26},
	{4,23} };
	int merged[10][2];
	int i_index,j_index;
	sorting(audience, 10, i_index, j_index);
	merge(audience, merged, 10, i_index, j_index);
	cout << i_index << "  " << j_index << endl;
	for (int i = 0;i < 10;i++)
	{
		cout << "\n";
		for (int j = 0;j < 2;j++)
		{
			cout << setw(4) << merged[i][j];
		}
		cout << endl;
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
