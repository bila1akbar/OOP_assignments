#include<iostream>
#include"./Question.h"
#include<fstream>
#include<string>

using namespace std;
Question::Question()
{
    correct_answer=0;
    getting_question="\0";
}
void Question::set_questions(const string questions)
{
    getting_question=questions;
}
void Question::set_answers(int answer)
{
    correct_answer=answer;
}
int Question::get_answers()
{
    return correct_answer;
}
string Question::get_question()
{
    return getting_question;
}