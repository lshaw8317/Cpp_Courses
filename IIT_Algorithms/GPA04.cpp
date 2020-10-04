// GPA04.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
long long findMinHashDiff(std::string text, std::string pattern) {
    long long q = 1e9 + 7;
    long long h = pow(10, pattern.size() - 1);
    h = h % q;
    long long p=0, t = 0;
    for (int i = 0; i < pattern.size(); ++i) {
        p = (10 * p + (pattern[i] - '0')) % q;
        t = (10 * t + (text[i] - '0')) % q;
    }
    long long min = LLONG_MAX;
    for (int s = 0; s <= text.size() - pattern.size(); ++s) {
        if (abs(p-t)<min) {
            min = abs(p - t);
        }
        if (s < text.size() - pattern.size()) {
            t = (10 * (t - text[s] * h) + text[s + pattern.size() + 1]) % q;
        }
    }
    return min;
}
int main()
{
    std::cout << "Hello World!\n";
}
