#pragma once
class Rational
{
private:
    int numerator;
    int denominator;
    //  void reduction( void );
public:
    Rational(int, int); // constructor
    // provide definitions of following functions...
    // constructor
    // implement mutators for all private data members
    // implement accessors for all private data members
    // you have to implement the following functions
    //  think about the parameters required and return type of the following
    void set_n_and_d(int x, int d);
    Rational Add(const Rational &);      // add two Rational numbers. The result should be stored in reduced form
    Rational Subtract(const Rational &); // subtracts two Rational numbers. The result should be stored in reduced form
    Rational Multiply(const Rational &); // multiplies two Rational numbers. The result should be stored in
    void reduce(); // reducing the terms by the greates common factor 
    Rational Divide(const Rational &); // divides two Rational numbers. The result should be stored in reduced
    // form
    void PrintRationalFormat(); // Printing Rational numbers in the form a/b, where a is
    // the numerator and b is the denominator
    void PrintFloatFormat(); // Prints Rational numbers in floating-point format
};