// GPA02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "GPA02.h"

int main()
{
    std::cout << "/+2b-3a -> "<<prefix_to_infix("/+2b-3a");
    std::cout << "\n*-/+2b-3a+9u*5y -> " << prefix_to_infix("*-/+2b-3a+9u*5y");
    std::cout << "\n/*^ab-+*decfg -> " << prefix_to_infix("/*^ab-+*decfg");
}