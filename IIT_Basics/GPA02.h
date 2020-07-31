#pragma once
#include<cmath>
using namespace std;
//Func 1
void getTotalGQ(int numOfStudents, int gq[], int sum_gq[])
{
	for (int i = 0;i < numOfStudents;i++)
	{
		sum_gq[gq[i]]+=1;
	}
}
//Func 2
void getTotalGPA(int numOfStudents, float gpa[], int sum_gpa[]) 
{
	for (int i = 0;i < numOfStudents;i++)
	{
		if (abs(gpa[i]) < 0.01) { sum_gpa[0] += 1; }
		else if(abs(gpa[i]-0.3)<0.01) { sum_gpa[1] += 1; }
		else if (abs(gpa[i] - 0.6) < 0.01) { sum_gpa[2] += 1; }
		else { sum_gpa[3] += 1; }
	}
}
//Func 3
void getTotalCount(int numOfStudents, int gq[], float gpa[], int count[][5]) 
{
	for (int k = 0; k < numOfStudents; k++)
	{
		if (abs(gpa[k]) < 0.01) { count[gq[k]][0] += 1; }
		else if (abs(gpa[k] - 0.3) < 0.01) { count[gq[k]][1] += 1; }
		else if (abs(gpa[k] - 0.6) < 0.01) { count[gq[k]][2] += 1; }
		else { count[gq[k]][3] += 1; }
	}

	for (int m = 0;m < 4;m++)
	{
		for (int n = 0;n < 11;n++)
		{
			count[11][m] += count[n][m];
			count[n][4] += count[n][m];
		}
		count[11][4] += count[11][m];
	}

}