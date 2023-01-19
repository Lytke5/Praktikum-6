#ifndef COURSE_H
#define COURSE_H
#include <vector>
#include "student.h"

using namespace std;

class Course
{
public:
    Course(string n);
    string GetName();
    void ListStudents();
    Student* GetStudent(int number);
    void AddStudent(Student* s);
    Student* DeleteStudent(int number);
private:
    Student* list;
    string name;
    int count;

};

#endif // COURSE_H
