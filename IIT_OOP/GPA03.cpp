// GPA03_OOP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <list>
#include <vector>;
using namespace std;

class SafeMap
{
	map<int, list<int> > connections;
	int numvertices;
public:
	SafeMap(int v) : numvertices(v) 
	{
		for (int i = 0;i < numvertices;i++)
		{
			connections[i] = {};
		}
	};
	void addSafeRoute(int n1, int n2)
	{
		connections[n1].push_back(n2);
	}
	int isReachable(int s, int d)
	{
		list<int> unvisited;
		for (int i = 0;i < numvertices;i++)
		{
			unvisited.push_back(i);
		}
		vector<int> dists(numvertices, numvertices + 1);
		vector<int> prev(numvertices, -1);
		dists[s] = 0;
		prev[s] = s;
		while (unvisited.size() != 0)
		{
			list<int>::iterator it = unvisited.begin();
			int min = numvertices + 1;
			int vert = unvisited.front();
			for (;it != unvisited.end();it++)
			{
				if (dists[*it] < min) { vert = *it; min = dists[*it]; }
			}
			unvisited.remove(vert);
			if (connections[vert].size() != 0)
			{
				it = connections[vert].begin();

				for (;it != connections[vert].end();it++)
				{
					if (dists[*it] > min + 1);
					{
						dists[*it] = min + 1;
						prev[*it] = vert;
					}
				}
			}
			else
			{
				//No connections
			}
			if (dists[d] < numvertices + 1) { break; }
		}
		if (dists[d] < numvertices + 1) { return dists[d]; }
		else { return -1; }
	}
};


int main()
{
	SafeMap g(4);
	g.addSafeRoute(0, 1);
	g.addSafeRoute(0, 2);
	g.addSafeRoute(1, 2);
	g.addSafeRoute(2, 0);
	g.addSafeRoute(2, 3);

	cout << g.isReachable(2, 3) << endl;

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
