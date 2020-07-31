#pragma once
//Functions
using namespace std;
//Pow
int pow(int base, unsigned int exp)
{
    if (exp == 0) { return 1; }
    else
    {
        int result = 1;
        for (int i = 0;i < exp;i++)
        {
            result *= base;
        }
        return result;
    }
}

//Sine
double sine(double opp, double hyp)
{
    return opp / hyp;
}

//Avg
double avg(int AnArray[], unsigned int array_size)
{
    double tot = 0;
    for (int i=0; i<array_size;i++)
    {
        tot += AnArray[i];
    }
    tot /= array_size;
    return tot;
}