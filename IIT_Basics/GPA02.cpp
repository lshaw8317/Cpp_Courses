// GPA02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "GPA02.h"
#include <iomanip>
using namespace std;

int main()
{
	int gq[54] = { 7,
10,
10,
7,
4,
8,
0,
5,
2,
0,
7,
9,
8,
9,
0,
3,
0,
0,
9,
10,
0,
0,
2,
9,
9,
2,
4,
3,
10,
2,
2,
3,
3,
4,
3,
2,
10,
10,
8,
5,
6,
4,
6,
2,
6,
6,
10,
10,
4,
10,
0,
0,
10,
8 };
	float gpa[54] = { 0,
1,
1,
0,
0.3,
0.3,
0.3,
0.3,
1,
1,
1,
0.3,
0.3,
0.3,
0.3,
0.3,
0,
0,
0.3,
0.3,
0.3,
1,
1,
1,
1,
1,
0,
0,
0.6,
0.6,
0.6,
0.6,
0.6,
0.6,
0.6,
0.6,
0,
0,
0.6,
0.6,
0,
0.6,
0,
0.6,
0,
0.6,
0,
0,
0,
0.6,
0.6,
0.6,
1,
0 };
	int sum_gq[11] = { 0 };
	int sum_gpa[4] = { 0 };
	int count[12][5] = { 0 };


	getTotalGQ(54, gq, sum_gq);
	getTotalGPA(54, gpa, sum_gpa);
	getTotalCount(54, gq, gpa, count);

	for (int i = 0;i < 12;i++)
	{
		cout << "\n";
		for (int j = 0;j < 5;j++)
		{
			cout << setw(3) << count[i][j];
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
