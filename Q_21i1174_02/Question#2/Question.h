#pragma once
#include<string>
using namespace std;
class Question {
    private :
    string getting_question;
    int correct_answer;
    public :
    Question();
    void set_answers(int );
    void set_questions(const string);
    // void display_output();
    int get_answers();
    string get_question();
};