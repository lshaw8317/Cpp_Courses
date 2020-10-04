// GPA05.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _USE_MATH_DEFINES
#include <iostream>
#include<list>
#include<vector>
#include<algorithm>
#include<math.h>
#include<stack>
struct Point {
    int x;
    int y;
    Point(int a, int b) : x(a), y(b) {}
};
std::vector<double> angles;
bool mycomp(int a, int b) {
    return angles[a] < angles[b];
}
double myAtan(int x, int y) {
    double ang = atan(y / x);
    return (x < 0) ? M_PI + ang : ang;
}
bool clockwise(Point& p, Point& q, Point &p0) {
    //if >0 the p-p0 is clockwise from q-p0
    return (p.x - p0.x) * (q.y - p0.y) - (p.y - p0.y) * (q.x - p0.x) > 0;
}

bool is_inside_triangle(Point p1, Point p2, Point p3, Point x) {
    Point minp = p1;
    std::vector<Point> l = { p1,p2,p3,x };
    for(std::vector<Point>::iterator it=l.begin();it!=l.end();++it){if (minp.y > it->y || (minp.y == it->y && minp.x > it->x)) { minp = *it; }}
    if (minp.x == x.x && minp.y==x.y) { return false; }
    for (std::vector<Point>::iterator it = l.begin(); it != l.end(); ++it) { angles.push_back(myAtan(it->x-minp.x, it->y-minp.y)); }
    std::sort(l.begin(), l.end(), mycomp);
    std::list<Point> s; s.push_back(l[0]); s.push_back(l[1]); s.push_back(l[2]);
    std::list<Point>::iterator it = s.begin();
    std::advance(it, 1);
    if (it->x == x.x && it->y == x.y) { return false; }
    if (clockwise(s.back(), *(l.end() - 1), *it)) { s.pop_back(); }
    s.push_back(*(l.end() - 1));
    if (s.size() < 4) { return !(s.back().x == x.x && s.back().y == x.y); }
    else {return false;}
};
 

}
int main()
{
    std::cout << "Hello World!\n";
}

