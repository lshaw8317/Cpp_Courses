// GPA04.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<list>
#include <algorithm>    // std::set_intersection, std::sort
struct fbUser {
    int userID;
    std::list<int> friends;
    fbUser(int i, std::list<int> l) :userID(i), friends(l) {};
};
typedef struct fbUser fbUser; //save writing struct every time

//Helper funcs//
bool contains(std::list<int>& l, int i, std::list<int>::iterator &left, std::list<int>::iterator &right) {
    if (right == l.end() && left == l.end()) { return false; }//empty list l
    //list l should be sorted
    int d = std::distance(left, right) / 2;
    if (d == 0)//termination case for list of length 2 or less
    {
        if (right != l.end()) {return *left == i || *right == i;}
        else { return *left == i; }
    }
    if (*std::next(left, d) < i) { std::advance(left, std::distance(left, right) / 2);}//left<mid<i<right
    else { right=std::next(left, d); }//left<i<mid<right
    contains(l, i, left, right);
}
std::list<fbUser>::iterator advance_it2x(std::list<fbUser> &Users, int x) {
    std::list<fbUser>::iterator x_it = Users.begin();
    while (true) { 
        if ((*x_it).userID == x) { break; }
        x_it++; 
    }
    return x_it;
}

//Assignment Funcs//
//Number of mutual friends
int mutuals(int user1, int user2, std::list<fbUser> &Users) {
    std::list<fbUser>::iterator it1 = advance_it2x(Users, user1);
    std::list<fbUser>::iterator it2 = advance_it2x(Users, user2);
    int mutuals = 0;
    std::list<int>::iterator num_it1 = (*it1).friends.begin();
    for (;num_it1 != (*it1).friends.end();num_it1++) {
        std::list<int>::iterator left = (*it2).friends.begin();
        std::list<int>::iterator right = (*it2).friends.end();
        if (contains((*it2).friends, *num_it1, left, right)) { ++mutuals; }
    }
    return mutuals;
};
//Number of people friends with only x not anyone else
int uniques(int x, std::list<fbUser>& Users) {
    //Make sure friends lists are sorted (in ascending order)
    for (std::list<fbUser>::iterator it = Users.begin();it != Users.end();++it) {
        (*it).friends.sort();
    }

    std::list<fbUser>::iterator x_it = advance_it2x(Users, x);
    std::list<int>::iterator friend_it = (*x_it).friends.begin();
    int counter = 0;
    bool unique;
    for (;friend_it != (*x_it).friends.end();++friend_it) {
        std::list<fbUser>::iterator it = Users.begin();
        unique = true;
        while(it != Users.end()) {
            if ((*it).userID != x) {
                std::list<int>::iterator left = (*it).friends.begin();
                std::list<int>::iterator right = (*it).friends.begin();
                if (contains((*it).friends, *friend_it, left, right)) { unique = false; break; }
            }
            ++it;
        }
        counter += unique;
    }
    return counter;
}
//Number of strangers to x
int strangers(int x, std::list<fbUser>& Users) {
    //Make sure friends lists are sorted (in ascending order)
    for (std::list<fbUser>::iterator it = Users.begin();it != Users.end();++it) {
        (*it).friends.sort();
    }

    std::list<fbUser>::iterator x_it = advance_it2x(Users, x);
    std::list<int> non_strangers;
    std::list<int>::iterator friend_it = (*x_it).friends.begin();
    //loop through friends of x
    for (;friend_it != (*x_it).friends.end();++friend_it) {
        std::list<int>::iterator left = non_strangers.begin();
        std::list<int>::iterator right = non_strangers.end();
        if (!contains(non_strangers, *friend_it, left, right)) { non_strangers.insert(right, *friend_it); }

        left = non_strangers.begin();
        right = non_strangers.end();
        std::list<fbUser>::iterator y_it = advance_it2x(Users, *friend_it);
        std::list<int>::iterator y_friend_it = (*y_it).friends.begin();
        //loop through friends of a friend of x
        while (y_friend_it != (*y_it).friends.end()) {
            if (!contains(non_strangers, *y_friend_it, left, right)) { 
                non_strangers.insert(right, *y_friend_it);
            }
            left = non_strangers.begin();
            right = non_strangers.end();
            ++y_friend_it;
        }
    }
    //Loop over all possible friends
    int strangers = 0;
    for (std::list<fbUser>::iterator it = Users.begin();it != Users.end();++it) {
        std::list<int>::iterator left = (*x_it).friends.begin();
        std::list<int>::iterator right = (*x_it).friends.end();
        if (contains((*x_it).friends, (*it).userID, left, right)||(*it).userID==x) { continue; }//friend of x or is x, don't need to check
        else {//not friend of x, check how many friends are strangers to x
            left = non_strangers.begin();
            right = non_strangers.end();
            if (!contains(non_strangers, (*it).userID, left, right)) { ++strangers; }//user is stranger
            for (std::list<int>::iterator sub_it = (*it).friends.begin();sub_it != (*it).friends.end();++sub_it) {
                left = non_strangers.begin();
                right = non_strangers.end();
                if (!contains(non_strangers, *sub_it, left, right)) { ++strangers; }
            }
        }
    }
    return strangers;
}

int main()
{
    fbUser Avik(0, { 1, 2 });
    fbUser Barath(1, { 2, 3, 4, 5, 6 });
    fbUser Chetty(2, { 4,5,6,7,8 });
    fbUser Dinash(3, { 6,7,8,9,10,11,12,13,14 });
    std::list<fbUser> Users{ Avik,Barath,Chetty,Dinash };
    std::cout << "1. Mutual friends between Chetty(2) and Barath(1): answer should be 3\n";
    std::cout << mutuals(1,2,Users); 
    std::cout << "\n\n2. Unique friends of Avik(0): answer should be 1\n";
    std::cout << uniques(0,Users); //correct
    std::cout << "\n\n3. Strangers to Avik(0): answer should be 6\n";
    std::cout << strangers(0, Users); //correct
}
