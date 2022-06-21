#include <iostream>
#include <time.h>
#include "Counsellor.cpp"

using namespace std;
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
void sort_students(Student students[], int enter_the_number_of_students)
{
    Student::sortStudents(students, enter_the_number_of_students);
}
int main()
{
    Counsellor *resultant_counsellor = NULL;
    int enter_the_number_of_students, choose = 0, storing_counseller_id, storing_student_id, counsellor_id1, counsellor_id2;
    string temp_name;

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
    int number_of_counseller = 0;
    cout << "Enter the number of counsellor : ";
    cin >> number_of_counseller;
    Counsellor *counseller_data = new Counsellor[number_of_counseller];

    for (int i = 0; i < number_of_counseller; i++)
    {
        cout << "Assiginning students for counsellor#" << i + 1 << endl;
        counseller_data[i].assigning_students(i, enter_the_number_of_students, students);
    }
    while (choose != 10)
    {
        cout << "Choose from the menu \n1.See the students of a Counseller\n2.Add a student\n3.Remove a student\n4.Print Studnet information using name\n5.Adding the Students of two counseller\n6.(==) operation\n7.(<)operation\n8.(>)operation\n9.Counsellor data in string\n10.End\n Choose : ";
        cin >> choose;
        switch (choose)
        {
        case 1:
            see_counseller_students(counseller_data, number_of_counseller);
            break;
        case 2:
            cout << "Enter counseller id : ";
            cin >> storing_counseller_id;
            cout << " Enter student id : ";
            cin >> storing_student_id;
            counseller_data[storing_counseller_id - 1] += students[storing_student_id - 1];
            Display_students(counseller_data[storing_counseller_id - 1]);
            break;
        case 3:
            cout << "Enter counseller id : ";
            cin >> storing_counseller_id;
            cout << " Enter student id : ";
            cin >> storing_student_id;
            counseller_data[storing_counseller_id - 1] -= students[storing_student_id - 1];
            Display_students(counseller_data[storing_counseller_id - 1]);
            break;
        case 4:
            cout << "Enter counseller id : ";
            cin >> storing_counseller_id;
            cout << "Enter the name of the student : ";
            cin >> temp_name;
            the_subscript_operator(counseller_data[storing_counseller_id - 1], temp_name);
            break;
        case 5:
            cout << "Enter first counseller  id : ";
            cin >> counsellor_id1;
            cout << "Enter secound counseller id : ";
            cin >> counsellor_id2;
            if (resultant_counsellor != NULL)
            delete  resultant_counsellor;
            resultant_counsellor = new Counsellor(0);
            resultant_counsellor = counseller_data[counsellor_id1 - 1] + counseller_data[counsellor_id2 - 1];
                Display_students(*resultant_counsellor);
            break;
        case 6:
            cout << "Enter first counseller  id : ";
            cin >> counsellor_id1;
            cout << "Enter secound counseller id : ";
            cin >> counsellor_id2;
            cout << "The given condition (==) is : " << (counseller_data[counsellor_id1 - 1] == counseller_data[counsellor_id2 - 1]) << endl;
            break;
        case 7:
            cout << "Enter first counseller  id : ";
            cin >> counsellor_id1;
            cout << "Enter secound counseller id : ";
            cin >> counsellor_id2;
            cout << "The given condition (<) is : " << (counseller_data[counsellor_id1 - 1] < counseller_data[counsellor_id2 - 1]) << endl;
            break;
        case 8:
            cout << "Enter first counseller  id : ";
            cin >> counsellor_id1;
            cout << "Enter secound counseller id : ";
            cin >> counsellor_id2;
            cout << "The given condition (>) is : " << (counseller_data[counsellor_id1 - 1] > counseller_data[counsellor_id2 - 1]) << endl;
            break;
        case 9:
            cout << "1.simple counsellor\n2.Resultant Counsellor : \n";
            cin >> choose;
            switch (choose)
            {
            case 1:
                cout << "Enter counseller id : ";
                cin >> storing_counseller_id;
                temp_name = counseller_data[storing_counseller_id - 1];
                cout << temp_name << endl;
                break;
            case 2:
                temp_name = *resultant_counsellor;
                cout << temp_name << endl;
                break;
            default:
                break;
            }

            break;
        case 10:
            break;
        default:
            cout << "\n\nNot choosing from the menu\n";
            break;
        }
    }
    delete[] students;
    delete[] counseller_data;
    delete resultant_counsellor;

    return 0;
}