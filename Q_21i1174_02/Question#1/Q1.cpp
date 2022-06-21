#include <iostream>
#include <time.h>
#include "Student.cpp"

using namespace std;
void increasing_size_of_array(Student *&oldArr, const int count)
{
    Student *newArr = new Student[count];
    for (int i = 0; i < count - 1; i++)
    {
        newArr[i] = oldArr[i];
    }
    // copy(oldArr, oldArr + (count - 1), newArr);
    delete[] oldArr;
    oldArr = newArr;
    newArr = 0;
}
void Choose_coursesCode(Student students[], int j)
{
    int choose[5] = {0, 0, 0, 0, 0};
    bool choose_check = false;
    cout << "You have to pick 5 courses, Choose the course codes : ";
    for (int i = 0; i < 5; i++)
    {
        cout << "\n1.Physics \n2.Chemistry  \n3.Intro to SE \n4.Calculus \n5.Islamiat \n6.Communication\n7.PF\n8.Linear Algebra\n Choose from the menu : ";
        cin >> choose[i];
        while (choose[i] > 8 || choose[i] < 1)
        cin >> choose[i];
        for (int k = 0; k < i; k++)
        {
            if (choose[k] == choose[i])
            {
                choose_check = true;
            }
        }
        while (choose_check)
        {
            for (int k = 0; k < i; k++)
            {
                if (choose[k] == choose[i])
                {
                    cout << "Course Already registered ! Choose Again : ";
                    choose_check = false;
                }
            }
            cin >> choose[i];
            while (choose[i] > 8 || choose[i] < 1)
            {
                cout << "Not choosing from the menu, Choose again : ";
                 cin >> choose[i];
            }
            for (int k = 0; k < i; k++)
            {
                if (choose[k] == choose[i])
                {
                    choose_check = true;
                }
            }
        }
        students[j].set_CourseCode(choose[i] - 1, i);
    }
}

void Display_courses(Student students[], int enter_the_number_of_students)
{
    int rollNo;
    bool rollNo_check = false;
    int storing_i;
    cout << "Enter the student roll # ";
    cin >> rollNo;
    for (int i = 0; i < enter_the_number_of_students; i++)
    {
        if (students[i].get_RollNumber() == rollNo)
        {
            rollNo_check = true;
            storing_i = i;
        }
    }
    if (rollNo_check)
        students[storing_i].DisplayCourses();
    else
        cout << "The roll No entered is incorrect !\n";
}
void Display_grades(Student students[], int enter_the_number_of_students)
{
    int rollNo;
    bool rollNo_check = false;
    int storing_i;
    cout << "Enter the student roll # ";
    cin >> rollNo;
    for (int i = 0; i < enter_the_number_of_students; i++)
    {
        if (students[i].get_RollNumber() == rollNo)
        {
            rollNo_check = true;
            storing_i = i;
        }
    }
    if (rollNo_check)
        students[storing_i].DisplayGrade();
    else
        cout << "The roll No entered is incorrect !\n";
}
void Display_Transcript(Student students[], int enter_the_number_of_students)
{
    int rollNo;
    bool rollNo_check = false;
    int storing_i;
    cout << "Enter the student roll # ";
    cin >> rollNo;
    for (int i = 0; i < enter_the_number_of_students; i++)
    {
        if (students[i].get_RollNumber() == rollNo)
        {
            rollNo_check = true;
            storing_i = i;
        }
    }
    if (rollNo_check)
        students[storing_i].Display();
    else
        cout << "The roll No entered is incorrect !\n";
}
void comparing_Students(Student students[], int enter_the_number_of_students)
{
    int choose;
    float highest;
    cout << "\n1.Physics \n2.Chemistry  \n3.Intro to SE \n4.Calculus \n5.Islamiat \n6.Communication\n7.PF\n8.Linear Algebra\n Choose from the menu : ";
    cin >> choose;
    highest = Student::comparesStudent(choose - 1);
    cout << highest << endl;
    for (int i = 0; i < enter_the_number_of_students; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (students[i].get_score(j) == highest)
            {
                cout << "Roll Number : " << students[i].get_RollNumber() << "\n Batch : " << students[i].get_Batch() << '\n'
                     << students[i].get_Name() << " has the highest marks in " << Student::CoursesNames[choose - 1] << " that is " << students[i].get_score(j) << '\n';
            }
        }
    }
}
void sort_students(Student students[], int enter_the_number_of_students)
{
    Student::sortStudents(students, enter_the_number_of_students);
}
void setting_student_Data(Student students[], const int enter_the_number_of_students)
{
    students[enter_the_number_of_students - 1].set_RollNumber(enter_the_number_of_students);
    students[enter_the_number_of_students - 1].set_Name();
    students[enter_the_number_of_students - 1].set_Batch();
    students[enter_the_number_of_students - 1].set_NumberOfCoursesRegistered();
    cout << "Course Registeration for Student " << students[enter_the_number_of_students - 1].get_Name() << endl;
    Choose_coursesCode(students, enter_the_number_of_students - 1);
    students[enter_the_number_of_students - 1].set_score();
    students[enter_the_number_of_students - 1].set_grades();
}
int main()
{
    int enter_the_number_of_students, choose = 0;
    cout << "Initially ! Enter the number of students ";
    cin >> enter_the_number_of_students;
    Student *students = new Student[enter_the_number_of_students];
    for (int i = 0; i < enter_the_number_of_students; i++)
    {
        cout << "Enter data for Student : " << i + 1 << '\n';
        students[i].set_RollNumber(i + 1);
        students[i].set_Name();
        students[i].set_Batch();
        students[i].set_NumberOfCoursesRegistered();
        cout << "Course Registeration for Student " << students[i].get_Name() << endl;
        Choose_coursesCode(students, i);
        students[i].set_score();
        students[i].set_grades();
    }
    while (choose != 7)
    {
        cout << "Choose from the given menu to perform your desire action : \n1.Add new Student\n2.Display Courses\n3.Display Grades\n4.Display Transcript \n5.Compare Students Grade\n6.Sort Students\n7.End\n  Choose : ";
        cin >> choose;
        if (choose >= 1 && choose <= 7)
            switch (choose)
            {
            case 1:
                increasing_size_of_array(students, ++enter_the_number_of_students);
                // sort_students(students, enter_the_number_of_students);
                setting_student_Data(students, enter_the_number_of_students);
                break;
            case 2:
                Display_courses(students, enter_the_number_of_students);
                break;
            case 3:
                Display_grades(students, enter_the_number_of_students);
                break;
            case 4:
                Display_Transcript(students, enter_the_number_of_students);
                break;
            case 7:
                choose = 7;
                break;
            case 5:
                comparing_Students(students, enter_the_number_of_students);
                break;
            case 6:
                sort_students(students, enter_the_number_of_students);
                break;

            default:
                cout << "nothing . . . " << endl;
                break;
            }
    }
    delete[] students;
    return 0;
}