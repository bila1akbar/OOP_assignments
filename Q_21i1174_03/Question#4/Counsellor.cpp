#include <iostream>
#include <time.h>
#include "Counsellor.h"
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
    availiability = 1;
}
Student::Student(double cgpa)
{
    rollNo = 0;
    Batch = 0;
    NumberOfRegisteredCourses = 0;
    CGPA = cgpa;
    availiability = 1;
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
float Student::get_CGPA()
{
    return CGPA;
}
void Student::sortStudents(Student student[], int enter_the_number_of_students)
{
    float temp;
    char char_temp[15], random;
    bool temp_avail;
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
                temp_avail = student[i].availiability;
                student[i].availiability = student[j].availiability;
                student[j].availiability = temp_avail;
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
// ***********************************************************************************************
// *********************************************Counsellor****************************************
// ***********************************************************************************************
int Counsellor::counsellor_count(0);
Counsellor::Counsellor(int)
{
    id = 0;
    name = " ";
}
Counsellor::Counsellor(string no_use)
{
    cout << "Enter the name of the resultant counsellor : ";
    cin >> name;
    id = counsellor_count + 1;
}
Counsellor::Counsellor()
{
    counsellor_count++;
    id = counsellor_count;
    number_of_students = 0;
    cout << "Enter the name of the counsellor#" << counsellor_count << " : ";
    cin >> name;
    cout << "Enter the number of student Counsellor#" << counsellor_count << " will have : ";
    cin >> number_of_students;
    student_assigned_to_counsellor = new Student[number_of_students];
}
void Counsellor::set_id(int x)
{
    id = x;
}

void Counsellor::assigning_students(int counsellor_id, const int enter_the_number_of_students, Student students[])
{
    int choose = 0, pick_student = 0, student_limit = 0;
    while (choose != 2)
    {
        if (student_limit == number_of_students)
        {
            cout << "Cant choose any more students ! \n";
            return;
        }
        cout << "Choose :\n1.Pick a Student by their roll#\n2.End\n Choose :";
        cin >> choose;

        switch (choose)
        {
        case 1:

            for (int j = 0; j < number_of_students; j++)
            {
                cout << "ROll #\tStudent Name\tBatch\tCGPA\n";
                for (int i = 0; i < enter_the_number_of_students; i++)
                {
                    if (students[i].availiability)
                    {
                        cout << students[i].rollNo << ".\t" << students[i].name << "\t\t" << students[i].Batch
                             << '\t' << students[i].CGPA << endl;
                    }
                }
                cout << enter_the_number_of_students + 1 << ". End\n";
                cin >> pick_student;
                cout << endl;
                if (pick_student == (enter_the_number_of_students + 1))
                    break;
                else if (students[pick_student - 1].availiability)
                {
                    student_assigned_to_counsellor[j] = students[pick_student - 1];
                    students[pick_student - 1].availiability = 0;
                    student_limit++;
                }
                else
                {
                    cout << "Student is not availiable ! Choose again\n";
                    j--;
                }
            }
            break;
        case 2:
            break;
        default:
            break;
        }
    }
}
void increasing_assigned_student_array_size(Student *&oldArr, const int count)
{
    Student *newArr = new Student[count];
    for (int i = 0; i < count - 1; i++)
    {
        newArr[i] = oldArr[i];
    }
    delete[] oldArr;
    oldArr = newArr;
    newArr = NULL;
}
void Counsellor::operator+=(Student &single_student)
{
    for (int i = 0; i < number_of_students; i++)
    {
        if (student_assigned_to_counsellor[i].rollNo == single_student.rollNo)
        {
            cout << "Student is already present !\n";
            return;
        }
    }
    increasing_assigned_student_array_size(student_assigned_to_counsellor, ++number_of_students);
    student_assigned_to_counsellor[number_of_students - 1] = single_student;
}
void Counsellor::operator-=(Student &single_student)
{
    number_of_students--;
    int count = 0;
    Student *newArr = new Student[number_of_students];
    for (int i = 0; i < number_of_students + 1; i++)
    {
        if (student_assigned_to_counsellor[i].rollNo == single_student.rollNo)
            continue;
        else
        {
            newArr[count] = student_assigned_to_counsellor[i];
            count++;
        }
    }
    delete[] student_assigned_to_counsellor;
    student_assigned_to_counsellor = newArr;
    newArr = NULL;
}
void Counsellor::operator[](string name)
{
    int storing_index = 0;
    bool checking_storing_index = false;
    for (int i = 0; i < number_of_students; i++)
    {
        if (student_assigned_to_counsellor[i].name == name)
        {
            storing_index = i;
            checking_storing_index = true;
        }
    }
    if (true)
    {
            cout << "ROll #\tStudent Name\tBatch\tCGPA\n";
        cout << student_assigned_to_counsellor[storing_index].rollNo << ".\t" << student_assigned_to_counsellor[storing_index].name << "\t\t" << student_assigned_to_counsellor[storing_index].Batch
             << '\t' << student_assigned_to_counsellor[storing_index].CGPA << endl;
        cout << "Student is registered in the following courses : \n";
        cout << "\nCourseCode"
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
                if (student_assigned_to_counsellor[storing_index].CourseCode_of_student[i] == Student::CourseCode[j])
                {
                    cout << student_assigned_to_counsellor[storing_index].CourseCode[j] << "\t\t" << student_assigned_to_counsellor[storing_index].CoursesNames[j] << " \t" << student_assigned_to_counsellor[storing_index].grade_of_student[i] << "\t" << student_assigned_to_counsellor[storing_index].score[i] << endl;
                }
            }
        }
    }
}
Counsellor::operator string()
{
    string temp = " ";
    temp = temp + "Name : ";
    temp = temp + name;
    int x = id;
    int length = 1;
    while (x /= 10)
        length++;
    char *storing_id = new char[length];
    x = id;
    int i = 0;
    int result = 0;

    while (x > 0)
    {
        result = result * 10 + x % 10;
        storing_id[i] = result + 48;
        x /= 10;
        i++;
        result = 0;
    }
    temp = temp + "  ->  Id : ";
    for (int j = i - 1; j >= 0; j--)
    temp = temp + storing_id[j];
    delete[] storing_id;
    return temp;
}
void Counsellor::set_number_of_students(int x)
{
    number_of_students = x;
}
int Counsellor::get_number_of_students()
{
    return number_of_students;
}


Counsellor *Counsellor::operator+(Counsellor &counsellor_2)
{
    Counsellor* temp = new Counsellor("xyz");
    int count = 0;
    temp->number_of_students = number_of_students + counsellor_2.number_of_students;
    temp->student_assigned_to_counsellor = new Student[temp->number_of_students];
    for (int i = 0; i < number_of_students; i++, count++)
    {
        temp->student_assigned_to_counsellor[count] = student_assigned_to_counsellor[i];
        // cout << temp.student_assigned_to_counsellor[count].get_RollNumber() << " " << temp.student_assigned_to_counsellor[count].get_Name() << " " << temp.student_assigned_to_counsellor[count].get_Batch() << " " << temp.student_assigned_to_counsellor[count].get_CGPA() << endl;
    }
    for (int i = 0; count < temp->number_of_students; i++, count++)
    {
        temp->student_assigned_to_counsellor[count] = counsellor_2.student_assigned_to_counsellor[i];
        // cout << temp.student_assigned_to_counsellor[count].get_RollNumber() << " " << temp.student_assigned_to_counsellor[count].get_Name() << " " << temp.student_assigned_to_counsellor[count].get_Batch() << " " << temp.student_assigned_to_counsellor[count].get_CGPA() << endl;
    }

    return temp;
}
bool Counsellor::operator==(Counsellor &counsellor_2)
{
    if (number_of_students == counsellor_2.number_of_students)
        return 1;
    else
        return 0;
}
bool Counsellor::operator<(Counsellor &counsellor_2)
{
    if (number_of_students < counsellor_2.number_of_students)
        return 1;
    else
        return 0;
}
bool Counsellor::operator>(Counsellor &counsellor_2)
{
    if (number_of_students > counsellor_2.number_of_students)
        return 1;
    else
        return 0;
}
Counsellor::~Counsellor()
{
    cout << "Destructor called ! \n";
    delete[] student_assigned_to_counsellor;
}
// ***********************************************************************
// ************************Global Functions*******************************
// ***********************************************************************
void see_counseller_students(Counsellor counseller_data[], int number_of_counsellor)
{
    int storing_id;
    cout << "Enter counseller id : ";
    cin >> storing_id;
    cout << "ROll #\tStudent Name\tBatch\tCGPA\n";
    for (int i = 0; i < counseller_data[storing_id - 1].number_of_students; i++)
    {
        cout << counseller_data[storing_id - 1].student_assigned_to_counsellor[i].get_RollNumber() << ".\t" << counseller_data[storing_id - 1].student_assigned_to_counsellor[i].get_Name() << "\t" << counseller_data[storing_id - 1].student_assigned_to_counsellor[i].get_Batch()
             << '\t' << counseller_data[storing_id - 1].student_assigned_to_counsellor[i].get_CGPA() << endl;
    }
}
void Display_students(Counsellor &counsellor)
{
    cout << "ROll #\tStudent Name\tBatch\tCGPA\n";
    for (int i = 0; i < counsellor.number_of_students; i++)
    {
        cout << counsellor.student_assigned_to_counsellor[i].get_RollNumber() << ".\t" << counsellor.student_assigned_to_counsellor[i].get_Name() << "\t\t" << counsellor.student_assigned_to_counsellor[i].get_Batch()
             << '\t' << counsellor.student_assigned_to_counsellor[i].get_CGPA() << endl;
    }
}
void the_subscript_operator(Counsellor &temp_counsellor, string temp_name)
{
    temp_counsellor[temp_name];
}
