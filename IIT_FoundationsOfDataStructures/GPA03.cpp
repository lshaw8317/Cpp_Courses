// GPA03.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "GPA03.h"

int main()
{
	int n = 6;
	twoStacks ts=twoStacks(n+1);
	std::cout << "Stack1";
	for (int i = 0;i < (n+3)/2;i++) {
		if (ts.push1(i)) { std::cout << "\nSuccessful push of "<<i<<" at i = " << i; }
		else { std::cout << "\nFailed push of " << i << " at i = " << i;}
	}
	std::cout << "\nStack2";
	for (int i = 0;i < n/2+1;i++) {
		if (ts.push2(i)) { std::cout << "\nSuccessful push of " << i << " at i = " << n-i; }
		else { std::cout << "\nFailed push of " << i << " at i = " << n-i; }
	}
	std::cout << "\nPop from Stack1: "<< ts.pop1();
	std::cout << "\nReset and try again for Stack2";
	ts.reset_top2();
	for (int i = 0;i < n / 2 + 1;i++) {
		if (ts.push2(i)) { std::cout << "\nSuccessful push of " << i << " at i = " << n - i; }
		else { std::cout << "\nFailed push of " << i << " at i = " << n - i; }
	}
	std::cout << "\nPop from Stack2 and then refill: " << ts.pop2();
	if (ts.push2(n/2)) { std::cout << "\n	Successful refill of " << n/2 << " at i = " << n - n/2; }
	else { std::cout << "\n	Failed push of " << n/2<< " at i = " << n - n/2; }
	std::cout << "\nStacks both full, try double_resize";
	ts.double_resize();
	for (int i = 0;i < (n + 3) / 2;i++) {
		if (ts.push1(i)) { std::cout << "\nSuccessful push of " << i << " at i = " << i; }
		else { std::cout << "\nFailed push of " << i << " at i = " << i; }
	}
	std::cout << "\nStack2";
	for (int i = 0;i < n / 2 + 1;i++) {
		if (ts.push2(i)) { std::cout << "\nSuccessful push of " << i << " at i = " << 2*n+1 - i; }
		else { std::cout << "\nFailed push of " << i << " at i = " << 2*n+1 - i; }
	}
}
