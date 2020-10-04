// GPA03.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

double NewtonRaphson(double Function (double), double Derivative (double), double start, double accuracy) {
    double xi = start; double f = Function(xi); double d = Derivative(xi);
    while (abs(f) > accuracy) {
        if (abs(d) < 1e-10) { std::cout << "Derivative close to 0; algorithm exited."; return -1; }
        xi -= f / d;
        f = Function(xi); d = Derivative(xi);
    }
    return xi;
}
//Function 1
double f1(double x) {return x * x;} double f1_(double x) {return 2*x;}
//Function 2
double f2(double x) { return exp(x) - 2; } double f2_(double x) { return exp(x); }


int main()
{
    std::cout << "Function 1, x^2\nRoot = " << NewtonRaphson(f1, f1_, -1.0, 1e-15) << std::endl;
    std::cout << "\nFunction 2, e^x-2\nRoot = " << NewtonRaphson(f2, f2_, -1.0, 1e-15) << std::endl;

}

