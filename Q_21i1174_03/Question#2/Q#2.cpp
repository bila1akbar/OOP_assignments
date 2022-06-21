#include <iostream>
#include "matrix.cpp"
using namespace std;
void copy_constructor(Matrix &M1)
{
    Matrix temp = M1;
    cout << temp;
}
void set_get_value(Matrix &M1)
{
    int choose = 0, row;
    while (choose != 3)
    {
        cout << "\nChoose from the menu \n1.Get Data \n2.Set Data\n3.End\n Choose : ";
        cin>>choose;
        switch (choose)
        {
        case 1:
            cout << "Enter the index of row : ";
            cin >> row;
            cout << "The Data at this location is " << M1[row];
            break;
            cout << M1;
        case 2:
            cout << "Enter the index of row : ";
            cin >> row;
            cout << "Enter the Data to set at this location : ";
            cin >> M1[row];
            cout << M1;
            break;

        default:
            break;
        }
    }
}
int main()
{
    float integer;
    int row = 6, column = 6;
    cout << "Initializing Matrix 1\n";
    Matrix M1(3, 3);
    cout << "Initializing Matrix 2\n";
    Matrix M2(3, 3);
    cout << "Initiliazing Matrix 3\n";
    Matrix M3(3, 3);
    Matrix M4;
    int choose = 0;
    while (choose != 15)
    {
        cout << "Choose from the menu\n1.Copy Constructor\n2.Set and get the value at (i,j)\n3.Assigning Matrix on RHS to LHS\n4.Addition of matrices\n5.Subtraction of matrices\n6.Multiplication of matrices\n7.Comparing matrices\n8.Adding by some integer\n9.Subtracting by some integer\n10.Multiplying by some integer\n11.Dividing by some integer\n12.Returninig a new matrix of size A x B\n13.Multiple operations in a single line\n14.See Matrices Data\n15.End \n Choose : ";
        cin >> choose;
        switch (choose)
        {
        case 1:
            copy_constructor(M1);
            break;
        case 2:
            set_get_value(M1);
        case 3:
            M4 = M1;
            cout << M4;
            break;
        case 4:
            cout<<"M1 : \n";
            cout<<M1;
            cout<<" +\n";
            cout<<"M2 : \n";
            cout<<M2;
            cout << "\nAdding two matrices : "
                 << (M1 + M2) << endl;
            break;
        case 5:
        cout<<"M1 : \n";
            cout<<M1;
            cout<<" -\n";
            cout<<"M2 : \n";
            cout<<M2;
            cout << "\nSubtracting two matrices : "
                 << (M1 - M2) << endl;
            break;
        case 6:
        cout<<"M1 : \n";
            cout<<M1;
            cout<<" *\n";
            cout<<"M2 : \n";
            cout<<M2;
            cout << "\nMultiplying two matrices : "
                 << (M1 * M2) << endl;
            break;
        case 7:
            cout << "Matrix M1 and M2 are : " << (M1 == M2)<<endl;
            break;
        case 8:
        
            cout << "Enter the real number you want to add : ";
            cin >> integer;
            cout<<"M1 : \n";
            cout<<M1;
            cout<<" +\n";
            cout<<' '<<integer<<'\n';
            M1 += integer;
            cout << "The result is :\n"
                 << M1;
            break;
        case 9:
        cout<<"M1 : \n";
            cout<<M1;
            cout<<" -\n";
            cout<<' '<<integer<<'\n';
            cout << "Enter the real number you want to subtract : ";
            cin >> integer;
            M1 -= integer;
            cout << "The result is :\n"
                 << M1;
            break;
        case 10:
            cout << "Enter the real number you want to multiply : ";
            cin >> integer;
            cout<<"M1 : \n";
            cout<<M1;
            cout<<" *\n";
            cout<<' '<<integer<<'\n';
            M1 *= integer;
            cout << "The result is :\n"
                 << M1;
            break;
        case 11:
            cout << "Enter the real number you want to divide : ";
            cin >> integer;
            cout<<"M1 : \n";
            cout<<M1;
            cout<<" /\n";
            cout<<' '<<integer<<'\n';
            M1 /= integer;
            cout << "The result is :\n"
                 << M1;
            break;
        case 12:
            cout << "Enter the row of the new matrix  : ";
            cin >> row;
            cout << "Enter the colume of the new matrix  : ";
            cin >> column;
            while (row > M1.get_row() || column > M1.get_column())
            {
                cout << "Enter row  again of the new matrix  : ";
                cin >> row;
                cout << "Enter colume again  of the new matrix  : ";
                cin >> column;
            }
            cout<<"M1 : \n";
            cout<<M1;
            M4 = M1(row, column);
            cout << "The result is :\n"
                 << M4;
            break;
        case 13:
            cout << "The result of the equation is : ";
            M4 = M1 + M2 - M3 * M2;
            cout << "The result is :\n"
                 << M4;
            break;
        case 14 :

        default:
            break;
        }
    }
    return 0;
}