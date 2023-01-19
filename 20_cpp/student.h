#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <vector>

using namespace std;


class Student
{
public:
    Student();
    Student(string ln, string fn);
    Student(string ln, string fn, int n);
    string GetLastname();
    string GetFirstname();
    int GetNumber();
    Student* prev;
    Student* next;

private:
    string lastname;
    string firstname;
    int number;
};

#endif // STUDENT_H
