#include "course.h"
#include <iostream>

Course::Course(string n)
{
    list = new Student();
    name = n;
    count = 0;
}

string Course::GetName()
{
    return name;
}

void Course::ListStudents()
{
    Student* currStudent = nullptr;

    cout << endl << "~~~~~~~~~~~~~~~~~~ " << name << " ~~~~~~~~~~~~~~~~~~" << endl << endl;

    if(count > 0)
    {
        vector<Student*> StudentList;
        currStudent = list;

        for(int i = 0; i < count; i++)
        {
            currStudent = currStudent->next;
            StudentList.push_back(currStudent);
        }

        for(int i = 0; i<StudentList.size(); i++) {     //bubblesort
           for(int j = i+1; j<StudentList.size(); j++)
           {
              if(StudentList[j]->GetLastname() < StudentList[i]->GetLastname()) {
                 Student* temp = StudentList[i];
                 StudentList[i] = StudentList[j];
                 StudentList[j] = temp;
              }
           }
        }

        for(int i = 0; i < count; i++)
        {
            cout.width(20);
            cout.setf(ios::left);
            cout << StudentList[i]->GetLastname();
            cout.width(20);
            cout.setf(ios::left);
            cout << StudentList[i]->GetFirstname();
            cout.width(20);
            cout.setf(ios::left);
            cout << StudentList[i]->GetNumber();
            cout << endl;
        }
    }
}

Student* Course::GetStudent(int number)
{
    Student* currStudent = nullptr;
    if(count > 0)
    {
        currStudent = list->next;

        for(int i = 0; i < count; i++)
        {
            if(currStudent->GetNumber() == number)
            {
                return currStudent;
            }
            currStudent = currStudent->next;
        }
    }
    return nullptr;
}

void Course::AddStudent(Student* s)
{
    s->prev = list;
    s->next = list->next;
    list->next = s;
    s->next->prev = s;

    count++;
}

Student* Course::DeleteStudent(int number)
{           
    Student* s = list->next;

        while (s->GetNumber() != number || s->GetNumber() == -1)
        {
            s = s->next;
        }
        s->next->prev = s->prev;
        s->prev->next = s->next;
        count--;
        return s;
}
