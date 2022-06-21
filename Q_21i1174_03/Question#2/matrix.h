#pragma once
#include<iostream>
using namespace std;
class Matrix
{
    float **matrix_data;
    int row, column;

public:
    // include all the necessary checks before performing the operations in the
    //  functions
    Matrix();                          // a default constructor
    Matrix(int, int);                  // a parametrized constructor
    Matrix(const Matrix &);            // copy constructor
    int get_row();
    int get_column();
    void DisplayMatrices();
    float &operator[](int);            // set and get value at (i,j)
    Matrix &operator=(const Matrix &); // assigns matrix on RHS to the one on LHS
    Matrix operator+(const Matrix &); // add two matrices
    Matrix operator-(const Matrix &); // subtracts two matrices
    Matrix operator*(const Matrix &); // dot product of two matrices
    bool operator==(const Matrix &);   // checks if two matrices are equal
    Matrix &operator+=(float);           // adds an integer to all elements
    Matrix &operator-=(float);           // subtracts an integer from all elements
    Matrix &operator*=(float);           // multiples an integer to all elements
    Matrix &operator/=(float);           // divides all elements by an integer
    Matrix operator()(int A, int B);  // returns a new matrix of size A x B
    friend ostream &operator<<(ostream &out, const Matrix &matrix);
    friend istream &operator>>(istream &in, const Matrix &matrix);

    ~Matrix();
};