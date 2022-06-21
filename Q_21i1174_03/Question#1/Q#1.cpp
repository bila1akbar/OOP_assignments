#include <iostream>
#include "ExtendedCharacter.cpp"
using namespace std;

int main()
{
    ExtendedCharacter c1, c2, temp;
    int pick, temp_int;
    short int temp_short_int, to_range, from_range;
    string temp_string;
    int choose = 0;
    while (choose != 1 && choose != 2)
    {
        cout << " Choose from the menu : \n1.Default Constructor\n2.Manually initiliazed constructor \n3.end\n";
        cin >> choose;
        switch (choose)
        {
        case 1:
            break;
        case 2:
            char x;
            cout << "Enter the character for 1st object : ";
            cin >> x;
            c1.set(x);
            cout << "Enter the character for 2nd object : ";
            cin >> x;
            c2.set(x);
            break;
        case 3:
            break;
        default:
            cout << " Not choosing from the menu\n";
            break;
        }
    }
    choose = 0;
    while (choose != 19)
    {
        cout << " Choose from the menu : \n1.IsEqualTo \n2.IsNotEqualTo\n3.IsGreaterThan\n4.IslessThan\n5.IsGreaterThanorEqualTo\n6.IsLessThanOrEqualTo\n7.Assigning c2 to c1\n8.Adding the two Characters\n9.Subtracting the two characters\n10.Returning binary as String\n11.Pre increment\n12.Post increment\n13.Pre decrement\n14.Post decrement\n15.Conversion to integer\n16.Conversion to short int\n17.View Characters\n18.Give a Range\n19.End\n";
        cin >> choose;
        switch (choose)
        {
        case 1:
            cout << "The characters are " << (c1 == c2) << endl;
            break;
        case 2:
            cout << "The characters are " << (c1 != c2) << endl;
            break;
        case 3:
            cout << "The characters are " << (c1 > c2) << endl;
            break;
        case 4:
            cout << "The characters are " << (c1 < c2) << endl;
            break;
        case 5:
            cout << "The characters are " << (c1 >= c2) << endl;
            break;
        case 6:
            cout << "The characters are " << (c1 <= c2) << endl;
            break;
        case 7:

            c1 = c2;
            cout << "C1 character is : " << c1.get_character() << endl;
            cout << "C2 character is : " << c2.get_character() << endl;

            break;
        case 8:
            temp = c1 + c2;
            cout << "After adding the two character the result is : " << temp.get_character() << endl;
            break;
        case 9:
            temp = c1 - c2;
            cout << "After adding the two character the result is : " << temp.get_character() << endl;
            break;
        case 10:
            char x;
            cout << "Enter the character to return as a string : ";
            cin >> x;
            temp_string = ExtendedCharacter::toString(x);
            cout << "The binary form of C1 in string is : " << temp_string << endl;
            break;
        case 11:
            temp = ++c1;
            cout << "C1 after pre increment is : " << temp.get_character() << endl;
            temp = ++c2;
            cout << "C2 after pre increment is : " << temp.get_character() << endl;

            break;
        case 12:
            temp = c1++;
            cout << "C1 after post increment is : " << temp.get_character() << endl;
            temp = c2++;
            cout << "C2 after post increment is : " << temp.get_character() << endl;
            break;
        case 13:

            temp = --c1;
            cout << "C1 after pre decrement is : " << temp.get_character() << endl;
            temp = --c2;
            cout << "C2 after pre decrement is : " << temp.get_character() << endl;
            break;
        case 14:
            temp = c1--;
            cout << "C1 after pre increment is : " << temp.get_character() << endl;
            temp = c2--;
            cout << "C2 after pre increment is : " << temp.get_character() << endl;
            break;
        case 15:
            temp_int = c1;
            cout << " After casting C1 to integer the result is : " << temp_int << endl;
            temp_int = c2;
            cout << " After casting C2 to integer the result is : " << temp_int << endl;
            break;
        case 16:
            temp_short_int = c1;
            cout << " After casting C1 to integer the result is : " << temp_short_int << endl;
            temp_short_int = c2;
            cout << " After casting C2 to integer the result is : " << temp_short_int << endl;
            break;
        case 17:
            cout << "C1 at the moment is : " << c1.get_character() << endl;
            cout << "C2 at the moment is : " << c2.get_character() << endl;
            break;
        case 18:
            cout << "Enter (from) Range for C1 : ";
            cin >> from_range;
            cout << "Enter (to) Range for C1 : ";
            cin >> to_range;
            c1(from_range, to_range);
            cout << "Enter (from) Range for C2 : ";
            cin >> from_range;
            cout << "Enter (to) Range for C2 : ";
            cin >> to_range;
            c2(from_range, to_range);
            break;
        case 19:
            break;
        }
    }
    return 0;
}