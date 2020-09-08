// PPAs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "PPAs.h"

int main()
{
    //PPA1
    /*
    vertex v1,v2,v3;
    v1.x = 1, v1.y = 4;
    v2.x = 2, v2.y = 5;
    v3.x=5, v3.y=20;
    vertex vs[3] = { v1,v2,v3 };
    triangle t;
    for (int i=0;i < 3;i++) {
        t.vertices[i] = vs[i];
    }
    std::cout << cal_area(t);
    */

    //PPA2
    rational r1;
    rational r2;
    r1.denominator = 9;r1.numerator = 3;
    r2.denominator = 3;r2.numerator = 1;
    std::cout << "Example 1";
    PPA2printer(isEqual(r1, r2));

    std::cout << "\n\nExample 2";
    r1.denominator = 4;r1.numerator = 1;
    r2.denominator = 3;r2.numerator = 1;
    PPA2printer(isEqual(r1, r2));
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
