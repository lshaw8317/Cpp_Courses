// PPAs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<list>
#include<stack>
#include<vector>
#include<iostream>
#include<string>

//PPA03
using namespace std;
// return the number of connected components of the graph
int no_of_connected_components(int N, vector< vector<int> >& adjList) {
    vector<bool> visited(adjList.size(), false);
    int num_unvisited = adjList.size(); int num_connected = 0;
    //DFS
    while (num_unvisited != 0) {
        stack<int> s; num_connected++;
        for (vector<bool>::iterator it = visited.begin(); it != visited.end(); ++it) {
            if (!(*it)) s.push(distance(visited.begin(), it));
        }
        while (!s.empty()) {
            int v = s.top(); s.pop();
            if (!visited[v]) {
                visited[v] = true; num_unvisited--;
                for (vector<int>::iterator it = adjList[v].begin(); it != adjList[v].end(); ++it) {
                    s.push(*it);
                }
            }
        }
    }
    cout << " My answer is this: " << num_connected;
    return num_connected;
}

//PPA05
class hiddenString {
private:
    string data;
public:
    int getSize() { return data.size(); }
    char getIdx(int i) { return data[i]; }
};
bool s1OfiEqualTos2Ofj(hiddenString s1, int i, hiddenString s2, int j) {
    return s1.getIdx(i) == s2.getIdx(j);
}
void ComputePrefix(hiddenString& p, vector<int>& pi) {
    pi[0] = -1;
    int q = -1;
    for (int i = 1; i < p.getSize(); ++i) {
        while (q > -1 && !s1OfiEqualTos2Ofj(p, q + 1, p, i)) { q = pi[q]; }
        if (s1OfiEqualTos2Ofj(p, q + 1, p, i)) { ++q; }
        pi[i] = q;
    }
}
vector<int> getPatternMatchIndices(hiddenString& word, hiddenString& pattern) {
    vector <int> matchedIndices;
    vector<int> pi(pattern.getSize());
    ComputePrefix(pattern, pi);

    int q = -1;
    for (int i = 0; i < word.getSize(); ++i) {
        while (q > -1 && !s1OfiEqualTos2Ofj(pattern, q + 1, word, i)) { q = pi[q]; }
        if (s1OfiEqualTos2Ofj(pattern, q + 1, word, i)) { ++q; }
        if (q == pattern.getSize() - 1) { matchedIndices.push_back(i - pattern.getSize() + 1); q = pi[q]; }
    }
    return matchedIndices;
}

int main()
{
    std::cout << "Hello World!\n";
}
