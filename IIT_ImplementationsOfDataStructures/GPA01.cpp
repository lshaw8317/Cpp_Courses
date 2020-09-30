// GPA01.cpp //

#include <iostream>
#include <vector>
#include <list>
class SafeMap {
private:
    std::vector<std::vector<int> > SafeRoutes;
public:
    int nVertices;
    //Constructors
    SafeMap() : nVertices(0),SafeRoutes(0) {}
    SafeMap(int n) : nVertices(n),SafeRoutes(n) {}

    int addSafeRoute(int s, int d) {
        if (s > nVertices - 1 || d > nVertices - 1) { std::cout << "Input args s,d to addSafeRoute must be less than nVertices";return -1; }
        if (SafeRoutes.at(s).size() == 0) { SafeRoutes.at(s).push_back(d); return 0; } //empty vector, push d and exit function
        else {
            try {
                std::vector<int>::iterator it = SafeRoutes.at(s).begin();
                while (*it <= d) {
                    it++;
                    if (it == SafeRoutes.at(s).end()) { break; } //return to final vector el., exit loop
                }
                it--;
                if (*it != d) { SafeRoutes.at(s).insert(it+1, d); return 0; } //keeps vector sorted
                else { std::cout << "Desired route already exists from " << s << " to " << d << "."; return -1; }
            }
            catch (const std::exception& e) { std::cout << "Exception: " << e.what(); return -1; }
        }
    };
    int isReachable(int s, int d) {
        std::list<int> q;
        int* dist = new int[nVertices];
        bool* visited = new bool[nVertices];
        for (int i = 0;i < nVertices; i++) { dist[i]=INT_MAX; }
        for (int i = 0;i < nVertices; i++) { visited[i] = false; }
        dist[s] = 0; //dist to itself is 0
        q.push_back(s); //label as discovered
        visited[s] = true;
        while (q.size() > 0) {
            int v = q.front();
            q.pop_front();
            for (std::vector<int>::iterator it = SafeRoutes[v].begin(); it != SafeRoutes[v].end();it++)
            {
                if (visited[*it] == false) { 
                    visited[*it] = true;
                    dist[*it] = dist[v] + 1;
                    q.push_back(*it);
                    if (*it == d) { return dist[*it]; }
                }//if not discovered
            }
        }
        return -1;
    }
};

void printer(int s, int d, SafeMap g) {
    int len = g.isReachable(s, d);
    if (len != -1) {std::cout << "\nThere is a Safe Path from " << s << " to " << d << " and path length is " << len;
    }
    else{std::cout << "\nThere is no Safe Path from " << s << " to " << d;}
}
int main()
{
    SafeMap g(4);
    g.addSafeRoute(0, 1);
    g.addSafeRoute(0, 2);
    g.addSafeRoute(1, 2);
    g.addSafeRoute(2, 0);
    g.addSafeRoute(2, 3);

    std::vector<std::vector<int> > sd{ {2,3},{3,2},{0,2} };
    std::vector<std::vector<int> >::iterator it = sd.begin();
    std::cout << "Sample Test Graph:";
    for (;it != sd.end();it++)
    {
        int s = (*it).at(0);int d = (*it).at(1);
        printer(s, d, g);
    }

}