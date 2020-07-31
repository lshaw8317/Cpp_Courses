#pragma once
using namespace std;
//power
int power(int a, int b)
{
	int res = 1;
	for (int i = 0;i < b;i++)
	{
		res = (res*a)%100;
	}
	return res%100;
}
//Func1
int comparator(int audience[][2], int index1, int index2)
{
	int ecode1 = power(audience[index1][0], audience[index1][1]);
	int ecode2 = power(audience[index2][0], audience[index2][1]);
	
	if (ecode1 > ecode2) { return -1; }
	else if (ecode1 < ecode2) { return 1; }
	else { return 0; }
}
//Func2
void sorting(int audience[][2], int N, int& i_index, int& j_index)
{
	for (int i = 0 ;i < N-1;i++)
	{
		if (comparator(audience, i, i+1) != 1) { i_index = i; break; }
	}
	for (int j = N-1; j>0 ;j--)
	{
		if (comparator(audience, j, j - 1) != -1) { j_index = j; break; }
	}

	int currIndex = i_index+1;
	while (currIndex < j_index)
	{
		for (int k = currIndex;k < j_index;k++)
		{
			if (comparator(audience, currIndex, k) == -1)
			{
				int temp1 = audience[currIndex][0];
				int temp2 = audience[currIndex][1];
				audience[currIndex][0] = audience[k][0]; //update minimums
				audience[currIndex][1] = audience[k][1];
				audience[k][0] = temp1;
				audience[k][1] = temp2;
			}
		}
		currIndex++;
	}
	return;
}
//Func3
void merge(int audience[][2], int mergedarray[][2], int N, int &i_index, int &j_index)
{
	int index = 0;
	for (int i = 0, j = j_index; (i <= i_index) || (j < N);)
	{
		if ((i <= i_index) && (j <N)) //Both arrays unseen
		{
			if (comparator(audience, i, j) == 1)//j>i
			{
				mergedarray[index][0] = audience[i][0];
				mergedarray[index][1] = audience[i][1];
				i++;
			}
			else //j<=i
			{
				mergedarray[index][0] = audience[j][0];
				mergedarray[index][1] = audience[j][1];
				j++;
			}
		}
		else
		{
			if(i<=i_index)
			{
				mergedarray[index][0] = audience[i][0];
				mergedarray[index][1] = audience[i][1];
				i++;
			} //j_array seen
			else
			{
				mergedarray[index][0] = audience[j][0];
				mergedarray[index][1] = audience[j][1];
				j++;
			}
		}
		index++;
	}
	for (int k = i_index+1;k < j_index;k++)
	{
		mergedarray[index][0] = audience[k][0];
		mergedarray[index][1] = audience[k][1];
		index++;
	}
}