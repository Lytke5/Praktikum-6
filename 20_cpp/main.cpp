#include <iostream>
#include "student.h"
#include "course.h"
#include <vector>

using namespace std;

int main()
{
    int answer;
    vector<Course*> CourseList;
    vector<Student*> StudentList;

    do{
        do{
            system("cls");
            cout << "Welcome to the course management system!" << endl << endl;
            cout << "(1) List all courses with students" << endl << endl;
            cout << "(2) Add course" << endl <<endl;
            cout << "(3) Delete course" << endl <<endl;
            cout << "(4) Add student" << endl <<endl;
            cout << "(5) Add student to a course" << endl <<endl;
            cout << "(6) Show student" << endl << endl;
            cout << "(7) Delete student" << endl << endl;
            cout << "(8) Delete student from a course" << endl << endl;
            cout << "(9) Quit" << endl << endl;

            cin >>answer;
        }while (answer < 1 || answer > 9);

        system("cls");

        switch(answer)
        {
        case 1:
        {
            cout.width(20);
            cout.setf(ios::left);
            cout << "Lastname";
            cout.width(20);
            cout.setf(ios::left);
            cout << "Firstname";
            cout.width(20);
            cout.setf(ios::left);
            cout << "Number";
            cout << endl;

            for(int i = 0; i<CourseList.size(); i++) {     //bubblesort
               for(int j = i+1; j<CourseList.size(); j++)
               {
                  if(CourseList[j]->GetName() < CourseList[i]->GetName()) {
                     Course* temp = CourseList[i];
                     CourseList[i] = CourseList[j];
                     CourseList[j] = temp;
                  }
               }
            }
            for(int i = 0; i < CourseList.size(); i++)
            {
                CourseList[i]->ListStudents();
            }
            cout << "Press any key to continue" <<endl;
            char tmp;
            cin >> tmp;
            break;
        }
        case 2:
        {
            string courseName;
            cout << "Name of the new course: ";
            cin >> courseName;
            Course* newCourse = new Course(courseName);
            CourseList.push_back(newCourse);
            cout << "Course " << courseName << " was added!" << endl;
            cout << "Press any key to continue" <<endl;
            char tmp;
            cin >> tmp;
            break;
        }
        case 3:
        {
            int success = false;
            string courseName;
            cout << "Name of course to delete: ";
            cin >> courseName;

            for(int i = 0; i < CourseList.size(); i++)
            {
                if(CourseList[i]->GetName() == courseName)
                {
                    CourseList[i] = CourseList[CourseList.size()-1];
                    CourseList.pop_back();
                    success = true;
                }
            }
            if(success)
                cout << courseName << " was deleted" << endl;
            else
                cout << courseName << " is not a course" << endl;

            cout << "Press any key to continue" <<endl;
            char tmp;
            cin >> tmp;
            break;
        }

        case 4:
        {
            string lastName;
            string firstName;
            string courseName;
            cout<<"Lastname of the new student: ";
            cin >> lastName;
            cout<<"Firstname of the new student: ";
            cin >> firstName;
            Student* newStudent = new Student(lastName,firstName);
            StudentList.push_back(newStudent);
            cout << "Created new student with the number " << newStudent->GetNumber() << "!" << endl;
            cout << "Press any key to continue" <<endl;
            char tmp;
            cin >> tmp;
            break;
        }
        case 5:
        {
            string courseName;
            int number;
            Student* currStudent;
            cout << "Name of the course: ";
            cin >> courseName;
            cout << "Number of the student: ";
            cin >> number;

            for(int i = 0; i < StudentList.size(); i++) // find student
            {
                if(StudentList[i]->GetNumber() == number)
                {
                    currStudent = new Student(StudentList[i]->GetLastname(), StudentList[i]->GetFirstname(), StudentList[i]->GetNumber());
                }
            }
            for(int i = 0; i < CourseList.size(); i++) // find course
            {
                if(CourseList[i]->GetName() == courseName)
                {
                    CourseList[i]->AddStudent(currStudent);
                }
            }
            cout << "Student was added to " << courseName <<endl;

            cout << "Press any key to continue"<<endl;
            char tmp;
            cin >> tmp;
            break;
        }

        case 6:
        {
            int number;
            cout<<"Number of the student: ";
            cin>>number;
            Student* currStudent;
            bool found = false;
            for(int i = 0; i < StudentList.size(); i++) // find student
            {
                if(StudentList[i]->GetNumber() == number)
                {
                    currStudent = StudentList[i];
                    found = true;
                }
            }
            cout << endl;
            if(found)
            {
                cout << "Lastname: " << currStudent->GetLastname() << endl;
                cout << "Firstname: " << currStudent->GetFirstname() << endl;
            }
            else
                cout << "Student does not exist" << endl;

            cout << "Press any key to continue"<<endl;
            char tmp;
            cin >> tmp;
            break;
        }
        case 7:
        {
            int number;
            Student* currStudent;
            cout<<"Number of the student: ";
            cin>>number;

            bool found = false;
            for(int i = 0; i < CourseList.size(); i++)
            {
                currStudent = CourseList[i]->DeleteStudent(number);
                found = true;
            }
            if(found)
            {
                delete(currStudent);
                cout << "Student was deleted." << endl;
            }
            else
                cout << "Student does not exist" << endl;

             cout << "Press any key to continue" << endl;
            char tmp;
            cin >> tmp;
            break;
        }
        case 8:
        {
            string courseName;
            int number;
            cout << "Name of the course: ";
            cin >> courseName;
            cout << "Number of the student: ";
            cin >> number;

            for(int i = 0; i < CourseList.size(); i++) // find course
            {
                if(CourseList[i]->GetName() == courseName)
                {
                    CourseList[i]->DeleteStudent(number);
                }
            }
            cout << "Student was deleted from course " << courseName << endl;
            cout << "Press any key to continue" << endl;
            char tmp;
            cin >> tmp;
            break;
        }
        }

    } while (answer < 9);
    cout << "Good bye!" << endl;
            return 0;
}
