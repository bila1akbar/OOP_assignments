#include <iostream>
#include "Rational.cpp"
using namespace std;

int main()
{
    int choose = 0;
    Rational r3, r1, r2;
    while (choose != 1 && choose != 2)
    {
        cout << "Choose from the menu : \n1.Default Constructor \n2.Initiliazed Constructor\n Choose : ";
        cin >> choose;
        switch (choose)
        {
        case 1:
            break;
        case 2:
            cout << "Enter the value for the numerator for the first term : ";
            int n, d;
            cin >> n;
            cout << "Enter the value for the denominator for the first term : ";
            cin >> d;
            r1.set_n_and_d(n, d);
            cout << "Enter the value for the numerator for the secound term : ";
            
            cin >> n;
            cout << "Enter the value for the denominator for the secound term : ";
            cin >> d;
            r2.set_n_and_d(n, d);
            break;
        default:
            cout<<"Not choosing from the menu ! \n";
            break;
        }
    }
    choose = 0;

    while (choose !=5)
    {
        cout << "Enter choose from the menu the operation you want to perform : \n1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n5.End \n";
        cin >> choose;
        switch (choose)
        {
        case 1:
            cout<<" The result addition is : ";
            r1.PrintRationalFormat();
            cout << " + ";
            r2.PrintRationalFormat();
            cout << " = ";
            r3 = r1.Add(r2);
            r3.PrintRationalFormat();
            cout << " = ";
            r3.PrintFloatFormat();
            cout << "\n\n";

            break;
        case 2:
        cout<<" The result subtraction is : ";
            r1.PrintRationalFormat();
            cout << " - ";
            r2.PrintRationalFormat();
            cout << " = ";
            r3 = r1.Subtract(r2);
            r3.PrintRationalFormat();
            cout << " = ";
            r3.PrintFloatFormat();
            cout << "\n\n";
            break;
        case 3:
        cout<<" The result Multiplication is : ";
            r1.PrintRationalFormat();
            cout << " * ";
            r2.PrintRationalFormat();
            cout << " = ";
            r3 = r1.Multiply(r2);
            r3.PrintRationalFormat();
            cout << " = ";
            r3.PrintFloatFormat();
            cout << "\n\n";
            break;
        case 4 :
        cout<<" The result division is : ";
            cout<<'(';
        r1.PrintRationalFormat();
        cout<<')';
            cout << " / ";
            cout<<'(';
            r2.PrintRationalFormat();
            cout<<')';
            cout << " = ";
            r3 = r1.Divide(r2);
            r3.PrintRationalFormat();
            cout << " = ";
            r3.PrintFloatFormat();
            cout << "\n\n";
            break;
        case 5 : break;
        default:
            cout<<"Not choosing from the menu ! \n";
            break;
        }
    }
    return 0;
}