// GPA01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "GPA01.h"
int main()
{
	//Test Case 1
	std::cout << "Test Case 1:\n";
	LineSeg l1, l2;
	Point p1a, p1b, p2a, p2b;
	p1a.x = 0; p1a.y = 0; p1b.x = 2; p1b.y = 0;
	p2a.x = 0; p2a.y = 0; p2b.x = 0; p2b.y = 2;
	l1.pa = p1a;l1.pb = p1b;
	l2.pa = p2a;l2.pb = p2b;
	if (SegIntersect(l1, l2)) {
		std::cout << "Yes";
	}
	else { std::cout << "No"; };

	//Test Case 2
	std::cout << "\nTest Case 2:\n";
	p1a.x = -1; p1a.y = 0; p1b.x = 3; p1b.y = 0;
	p2a.x = 0; p2a.y = 4; p2b.x = 0; p2b.y = 6;
	l1.pa = p1a;l1.pb = p1b;
	l2.pa = p2a;l2.pb = p2b;
	if (SegIntersect(l1, l2)) {
		std::cout << "Yes";
	}
	else { std::cout << "No"; };

	//Test Case 3
	std::cout << "\nTest Case 3:\n";
	p1a.x = 0; p1a.y = 0; p1b.x = 1; p1b.y = 2;
	p2a.x = 3; p2a.y = 2; p2b.x = 2; p2b.y = 0;
	l1.pa = p1a;l1.pb = p1b;
	l2.pa = p2a;l2.pb = p2b;
	if (SegIntersect(l1, l2)) {
		std::cout << "Yes";
	}
	else { std::cout << "No"; };
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
