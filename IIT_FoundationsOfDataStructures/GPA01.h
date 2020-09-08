#pragma once
#include <math.h>

class Point {
public:
    int x, y;
};
class LineSeg {
public:
    Point pa,pb;
};

bool SegIntersect(LineSeg l1, LineSeg l2) {
    //Line 1
    double a1x = l1.pa.x;
    double a1y = l1.pa.y;
    double b1x = l1.pb.x;
    double b1y = l1.pb.y;

    //Line 2
    double a2x = l2.pa.x;
    double a2y = l2.pa.y;
    double b2x = l2.pb.x;
    double b2y = l2.pb.y;
    
    double det = (a1x - b1x) * (b2y - a2y) + (a2x - b2x) * (a1y - b1y);
    if (fabs(det) > 1e-10) {
        float lam1 = ((b2y - a2y) * (a1x - a2x) + (a2x - b2x) * (a1y - a2y)) / det;
        float lam2 = ((b1y - a1y) * (a1x - a2x) + (a1x - b1x) * (a1y - a2y)) / det;
        return (abs(lam1) < 1 && abs(lam2) < 1) ? true : false;
    }
    else { return false; };
}; 