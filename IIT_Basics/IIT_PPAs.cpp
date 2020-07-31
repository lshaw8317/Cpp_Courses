// IIT_PPAs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include "PracProgsFuncs.h"

using namespace std;

int main()
{
    /*
    //PPA01
    cout << "PPA 01" << endl;
    int age, ageResult;
    cout << "What is your age?" << endl;
    cin >> age;
    if ((age / 102) > 0 || age < 0) { ageResult = -1; }
    else
    {
        switch (age / 6)
        {
        case 0:
            ageResult = 0;
            break;
        case 1:
            ageResult = 1;
            break;
        case 2:
            ageResult = ((age % 6) == 0) ? (1) : (2);
            break;
        case 3:
            ageResult = ((age % 6) < 2) ? (2) : (3);
            break;
        default:
            switch (age / 50)
            {
            case 0:
                ageResult = 3;
                break;
            case 1:
                ageResult = ((age % 50) == 0) ? (3) : (4);
                ageResult = (age > 60) ? (ageResult + 1) : (ageResult);
                break;
            default:
                ageResult = 5;
            }
        }
    }
    cout << "Your age is in group: " << ageResult;

    //PPA02
    int sqdnumber, rem, num;
    int sum = 0;
    cout << "\n\nPPA 02" << endl;
    cout << "Pick an integer" << endl;
    cin >> sqdnumber;
    num = sqdnumber;
    while (true)
    {
        rem = num % 10;
        sum += rem * rem;
        num = (num - rem) / 10;
        if (num == 0) { break; }

    }
    cout << "Sum of squared digits of " << sqdnumber << " = " << sum << endl;
    
    //PPA03
    int basenumber, num, rem;
    cout << "\n\nPPA 03" << endl;
    cout << "Pick an integer" << endl;
    cin >> basenumber;
    int sum = basenumber;
    for (int numcycles = 1;;numcycles++)
    {
        num = sum;
        sum = 0;
        while (true)
        {
            rem = num % 10;
            sum += rem * rem;
            num = (num - rem) / 10;
            if (num == 0) { break; }
        }
        if (sum == 1)
        {
            cout << basenumber << " is a happy number within " << numcycles << " cycles." << endl;
            break;
        }
        if (numcycles >= 10)
        {
            cout << basenumber << " is not a happy number within 10 cycles." << " After 10 cycles the resultant value is " << sum << endl;
            break;
        }
    }


    //PracProgs//

    //Basic Prog 1
    get_area_perim();
    //Basic Prog 2
    print_ASCII();
    //Basic Prog 3
    get_frac();
    //Basic Prog 4
    print_expans();

    //Cond Prog 1
    swap();
    //Cond Prog 2
    tablet_select();
    //Cond Prog 3
    right_angle_check();
    //Cond Prog 4
    leap_year();
    //Cond Prog 5
    check_vowel();

    //Iter Prog 1
    print_rect();
    //Iter Prog 2
    enter_nums();
    //Iter Prog 3
    print_pattern();
    //Iter Prog 4
    palind();
    //Iter Prog 5
    print_primes();
    //Iter Prog 6ab
    C_to_Fa();
    C_to_Fb();
    //Iter Prog 7
    reverse();
    //Iter Prog 8
    print_seq();
    //Func Prog 1
    int n;
    cout << "Enter a positive number: " << endl;
    cin >> n;
    cout << "The factorial of " << n << " is " << fact(n) << endl;
    //Func Prog 2
    int r;
    cout << "Enter n>0: " << endl;
    cin >> n;
    cout << "Enter r>0 and <n: " << endl;
    cin >> r;
    cout << "nCr is is " << nCr(n,r) << endl;

    //PPA 04
    int prices[5] = { 87000, 67000, 45000, 34000, 33000 };
    int buy,prof=prices[1]-prices[0];
    for (int i = 0;i < 5;i++)
    {
        buy = prices[i];
        for (int j = i+1;j < 5;j++)
        {
            if (prof < prices[j] - prices[i]) { prof = prices[j] - prices[i]; }
        }
    }
    cout << prof;
    //PPA 05 
    float studentmarks[8][2] = {
    {90, 30},
    {60, 20},
    {30, 40},
    {60, 20},
    {10, 90},
    {0, 100},
    {60, 20},
    {50,10} };
    float merger[8][2];
    int breakp = selectionSort2(studentmarks, 8);
    int numelements = merge(studentmarks, merger, breakp, 8);
    cout << numelements;

    for (int i = 0;i < numelements;i++)
    {
        cout << "\n";
        for (int j = 0;j < 2;j++)
        {
            cout << setw(4) << merger[i][j];
        }
        cout << endl;
    }

    //PPA06
    int m=5, n=2;
    int** Aptr;
    Aptr = new int* [m];
    getArray2D(m, n, Aptr);
    for (int i = 0;i < m;i++)
    {
        for (int j = 0;j < n;j++)
        {
            cout << setw(4) << Aptr[i][j];
        }
        cout << endl;
    }
    */

    //PPA07
    myNode* nodes;
    int* nodesArray;
    int num = 1;
    nodesArray = new int [1];
    nodes = new myNode[5];
    if (nodes != NULL)
    {
        initNodes(nodes, 5);
        addEdge(nodes, 1, 2);
        addEdge(nodes, 2, 4);
        addEdge(nodes, 5, 4);
        addEdge(nodes, 5, 5);
        addEdge(nodes, 3, 5);
        addEdge(nodes, 2, 3);
        getOutgoingNodes(nodes, 1, nodesArray, num);

        for (int j = 0;j < num;j++)
        {
            cout << nodesArray[j] << endl;
        }
    }


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
