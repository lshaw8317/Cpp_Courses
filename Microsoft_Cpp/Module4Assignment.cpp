#include <iostream>
#include "Module4Assignment.h";
int main()
{
    //Pow func
    std::cout << "\nPower function";
    int ans1 = pow(2, 4);
    int ans2 = pow(4, 0);
    std::cout << "\nThe base is " << 2 << " and the exponent is " << 4 <<
        ". The answer is " << ans1;
    std::cout << "\nThe base is " << 4 << " and the exponent is " << 0 <<
        ". The answer is " << ans2;

    //Sine func
    std::cout << "\n\nSine function";
    double ans3 = sine(2, 4);
    double ans4 = sine(4, 1);
    std::cout << "\nThe opposite is " << 2 << " and the hypotenuse is " << 4 <<
        ". The answer is " << ans3;
    std::cout << "\nThe opposite is " << 4 << " and the hypotenuse is " << 1 <<
        ". The answer is " << ans4;

    //Avg func
    std::cout << "\n\nArray Avg function";
    int myArray[5] = { 1,2,3,4,5 };
    std::cout << "\nThe array is { 1,2,3,4,5 }, and the average is " << avg(myArray, sizeof(myArray) / sizeof(myArray[0])) ;
}