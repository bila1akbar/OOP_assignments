#include <iostream>
#include "Rational.h"
using namespace std;
Rational::Rational(int n = 1/*default and parameterized constructor at the same time*/, int d = 3)
{
    // Default constructor
    numerator = n;
    denominator = d;
}
void Rational::set_n_and_d(int n, int d)
{
    // setting the value for numerator
    numerator = n;
    // setting the value for denominator
    denominator = d;
}
Rational Rational::Add(const Rational &t)
{
    Rational temp;
    // Setting the value for the denominator
    temp.denominator = t.denominator * denominator;
    //setting the value for the numerator
    temp.numerator = t.numerator * denominator + t.denominator * numerator;
    // reducing the rational number
    temp.reduce();

    return temp;
}
Rational Rational::Multiply(const Rational &t)
{
    Rational temp;
    //setting the value for the numerator
    temp.numerator = t.numerator * numerator;
    // Setting the value for the denominator
    temp.denominator = t.denominator * denominator;
    temp.reduce();
    return temp;
}
Rational Rational::Subtract(const Rational &t)
{
    Rational temp;
    //setting the value for the numerator
    temp.numerator = t.numerator * denominator - t.denominator * numerator;
    //setting the value for the denominator
    temp.denominator = t.denominator * denominator;
    temp.reduce();
    return temp;
}
Rational Rational::Divide(const Rational &t)
{
    Rational temp;
    //setting the value for the numerator
    temp.numerator = t.numerator * denominator;
    //setting the value for the denominator
    temp.denominator = t.denominator * numerator;
    temp.reduce();
    return temp;
}
void Rational::reduce()
{
    int largest, greatest_common_factor = 0,number = 2;
    // Checking if the highest value is of the denominator or the numerator
    if (numerator > denominator)
        largest = numerator;
    else
        largest = denominator;
    // getting the highest common factor
    for (number /*starting number from 2 as all numbers are divisible by 1 */; number <= largest; number++)
    {
        if (denominator % number == 0 && numerator % number == 0)
            greatest_common_factor = number; // the highest common factor when both the number give modulus 0
    }
    if (greatest_common_factor != 0)
    {
        //dividing the numerator by greates_common_factor
        numerator = numerator/greatest_common_factor;
        //dividing th denominator by the greatest common factor
        denominator =denominator/ greatest_common_factor;
    }
    else 
    cout<<"The denominator is equal to zero divsion not possible ! \n";
}
void Rational::PrintFloatFormat()
{
    // coverting to float because modulus operator does not work with float 
    cout << static_cast<float>(numerator) / denominator; 
}

void Rational::PrintRationalFormat()
{
    if (denominator == 0)//denominator check will be applied first
        cout << "\nDivision by zero : ERROR !\n";
    else if (numerator == 0)//then the denominator check
        cout << 0;//as if the numerator is zero then the whole term will be zero 
    else /*simply ouputting the rational form */
        cout << numerator << '/' << denominator;
}
