
#include <iostream>
#include "GPA05.h"
#include <vector>

int main()
{
    binaryTree bst (2);
    bst.a = std::vector<int>{ 1, 2, 3, 4, 5, 6, 7 };
    std::cout << "Tree 1";
    std::cout << "\nPostorder: " + postOrderRepn(bst,0);
    std::cout << "\nPreorder: " + preOrderRepn(bst, 0);
    std::cout << "\nHeight: "+ numberToString(heightOfBinaryTree(bst));

    bst.a = std::vector<int>{ 10, 6, 15, 3, 8, 11, 17 };
    std::cout << "\nTree 2";
    std::cout << "\nPostorder: " + postOrderRepn(bst, 0);
    std::cout << "\nPreorder: " + preOrderRepn(bst, 0);
    std::cout << "\nHeight: " + numberToString(heightOfBinaryTree(bst));

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
