#pragma once
using namespace std;
class Student
{
private:
    bool availiability;
    int rollNo;
    char name[15];
    int Batch;
    int NumberOfRegisteredCourses;
    char grade_of_student[5];
    int CourseCode_of_student[5];
    float score[5];
    double CGPA;
    static float highest_score_of_the_coruse[];
    static const int CourseCode[];
    static float score_in_a_course[];

public:
    static const char *CoursesNames[];
    // provide definitions of following functions...
    Student(); // default constructor
    Student(char *);
    Student(double);
    // Student(const Student &);
    void set_RollNumber(int);
    int get_RollNumber();
    void set_Name();
    char *get_Name();
    void set_Batch();
    int get_Batch();
    float get_CGPA();
    void set_NumberOfCoursesRegistered();
    int get_NumberOfCoursesRegistered();
    void set_CourseCode(int, int);
    int get_CourseCode(int);
    void set_score();
    float get_score(int);
    void set_grades();
    friend class Counsellor;
    // you have to implement the following functions
    //  think about the parameters required and return type of the following
    void DisplayCourses();                    // displays the courses Student is registered in
    void DisplayGrade();                      // display grades in each course
    void Display();                           // displays the transcript
    static float comparesStudent(int);        // static function that returns the student with better score in a given course
    static void sortStudents(Student[], int); // static function that sorts the students in ascending order on the basis of GPA
    // ~Student();
};
class Counsellor
{
private:
    Student *student_assigned_to_counsellor; // one member of this class is list of students assigned to a counsellor
    int number_of_students;
    // name, ID,
    string name;
    int id;

public:
    // implement necessary constructors
    static int counsellor_count;
    Counsellor();
    Counsellor(string);
    Counsellor(int);
    void set_id(int);
    void set_number_of_students(int);
    int get_number_of_students();
    friend void see_counseller_students(Counsellor counseller_data[], int number_of_counsellor);
    friend void Display_students(Counsellor &counsellor);
    void assigning_students(int, const int, Student[]);
    void operator+=(Student &);         // adds a student against the counsellor
    void operator-=(Student &);         // removes the student against the counsellor
    void operator[](string);            // Prints the information of the student whose name is given as the argument
    operator string();                  // converts counsellor information into a string
    Counsellor* operator+(Counsellor &); // add the students of two counsellors and create a third one
    bool operator==(Counsellor &);      // checks if both the counsellors are assigned same number of students
    bool operator<(Counsellor &);       // returns true if a counsellor is assigned less student than the other (RHS)
    bool operator>(Counsellor &);       // returns true if a counsellors is assigned more students than the other (RHS)
    ~Counsellor();
};