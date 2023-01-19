#include "student.h"
#include <time.h>

static int highestNumber = 99999;

Student::Student()
{
    next = this;
    prev = this;
    number = -1;
}
Student::Student(string ln, string fn)
{
    lastname = ln;
    firstname = fn;
    number = highestNumber+1;
    highestNumber++;
}
Student::Student(string ln, string fn, int n)
{
    lastname = ln;
    firstname = fn;
    number = n;
    next = nullptr;
    prev = nullptr;
}
string Student::GetLastname()
{
    return lastname;
}

string Student::GetFirstname()
{
    return firstname;
}

int Student::GetNumber()
{
    return number;
}
