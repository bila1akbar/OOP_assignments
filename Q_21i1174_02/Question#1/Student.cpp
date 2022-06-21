#include <iostream>
#include <time.h>
#include "Student.h"
#include <cstring>
using namespace std;
float Student::score_in_a_course[] = {0, 0, 0, 0, 0, 0, 0, 0};
float Student::highest_score_of_the_coruse[] = {0, 0, 0, 0, 0, 0, 0, 0};
// int Student::count(1);
const char *Student::CoursesNames[] = {"Physics", "Chemistry", "Intro to SE", "Calculus", "Islamiat", "Communication", "PF", "Linear Algebra"};
const int Student::CourseCode[] = {1, 2, 3, 4, 5, 6, 7, 8};
// int *Student::sorting_students= new int [count];
Student::Student()
{
    rollNo = 0;
    Batch = 0;
    NumberOfRegisteredCourses = 0;
    CGPA = 0;
}
Student::Student(double cgpa)
{
    rollNo = 0;
    Batch = 0;
    NumberOfRegisteredCourses = 0;
    CGPA = cgpa;
}
// Student::Student(const Student &x)
// {
//     Batch = x.Batch;
//     NumberOfRegisteredCourses = x.NumberOfRegisteredCourses;
//     rollNo = x.rollNo;
//     CGPA = x.CGPA;
//     name=x.name;
//     for (int i=0;i<5;i++)
//     {
//         name
//     }
// }
float Student::get_score(int choose)
{
    return score[choose];
}
void Student::set_Batch()
{
    srand(time(NULL));
    int x;
    x = rand() % (2022 - 2018 + 1) + 2018;
    Batch = x;
}
int Student::get_Batch()
{
    return Batch;
}

void Student::set_Name()
{
    cout << "Enter Student name : ";
    cin >> name;
}
char *Student::get_Name()
{
    return name;
}
void Student::set_RollNumber(int x)
{
    rollNo = x;
}
int Student::get_RollNumber()
{
    return rollNo;
}
void Student::set_NumberOfCoursesRegistered()
{
    NumberOfRegisteredCourses = 5;
}
int Student::get_NumberOfCoursesRegistered()
{
    return NumberOfRegisteredCourses;
}
void Student::set_CourseCode(int x, int count)
{
    CourseCode_of_student[count] = CourseCode[x];
}
int Student::get_CourseCode(int count)
{
    return CourseCode_of_student[count];
}
void Student::set_score()
{
    float x;
    srand(time(NULL));
    for (int i = 0; i < 5; i++)
    {
        x = 1 + (rand() % (100));
        score[i] = (x / 100) * 4;
        highest_score_of_the_coruse[CourseCode_of_student[i] - 1] = score[i];
        cout << highest_score_of_the_coruse[CourseCode_of_student[i] - 1] << endl;
    }
    for (int i = 0; i < NumberOfRegisteredCourses; i++)
    {
        CGPA = score[i] + CGPA;
    }
    CGPA = (CGPA / 20) * 4;
    for (int i = 0; i < 8; i++)
    {
        if (score_in_a_course[i] < highest_score_of_the_coruse[i])
            score_in_a_course[i] = highest_score_of_the_coruse[i];
    }
}

void Student::DisplayCourses()
{

    cout << "Roll Number : " << rollNo << "\nBatch : " << Batch << '\n'
         << name << " is registered in following courses : \n";
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (CourseCode_of_student[i] == CourseCode[j])
                cout << i + 1 << ".  " << CoursesNames[j] << endl;
        }
    }
}
void Student::set_grades()
{
    for (int i = 0; i < 5; i++)
    {
        if (score[i] >= 3.5)
            grade_of_student[i] = 'A';
        else if (score[i] >= 3 && score[i] < 3.5)
            grade_of_student[i] = 'B';
        else if (score[i] >= 2 && score[i] < 3)
            grade_of_student[i] = 'C';
        else if (score[i] >= 1 && score[i] < 2)
            grade_of_student[i] = 'D';
        else if (score[i] < 1)
            grade_of_student[i] = 'F';
    }
}
void Student::DisplayGrade()
{

    cout << "Roll Number : " << rollNo << "\nBatch : " << Batch << '\n'
         << name << " is registered in following courses : \n";
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (CourseCode_of_student[i] == CourseCode[j])
                cout << i + 1 << ".  " << CoursesNames[j] << "  Grade : " << grade_of_student[i] << endl;
        }
    }
}
void Student::Display()
{
    cout << "****************************************************\n";
    cout << "Student Name : " << name << endl;
    cout << "Student Roll #" << rollNo << endl;
    cout << "Batch :" << Batch << endl;
    cout << "CGPA of the Student is :" << CGPA << endl;
    cout << "CourseCode"
         << "  "
         << " CoursesNames"
         << "\t"
         << "Grade"
         << "  "
         << "GPA\n";
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (CourseCode_of_student[i] == CourseCode[j])
            {
                cout << CourseCode[j] << "\t\t" << CoursesNames[j] << " \t" << grade_of_student[i] << "\t" << score[i] << endl;
            }
        }
    }
    cout << "****************************************************\n";
}

float Student::comparesStudent(int coursecode)
{
    return score_in_a_course[coursecode];
}
int Student::get_CGPA()
{
    return CGPA;
}
void Student::sortStudents(Student student[], int enter_the_number_of_students)
{
    float temp;
    char char_temp[15], random;

    for (int i = 0; i < enter_the_number_of_students; i++)
    {
        for (int j = i + 1; j < enter_the_number_of_students; j++)
        {
            if (student[i].CGPA < student[j].CGPA)
            {
                temp = student[i].CGPA;
                student[i].CGPA = student[j].CGPA;
                student[j].CGPA = temp;
                temp = student[i].rollNo;
                student[i].rollNo = student[j].rollNo;
                student[j].rollNo = temp;
                temp = student[i].Batch;
                student[i].Batch = student[j].Batch;
                student[j].Batch = temp;

                for (int k = 0; k < 5; k++)
                {
                    temp = student[i].score[k];
                    student[i].score[k] = student[j].score[k];
                    student[j].score[k] = temp;
                    random = student[i].grade_of_student[k];
                    student[i].grade_of_student[k] = student[j].grade_of_student[k];
                    student[j].grade_of_student[k] = random;
                    temp = student[i].CourseCode_of_student[k];
                    student[i].CourseCode_of_student[k] = student[j].CourseCode_of_student[k];
                    student[j].CourseCode_of_student[k] = temp;
                }
                temp = student[i].NumberOfRegisteredCourses;
                student[i].NumberOfRegisteredCourses = student[j].NumberOfRegisteredCourses;
                student[j].NumberOfRegisteredCourses = temp;
                strcpy(char_temp, student[i].name);
                strcpy(student[i].name, student[j].name);
                strcpy(student[j].name, char_temp);
            }
        }
            
        
    }
    cout << "Sorted students are : \n";
            for (int i = 0; i < enter_the_number_of_students; i++)
            {
                cout << "Student Names \tROll #\tBatch\tCGPA\n"
                     << student[i].name << "\t\t" << student[i].rollNo << "\t" << student[i].Batch
                     << '\t' << student[i].CGPA << endl;
            }
}
// Student::~Student(){
// delete [] sorting_students;
// sorting_students=0;
// }