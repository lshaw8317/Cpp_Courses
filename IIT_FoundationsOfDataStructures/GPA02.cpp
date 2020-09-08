// GPA02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "GPA02.h"
int main()
{
    std::string s="0011";
    std::cout << "Binary: "<<s;
    std::cout << "\nGray: " << binarytoGray(s);

    s = "01001";
    std::cout << "\n\nBinary: " << s;
    std::cout << "\nGray: " << binarytoGray(s);

    s = "0010";
    std::cout << "\n\nGray: " << s;
    std::cout << "\nBinary: " << graytoBinary(s);

    s = "01101";
    std::cout << "\n\nGray: " << s;
    std::cout << "\Binary: " << graytoBinary(s);
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
