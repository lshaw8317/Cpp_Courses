// GPA06.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <list>

typedef std::vector<std::vector<int>> graph;
int subnnR(int* a, graph g, int n) {
    if (n > g.size() - 1) { std::cout << "Error";return -1; }; //If node label is not in graph
    a[n] = 1; //label as discovered
    for (std::vector<int>::iterator it = g[n].begin();it < g[n].end();it++) {
        if (a[*it] == 0) { subnnR(a, g, *it); } //undiscovered => recursive call
    };
    return 0; //finished
};
int numNodesReachable(graph g, int s) {
    int* arr = new int[g.size()]; //array to track visited nodes
    for (int i = 0;i < g.size();i++) {
        arr[i] = 0;
    }
    if (subnnR(arr, g, s) == 0) {
        int tot = 0;
        for (int i = 0;i < g.size();i++) {
            tot += arr[i];
        }
        return tot;
    }
    else { return -1; };
};
int main()
{
    std::cout << "Test graph 1";
    graph g = { {1,2},{2,4},{4},{5},{},{3} };
    std::cout << "\ns=1, number of accessible nodes: "<<numNodesReachable(g,1);
    std::cout << "\ns=3, number of accessible nodes: "<< numNodesReachable(g, 3);

    std::cout << "\n\nTest graph 2";
    graph g2 = { {1,2},{3,4,8},{6,7},{8},{5,0},{},{8,9},{3},{},{}};
    std::cout << "\ns=1, number of accessible nodes: " << numNodesReachable(g2, 1);
    std::cout << "\ns=2, number of accessible nodes: " << numNodesReachable(g2, 2);
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
