#pragma once
class Student
{
private:
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
    void set_RollNumber(int );
    int get_RollNumber();
    void set_Name();
    char* get_Name();
    void set_Batch();
    int get_Batch();
    int get_CGPA();
    void set_NumberOfCoursesRegistered();
    int get_NumberOfCoursesRegistered();
    void set_CourseCode(int ,int );
    int get_CourseCode(int);
    void set_score();
    float get_score(int);
    void set_grades();
    // you have to implement the following functions
    //  think about the parameters required and return type of the following
    void DisplayCourses();  // displays the courses Student is registered in
    void DisplayGrade();    // display grades in each course
    void Display();         // displays the transcript
    static float comparesStudent(int); // static function that returns the student with better score in a given course
    static void  sortStudents( Student [],int);    // static function that sorts the students in ascending order on the basis of GPA
    // ~Student();
};