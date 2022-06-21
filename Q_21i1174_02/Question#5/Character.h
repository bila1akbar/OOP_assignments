#pragma once
using namespace std;
class Character
{
    char characters;

public:
    // include all the necessary checks before performing the operations in the
    Character();                    // a default constructor
    Character(int);                 // a parametrized constructor
    // Character(string);              // a parametrized constructor
    void set(char); 
    char get() const;           // set value
    Character isEqualTo( Character &); // Compares two Character objects numerically
    Character isNotEqualTo( Character &);
    Character isGreaterThan( Character &);
    Character isLessThan( Character &);
    Character isGreaterThanOrEqualTo( Character &);
    Character isLessThanOrEqualTo( Character &);
    Character isAlpha(const Character &);                // checks if the Character is an alphabet
    Character isNum(const Character &);                  // checks if the Character is a number
    Character  isLower (const Character&);                // check for lower case
    Character isUpper(const Character &);                // check for upper case
    Character toUpper( Character &);                // convert a lowercase alphabet to uppercase
    Character toLower( Character &);                // convert a uppercase alphabet to lowercase
    string stringValue();               // Returns the value of this character as a string
    Character plus(const Character &);  // adds two Characters and return the result
    Character minus(const Character &); // subtracts two Characters and return the result
    
};