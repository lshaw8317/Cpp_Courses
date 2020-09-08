#pragma once
#include <math.h>       /* sqrt */
///////////////////////////////////////////////////////////////

//PPA 1
struct vertex {
    float x;
    float y;
};
struct triangle {
    vertex vertices[3];
};
float cal_area(triangle aTriangle) {
    double ax = aTriangle.vertices[0].x;
    double ay = aTriangle.vertices[0].y;
    double bx = aTriangle.vertices[1].x;
    double by = aTriangle.vertices[1].y;
    double cx = aTriangle.vertices[2].x;
    double cy = aTriangle.vertices[2].y;
    float area;
    area = 0.5 * (ax * (by - cy) + bx * (cy - ay) + cx * (ay - by));
    area = area < 0 ? -area : area;
    return area;
};
///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////
//PPA 2
struct rational {
    int numerator,denominator;
};
void reduce(rational* inputrational, rational* outputrational) {
    int n = inputrational->numerator;
    int d = inputrational->denominator;
    if (n == d) { n = 1;d = 1; }//case where n/d=1
    else {
        int i = n < d ? n : d;
        //Deal with case where d (or n) is a multiple of n (or d)
        if (n % i == 0 && d % i == 0) { n /= i;d /= i;i = 0; };
        //search for HCF<min(n,d)/2 (assume +ve)
        for (i / 2;i > 0;i--) {
            if (n % i == 0 && d % i == 0) { n /= i;d /= i;break; };
        }
    };
    outputrational->numerator = n;
    outputrational->denominator = d;
};
bool isEqual(struct rational num1, struct rational num2) {
    rational* p1 = &num1;
    rational* p2 = &num2;
    rational obj;
    rational* p = &obj;
    reduce(p1, p);
    int d = p->denominator;int n = p->numerator;
    reduce(p2, p);
    return (p->denominator == d && p->numerator == n) ? true : false;
}
void PPA2printer(bool indicator) {
    if (indicator){std::cout << "\nNumbers are equal.";}
    else { std::cout << "\nNumbers are not equal."; }
}
///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////
//PPA 3