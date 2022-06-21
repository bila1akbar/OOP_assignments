#include <iostream>
#include "Question.cpp"
#include <fstream>
using namespace std;
void setting_data(Question question[])
{
string string_Questions[20];
    ifstream text_file;
    text_file.open("Question.txt", ios::in);
    while (!text_file.eof())
    {
        getline(text_file, string_Questions[0], '\n');
        getline(text_file, string_Questions[1], '\n');
        getline(text_file, string_Questions[2], '\n');
        getline(text_file, string_Questions[3], '\n');
        getline(text_file, string_Questions[4], '\n');
        getline(text_file, string_Questions[5], '\n');
        getline(text_file, string_Questions[6], '\n');
        getline(text_file, string_Questions[7], '\n');
        getline(text_file, string_Questions[8], '\n');
        getline(text_file, string_Questions[9], '\n');
        getline(text_file, string_Questions[10], '*');
        question[0].set_answers(stoi(string_Questions[10]));
        getline(text_file, string_Questions[11], '*');
        question[1].set_answers(stoi(string_Questions[11]));
        getline(text_file, string_Questions[12], '*');
        question[2].set_answers(stoi(string_Questions[12]));
        getline(text_file, string_Questions[13], '*');
        question[3].set_answers(stoi(string_Questions[13]));
        getline(text_file, string_Questions[14], '*');
        question[4].set_answers(stoi(string_Questions[14]));
        getline(text_file, string_Questions[15], '*');
        question[5].set_answers(stoi(string_Questions[15]));
        getline(text_file, string_Questions[16], '*');
        question[6].set_answers(stoi(string_Questions[16]));
        getline(text_file, string_Questions[17], '*');
        question[7].set_answers(stoi(string_Questions[17]));
        getline(text_file, string_Questions[18], '*');
        question[8].set_answers(stoi(string_Questions[18]));
        getline(text_file, string_Questions[19], '*');
        question[9].set_answers(stoi(string_Questions[19]));

    }
    text_file.close();
    
    for (int i=0;i<10;i++)
    {
        for (int j=0;string_Questions[i][j]!='\0';j++)
        {
           
            if (string_Questions[i][j]=='*'){
            string_Questions[i][j]='\n';
             
             }
        }
    }
    for (int i=0;i<10;i++)
    {
        question[i].set_questions(string_Questions[i]);
    }
    
}
void asking_questions(Question question[],int Player[],int &i){
    int choose;
    static int index=0;
        cout<<"**************************\n";
        cout<<"Player#1 Turn#"<<i+1<<endl;
        cout<<"**************************\n";
        cout<<"Your "<<i+1<<" Question is : \n";
        cout<<question[index].get_question();
        cout<<"\nChoose :";
        // cout<<question[index].get_answers();
        cin>>choose;
        while (choose !=1 && choose!=2  && choose!=3 && choose!=4)
        {
            cout<<"Not choosing from the options ! Choose again : ";
            cin>>choose;
        }
        if(choose == question[index].get_answers())
        Player[0]++;
        index++;
        cout<<"**************************\n";
        cout<<"Player#2 Turn#"<<i+1<<endl;
        cout<<"**************************\n";
        cout<<" Your "<<i+1<<" Question is : \n";
        cout<<question[index].get_question();
        cout<<"\nChoose :";
        // cout<<question[index].get_answers();
        cin>>choose;
        while (choose !=1 && choose!=2  && choose!=3 && choose!=4)
        {
            cout<<"Not choosing from the options ! Choose again : ";
            cin>>choose;
        }
        if(choose == question[index].get_answers())
        Player[1]++;
        index++;
        // cout<<Player[0]<<" "<<Player[1]<<endl;
}
int main()
{
    int Player[2]={0,0},index=0,choose;
    Question question[10];
    setting_data(question);
    for (int i=0;i<5;i++)
    {
        asking_questions(question,Player, i);
    }
    if (Player[0]==Player[1])
    cout<<"The game resulted in a draw\n with Player#1 points : "<<Player[0]<<" \nPlayer#2 points are : "<<Player[1]<<'\n';
    else if (Player[0]>Player[1])
    cout<<"Player#1 has won the game, with points : "<<Player[0]<<" \nPlayer#2 points are : "<<Player[1]<<'\n';
    else 
    cout<<"The winner of the game is \nPlayer#2 :  with points : "<<Player[1]<<" \nPlayer#1 points are : "<<Player[0]<<'\n';
    return 0;
}