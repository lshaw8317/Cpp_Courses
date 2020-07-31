// GPA01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
    //PPA03
    int RPM, num, rem, limit, crs, crscount;
    cout << "GPA 01" << endl;
    cout << "Give an RPM" << endl;
    cin >> RPM;
    limit = 8 * RPM;
    int sum = RPM;
    for (int numyears = 1; ;numyears++)
    {
        num = sum;
        sum = 0;
        crs = 0;
        //Get sum of squares
        for(int crscount=1; ;crscount++)
        {
            rem = num % 10;
            sum += rem * rem;
            num = (num - rem) / 10;
            if (num == 0) { break; }
            if (crscount > 1 && crscount < 4) { crs += (crscount == 3)?(rem * 10) : (rem); } //Get cyclic right shift total
        }
        sum *= 323; //multiply sum of squared digits by 323
        sum += crs; //Add last two digits from crs
        int newRPM = sum;
        if (newRPM > limit)
        {
            cout << RPM << "rpm will go bad in " << numyears << " years, when the RPM will be "<< newRPM << endl;
            break;
        }
        if (numyears >= 10)
        {
            cout << RPM << " will be fine for at least 10 years." << " After 10 years the RPM is " << newRPM << endl;
            break;
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
