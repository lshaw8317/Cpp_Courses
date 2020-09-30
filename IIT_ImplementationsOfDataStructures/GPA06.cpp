// GPA06.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include<stack>
typedef std::vector<std::vector<int> > graph;
int compute_longest_path_length(std::vector<std::vector<int> > graph) {
    int max = 0;
    //DFS
    for (int i = 0; i < graph.size(); ++i) {
        //std::cout << "\n"<<i;
        std::vector<bool> visited(graph.size(), false); //vector for visited nodes
        std::vector<int> path(graph.size(),0); //vector for paths to nodes
        std::stack<int> s;
        s.push(i); visited[i] = true;
        while (!s.empty()) {
            int t = s.top(); s.pop();
            for (std::vector<int>::iterator it = graph.at(t).begin(); it != graph.at(t).end(); ++it) {
                if (!visited[*it]) { s.push(*it); path.at(*it) = path.at(t) + 1; visited[*it] = true; } //add to stack if not parent
            }
        }
        for (std::vector<int>::iterator it = path.begin(); it != path.end(); ++it) { if (*it > max) { max = *it; } }
    }
    return max;
}
int main()
{
    graph g(18);
    g.at(0) = { 1 };g.at(1) = { 0,2,3 };g.at(2) = { 1 };g.at(3) = { 1,4,5 };g.at(4) = { 3 };g.at(5) = { 3, 6, 7 };g.at(6) = { 5 };g.at(7) = { 5,8,11 };g.at(8) = { 7,9,10 };g.at(9) = { 8 };g.at(10) = { 8 };
    g.at(11) = { 7,12,13 };g.at(12) = { 11 };g.at(13)= { 11,14,15 };g.at(14) = { 13 };g.at(15) = { 13,16,17 };g.at(16) = { 15 };g.at(17) = { 15 };
    std::cout << "Test case 1:\nCorrect answer is 8. My answer is: "<< compute_longest_path_length(g);
    g.resize(6);
    g.at(0) = { 1,5 }; g.at(1) = { 0,2,3 }; g.at(2) = { 1,4 }; g.at(3) = { 1 }; g.at(4) = { 2 }; g.at(5) = { 0 };
    std::cout << "\n\nTest case 2:\nCorrect answer is 4. My answer is: " << compute_longest_path_length(g);
}
