#include <iostream>
#include "ExtendedCharacter.h"
using namespace std;
ExtendedCharacter::ExtendedCharacter()
{
    character = 'c';
}
ExtendedCharacter::ExtendedCharacter(int temp)
{
    character = temp;
}
ExtendedCharacter::ExtendedCharacter(char temp)
{
    character = temp;
}
void ExtendedCharacter::set(char x)
{
    character = x;
}
string ExtendedCharacter::toString(char x)
{
    string temp = "";
    int a[16];
    int integer = x; // storing the ASCII value
    char arr[16];    // storing the binary
    for (int i = 0; i < 16; i++)
        a[i] = 0;
    for (int i = 15; x > 0; i--)
    {
        a[i] = x % 2;
        x = x / 2;
    }
    for (int i = 0; i < 16; i++)
    {
        if (a[i] == 0)
            arr[i] = '0';
        else
            arr[i] = '1';
    }
    for (int i = 0; i < 16; i++)
    {
        temp = temp + arr[i];
    }
    return temp;
}
bool ExtendedCharacter::operator==(const ExtendedCharacter &x)
{
    if (character == x.character)
        return 1;
    else
        return 0;
}
bool ExtendedCharacter::operator!=(const ExtendedCharacter &x)
{

    if (character != x.character)
        return 1;
    else
        return 0;
}
bool ExtendedCharacter::operator<=(const ExtendedCharacter &x)
{

    if (character <= x.character)
        return 1;
    else
        return 0;
}
bool ExtendedCharacter::operator>=(const ExtendedCharacter &x)
{

    if (character >= x.character)
        return 1;
    else
        return 0;
}
bool ExtendedCharacter::operator<(const ExtendedCharacter &x)
{

    if (character < x.character)
        return 1;
    else
        return 0;
}
bool ExtendedCharacter::operator>(const ExtendedCharacter &x)
{

    if (character > x.character)
        return 1;
    else
        return 0;
}
ExtendedCharacter &ExtendedCharacter::operator=(const ExtendedCharacter &c2)
{

    character = c2.character;
    return *this;
}
ExtendedCharacter ExtendedCharacter::operator+(const ExtendedCharacter &c2)
{
    ExtendedCharacter temp;
    temp.character = character + c2.character;
    return temp;
}
ExtendedCharacter ExtendedCharacter::operator-(const ExtendedCharacter &c2)
{
    ExtendedCharacter temp;
    temp.character = character - c2.character;
    return temp;
}
char ExtendedCharacter::get_character() { return character; }
ExtendedCharacter &ExtendedCharacter::operator++()
{
    character++;
    return *this;
}
ExtendedCharacter ExtendedCharacter::operator++(int)
{
    ExtendedCharacter temp;
    temp = *this;
    character++;
    return temp;
}
ExtendedCharacter &ExtendedCharacter::operator--()
{
    character--;
    return *this;
}
ExtendedCharacter ExtendedCharacter::operator--(int)
{
    ExtendedCharacter temp;
    temp = *this;
    character--;
    return temp;
}
ExtendedCharacter::operator int()
{
    return character;
};
ExtendedCharacter::operator short()
{
    return character;
};
void ExtendedCharacter::operator()(int from_range, int to_range)
{
    if (character >= from_range && character <= to_range)
        cout << "The character is with in the entered range " << endl;
    else
        cout << "The character is not  in the entered range " << endl;
    if (character >= 65 && character <= 90)
        cout << "Character is an Upper case Alphabet\n";
    else if (character >= 97 && character <= 122)
        cout << "Character is a lower case Alphabet\n";
    else if (character >= 48 && character <= 57)
        cout << "Character is a Number\n";
}