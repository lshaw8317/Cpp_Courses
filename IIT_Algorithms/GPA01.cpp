// GPA01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include<algorithm>
#include<list>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <chrono>
#include<random>
typedef std::vector<int>::iterator iter;
std::vector<int> n, w;
bool myComp(int n1, int n2) {
    if (w.at(n1) > w.at(n2)) { return true; } //sort be greatest weights first
    else if (w.at(n1) < w.at(n2)) { return false; }
    else {return n.at(n1) > n.at(n2);} //where weights are same, sort by greatest number first
}
/*
void merge(iter n1, iter n_mid, iter n_end, iter w1, iter w_mid, iter w_end){
    iter n2 = n_mid; iter w2 = w_mid;
    while (n1!=n_mid && n2!=n_end) {
        if (myComp(n1, n2, w1, w2)) { std::iter_swap(n1, n2); std::iter_swap(w1, w2); n1++; w1++; }
        else{ indices.push_back(start2); start2++; }
    }
    while (start1 != end1) { indices.push_back(start1); start1++; }
    while (start2 != end2) { indices.push_back(start2); start2++; }
    return;
}
void mysort(iter n_start, iter n_end, iter w_start, iter w_end) {
    int d = std::distance(n_start,n_end);
    if (d > 1) {
        mysort(n_start + d / 2,n_end, w_start + d / 2, w_end);
        mysort(n_start, n_start+d/2, w_start, w_start + d / 2);
        merge(n_start, n_start+d/2, n_end, w_start, w_start+d/2, w_end);
    }
    return;
}
*/
std::vector<int> customsort(std::vector<int> &num, std::vector<int> &weights) {
    std::vector<int> a; n = num; w = weights;
    for (int i = 0; i != num.size(); ++i) { a.push_back(i); }
    std::sort(a.begin(), a.end(),myComp);
    for (std::vector<int>::iterator it = a.begin(); it != a.end(); ++it) { *it = num[*it]; }
    return a;
}
int main()
{
    std::vector<int> weights { 2,9,5,9,8 };
    std::vector<int> num { 1,4,9,6,9 };
    std::vector<int> answer = customsort(num, weights);
    std::cout << "Test Case 1\nAnswer is: 6 4 9 9 1\nMy answer:";
    for (std::vector<int>::iterator it = answer.begin(); it != answer.end(); ++it) { std::cout << " " << *it; }

    //Random arrays
    std::default_random_engine generator;
    std::uniform_int_distribution<int> N_distribution(10000, 100000);

    for (int j = 2; j < 7; j++) {
        weights.clear(); num.clear();
        int N = N_distribution(generator);
        for (int i = 0; i < N; ++i) {
            num.push_back(10 + rand() % 90);
            weights.push_back(10 + rand() % 90);
        }
        // Get starting timepoint 
        auto start = std::chrono::high_resolution_clock::now();
        answer = customsort(num, weights);
        // Get ending timepoint 
        auto stop = std::chrono::high_resolution_clock::now();
        std::cout << "\n\nTest Case " << j << " for array of size " << N << "\nTime taken = " <<
            std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count() << " microseconds.";
        //for (std::vector<int>::iterator it = answer.begin(); it != answer.end(); ++it) { std::cout << " " << *it; }
    }
}
