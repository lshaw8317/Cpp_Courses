// PPAs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>
#include<list>
#include <cstdlib>
using namespace std;
#include <time.h>       /* time */
//PPA03
/*
using namespace std;
void move(int coordinateX, int coordinateY, queue<int>& Qx, queue<int>& Qy, vector<vector<char> >& graph, vector<vector<bool> >& visited, vector <char>& answer)
{
    visited[coordinateY][coordinateX] = true;
    //step 0
    if (graph[coordinateY][coordinateX] == 't') { return; }
    //step 1
    if (coordinateX < 9) {
        if (graph[coordinateY][coordinateX + 1] != 'x' && visited[coordinateY][coordinateX + 1] == false) {
            Qx.push(coordinateX + 1);Qy.push(coordinateY);
            visited[coordinateY][coordinateX + 1] = true;
            answer.push_back(graph[coordinateY][coordinateX + 1]);
        }
    }
    //step 2
    if (coordinateY < 9) {
        if (graph[coordinateY + 1][coordinateX] != 'x' && visited[coordinateY + 1][coordinateX] == false) {
            Qx.push(coordinateX);Qy.push(coordinateY + 1);
            visited[coordinateY + 1][coordinateX] = true;
            answer.push_back(graph[coordinateY + 1][coordinateX]);
        }
    }
    //step 3
    if (coordinateX > 0) {
        if (graph[coordinateY][coordinateX - 1] != 'x' && visited[coordinateY][coordinateX - 1] == false) {
            Qx.push(coordinateX - 1);Qy.push(coordinateY);
            visited[coordinateY][coordinateX - 1] = true;
            answer.push_back(graph[coordinateY][coordinateX - 1]);
        }
    }
    //step 4
    if (coordinateY > 0) {
        if (graph[coordinateY - 1][coordinateX] != 'x' && visited[coordinateY - 1][coordinateX] == false) {
            Qx.push(coordinateX);Qy.push(coordinateY - 1);
            visited[coordinateY - 1][coordinateX] = true;
            answer.push_back(graph[coordinateY - 1][coordinateX]);
        }
    }
    //step 5
    if (!Qx.empty()) {
        int x = Qx.front();int y = Qy.front();
        Qx.pop();Qy.pop();
        //step 6
        move(x, y, Qx, Qy, graph, visited, answer);
    }
}
void move(int coordinateX, int coordinateY, queue<int>& Qx, queue<int>& Qy, vector<vector<char> >& graph, vector<vector<bool> >& visited, vector <char>& answer)
{
    int x = coordinateX;int y = coordinateY;
    visited[y][x] = true;
    Qx.push(x);Qy.push(y);
    while (!Qx.empty()) {
        //step 5
        x = Qx.front();y = Qy.front();
        Qx.pop();Qy.pop();
        //step 0
        if (graph[y][x] == 't') { break; }
        //step 1
        if (x < 9) {
            if (graph[y][x + 1] != 'x' && visited[y][x + 1] == false) {
                Qx.push(x + 1);Qy.push(y);
                visited[y][x + 1] = true;
                answer.push_back(graph[y][x + 1]);
            }
        }
        //step 2
        if (y < 9) {
            if (graph[y + 1][x] != 'x' && visited[y + 1][x] == false) {
                Qx.push(x);Qy.push(y + 1);
                visited[y + 1][x] = true;
                answer.push_back(graph[y + 1][x]);
            }
        }
        //step 3
        if (x > 0) {
            if (graph[y][x - 1] != 'x' && visited[y][x - 1] == false) {
                Qx.push(x - 1);Qy.push(y);
                visited[y][x - 1] = true;
                answer.push_back(graph[y][x - 1]);
            }
        }
        //step 4
        if (y > 0) {
            if (graph[y - 1][x] != 'x' && visited[y - 1][x] == false) {
                Qx.push(x);Qy.push(y - 1);
                visited[y - 1][x] = true;
                answer.push_back(graph[y - 1][x]);
            }
        }
    }
}
*/

//PPA04
/*
struct Node {
    int data;
    Node* next;
};
class LinkedList {
    int size;
public:
    Node* list;
    LinkedList(int s) : size(s){
        list = new Node;
        Node* ptr=list;
        for (int i = 0;i < s-1;i++) {
            ptr->data = 10*(i+1);
            Node* n = new Node;
            ptr->next = n;
            ptr = n;
        }
        ptr->data = 10*s;
        ptr->next = NULL;
    }
    void deleteNode(Node* toDelete);
};

void LinkedList::deleteNode(Node* toDelete){
    (toDelete - 1)->next = toDelete->next;
    delete toDelete;
    return;
}
*/

//PPA05
/*
class LocTree {
private:
    int N;
    list<int>* adj; //array of lists of ints
//Functions
public:
    LocTree(int N);
    void addEdge(int n, int m);
    void IterAry(int v, int Itr[]);
    int getIterTree();
    void printTree();
};
LocTree::LocTree(int N)
{
    this->N = N;
    adj = new list<int> [N];
}
void LocTree::addEdge(int node1, int node2)
{
    adj[node1].push_back(node2);
}
void LocTree::IterAry(int v, int Itr[])
{
    if (adj[v].empty()) { Itr[v] = 0;return; }
    else {
        int i = 1;
        for (list<int>::iterator it = adj[v].begin();it != adj[v].end();++it) {
            IterAry(*it, Itr);
            if (Itr[*it] + i > Itr[v]) { Itr[v] = Itr[*it] + i; }
            ++i;
        }
    }
}
int LocTree::getIterTree()
{
    int* Itr = new int[N];
    for (int i = 0;i < N;++i) {
        Itr[i] = 0;
    }
    IterAry(0, Itr);
    return Itr[0];
}
void LocTree::printTree() {
    for (int i = 0;i < N;++i) {
        cout << "\n\n" << i << "\n";
        for (list<int>::iterator it = adj[i].begin();it != adj[i].end();++it) {
            cout << *it;
        }
    }
}
*/

//PPA06
class Graph {
    int V;
    list<int>* adj;
public:
    Graph(int);
    void addEdge(int, int);
    bool checkCyclicNode(int, bool[], bool*);
    bool checkCyclicGraph();
};
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int node1, int node2)
{
    adj[node1].push_back(node2);
}

bool Graph::checkCyclicNode(int node, bool visited[], bool* currentIter)
{
    if (visited[node] && !currentIter[node]) { return true; }
    else { return false; }
}

bool Graph::checkCyclicGraph()
{
    int v = V;
    bool visited [v];
    bool currentIter [v];
    for (int i = 0;i < V;++i) {
        for (int j = 0; j < V; j++) { visited[j] = false; }
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            for (int j = 0; j < V; j++) { currentIter[j] = false; }
            int c = q.front();
            q.pop();
            for (list<int>::iterator it = adj[c].begin();it != adj[c].end();++it) {
                if (!visited[*it]) {
                    visited[*it] = true;
                    q.push(*it);
                }
                currentIter[*it] = true;
                if (checkCyclicNode(*it, visited, currentIter)) { return false; }
            }
        }
    }
    return true;
}

int main()
{
    //PPA03
    /*
    srand(time(NULL));
    vector<vector<char> > g(10);
    for (int i = 0;i < 10;i++) {
        g[i] = vector<char>(10);
        for (int j= 0;j < 10;j++) {
            g[i][j] = rand() % 10;
            if (rand() % 10 == 1) { g[i][j] = 'x'; }
        }
    }
    g[rand() % 10][rand() % 10] = 't';
    vector<vector<char> > g{
        {'8', '0', '8', '0', '2', '1', '6', '2', '6', '0'},
        {'8', 'x', 'x', '5', '2', '7', '7', '9', '6', '8'},
        {'4', '7', '4', '2', '3', '5', '2', '5', '3', 'x'},
        {'7', '9', 'x', '4', '7', 'x', '3', '2', '1', '7'},
        {'0', '7', '6', '0', '1', '6', '5', '8', '2', '9'},
        {'5', '6', '5', '9', '6', '7', '2', '8', 'x', '3'},
        {'5', '4', '1', '4', '8', '8', '1', '9', 'x', '2'},
        {'3', 'x', '9', '7', '8', '8', '0', '1', '6', '2'},
        {'x', '9', '7', '3', '6', '0', 'x', '6', '9', '7'},
        {'9', '3', '0', 'x', '6', 't', '7', '7', '4', '4'}
    };

    for (int i = 0;i < 10;i++) {
        for (int j = 0;j < 10;j++) {
            if (g[i][j] != 'x' && g[i][j] != 't') { cout << g[i][j] << " "; }
            else { cout << g[i][j] << " "; }
        }
        cout << "\n";
    }
    queue<int> Qx;queue<int> Qy;
    vector<vector<bool> > visited(10);vector <char> answer;
    for (int i = 0;i < 10;i++) {
        visited[i] = vector<bool>(10);
        for (int j = 0;j < 10;j++) {
            visited[i][j] = false;
        }
    }
    visited[0][0] = true;
    answer.push_back(g[0][0]);
    Qx.push(0);Qy.push(0);
    move(0, 0, Qx, Qy, g, visited, answer);
    cout << "\n\n";
    for (vector<char>::iterator it = answer.begin();it != answer.end();it++) { 
        if (*it != 'x' && *it != 't') { cout << *it << " "; }
        else { cout << *it << " "; }
    }
    cout << "\n\nExpected output:\n8 0 8 8 4 0 7 7 2 5 4 9 0 1 2 2 7 5 6 7 3 4 6 6 5 2 7 5 7 0 5 4 3 6 9 2 1 9 1 0 6 5 3 6 6 4 9 8 3 2 5 7 8 7 7 1 8 2 8 8 3 0 9 7 2 8 1 8 6 3 9 9 0 0 6 3 1 t 2 6 6";
    */
    //PPA04
    /*
    void LinkedList::deleteNode(Node *toDelete){
        Node* ptr=this->head;
        if(ptr==toDelete){this->head=ptr->next;}
        else{
            while (ptr->next!=toDelete){
                ptr=ptr->next;
            }
            ptr->next=toDelete->next;
        }
        delete toDelete;
    }
    LinkedList l(5);
    Node* ptr;
    ptr = l.list;
    while(ptr!=NULL){
        std::cout << ptr->data;
        ptr=ptr->next;
    }
    l.deleteNode(l.list->next->next);
    std::cout << "\n\n";
    ptr = l.list;
    while (ptr != NULL) {
        std::cout << ptr->data;
        ptr = ptr->next;
    }
    */
    //PPA05
    /*
    LocTree tree(25);
    for (int i = 1;i < 7;++i) {tree.addEdge(0, i);}
    for (int i = 1;i < 18;++i) { tree.addEdge(i, i + 6); }
    tree.addEdge(19, 24);
    tree.printTree();
    cout << tree.getIterTree();
    */
    Graph g=Graph(6);
    g.addEdge(0, 1);g.addEdge(1, 2);g.addEdge(2, 3);g.addEdge(2, 4);g.addEdge(4, 5);g.addEdge(5, 3);
    if (g.checkCyclicGraph()) { cout << "Graph has cycle."; }
}

