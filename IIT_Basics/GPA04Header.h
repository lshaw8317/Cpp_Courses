#pragma once
struct rational {
    int numerator;
    int denominator;
};

//Func1
void reduce(rational* inputrational, rational* outputrational) 
{
    int num = inputrational->numerator;
    int den = inputrational->denominator;
    if (num > den)
    {
        for (int j = den;j >= 2;j--)
        {
            if (num % j == 0 && den % j == 0)
            {
                num /= j;
                den /= j;
                break;
            }
        }
    }
    else if (den > num)
    {
        for (int j = num;j >= 2;j--)
        {
            if (num % j == 0 && den % j == 0)
            {
                num /= j;
                den /= j;
                break;
            }
        }
    }
    else //num=denom
    {
        num = 1;
        den = 1;
    }
    outputrational->denominator = den;
    outputrational->numerator = num;
}
//Func2
bool isEqual(rational num1, rational num2)
{
    rational* ptr1 = &num1;
    rational* ptr2 = &num2;
    rational red1;
    rational red2;
    reduce(ptr1, &red1);
    reduce(ptr2, &red2);
    if (red1.numerator == red2.numerator && red1.denominator == red2.denominator)
    { return true; }
    else { return false; }

}