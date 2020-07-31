#pragma once

#include <iostream>
#include <cstring>
using namespace std;
//PPA01
struct  student {

    string name;

    int age;

    float marks;

};
student* initiateStudent(string name, int age, float marks)
{
    student* s = new student;
    s->name = name;
    s->age = age;
    s->marks = marks;
    return s;
   
}
student* highestScorer(student** stud, int totalStudents)
{
    int i = 0;
    float maxmarks = stud[i]->marks;
    int maxstud = i;
    i++;
    do{
        if (stud[i]->marks > maxmarks) 
        {
            maxmarks = stud[i]->marks;
            maxstud = i;
        }
        i++;
    } while (i < totalStudents);
    return stud[maxstud];
}
