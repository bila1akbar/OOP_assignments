#include "matrix.h"
using namespace std;
#include <iostream>
ostream &operator<<(ostream &out, const Matrix &matrix)
{
    out << '\n';
    for (int i = 0; i < matrix.row; i++)
    {
        for (int j = 0; j < matrix.column; j++)
        {
            out << matrix.matrix_data[i][j] << " ";
        }
        cout << endl;
    }
    return out;
}
// outputs the matrix
istream &operator>>(istream &in, const Matrix &matrix)
{
    for (int i = 0; i < matrix.row; i++)
    {
        for (int j = 0; j < matrix.column; j++)
        {
            cout << "\tEnter the data for r#" << i + 1 << " of c#" << j + 1 << " : ";
            cin >> matrix.matrix_data[i][j];
        }
    }
    return in;
}
Matrix::Matrix()
{
    matrix_data = NULL;
}
Matrix::~Matrix()
{
    for (int i = 0; i < row; i++)
        delete[] matrix_data[i];
    delete[] matrix_data;
}
Matrix::Matrix(int r, int c)
{
    row = r;
    column = c;
    matrix_data = new float *[r];
    for (int i = 0; i < r; i++)
    {
        matrix_data[i] = new float[c];
    }
    cin >> *this;
}
Matrix::Matrix(const Matrix &temp)
{
    row = temp.row;
    column = temp.column;
    matrix_data = new float *[temp.row];
    for (int i = 0; i < temp.row; i++)
    {
        matrix_data[i] = new float[temp.column];
    }
    for (int i = 0; i < temp.row; i++)
    {
        for (int j = 0; j < temp.column; j++)
        {

            matrix_data[i][j] = temp.matrix_data[i][j];
        }
    }
}
float &Matrix::operator[](int row)
{
    int column;
    cout << "Enter the index of column  : ";
    cin >> column;
    return matrix_data[row - 1][column - 1];
}
Matrix Matrix::operator()(int A, int B)
{
    Matrix temp;
    temp.row = A;
    temp.column = B;
    temp.matrix_data = new float *[A];
    for (int i = 0; i < A; i++)
        temp.matrix_data[i] = new float[B];

    for (int i = 0; i < A; i++)
        for (int j = 0; j < B; j++)
            temp.matrix_data[i][j] = matrix_data[i][j];
    return temp;
}
Matrix &Matrix::operator=(const Matrix &temp)
{
    row = temp.row;
    column = temp.column;
    matrix_data = new float *[temp.row];
    for (int i = 0; i < temp.row; i++)
    {
        matrix_data[i] = new float[temp.column];
    }
    for (int i = 0; i < temp.row; i++)
    {
        for (int j = 0; j < temp.column; j++)
        {
            matrix_data[i][j] = temp.matrix_data[i][j];
        }
    }
    return *this;
}
Matrix Matrix::operator+(const Matrix &matrix_2)
{
    if (row == matrix_2.row && column == matrix_2.column)
    {
        Matrix temp;
        temp.row = row;
        temp.column = column;
        temp.matrix_data = new float *[row];
        for (int i = 0; i < row; i++)
            temp.matrix_data[i] = new float[column];
        for (int i = 0; i < matrix_2.row; i++)
        {
            for (int j = 0; j < matrix_2.column; j++)
            {
                temp.matrix_data[i][j] = matrix_data[i][j] + matrix_2.matrix_data[i][j];
            }
        }
        return temp;
    }
    else
    {
        cout << "Order of martices are not equal ! \n";
    }
}
Matrix Matrix::operator-(const Matrix &matrix_2)
{
    if (row == matrix_2.row && column == matrix_2.column)
    {
        Matrix temp;
        temp.row = row;
        temp.column = column;
        temp.matrix_data = new float *[row];
        for (int i = 0; i < row; i++)
            temp.matrix_data[i] = new float[column];
        for (int i = 0; i < matrix_2.row; i++)
        {
            for (int j = 0; j < matrix_2.column; j++)
            {
                temp.matrix_data[i][j] = matrix_data[i][j] - matrix_2.matrix_data[i][j];
            }
        }
        return temp;
    }
    else
    {
        cout << "Order of martices are not equal ! \n";
    }
}
Matrix Matrix::operator*(const Matrix &matrix_2)
{
    if (column == matrix_2.row)
    {
        Matrix temp;
        temp.row = row;
        temp.column = matrix_2.column;
        temp.matrix_data = new float *[row];
        for (int i = 0; i < row; i++)
            temp.matrix_data[i] = new float[temp.column];
        for (int i = 0; i < temp.row; i++)
            for (int j = 0; j < temp.column; j++)
                temp.matrix_data[i][j] = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < matrix_2.column; j++)
            {
                for (int k = 0; k < column; k++)
                    temp.matrix_data[i][j] = temp.matrix_data[i][j] + matrix_data[i][k] * matrix_2.matrix_data[k][j];
            }
        }
        return temp;
    }
    else
    {
        cout << "Colume of first martix is  not equal to row of secound matrix ! \n";
    }
}
bool Matrix::operator==(const Matrix &matrix_2)
{
    bool check_equal = false;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
            if (matrix_data[i][j] == matrix_2.matrix_data[i][j])
                check_equal = true;
            else
            {
                check_equal = false;
                return check_equal;
            }
    }
    return check_equal;
}

Matrix &Matrix::operator+=(float x)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
            matrix_data[i][j] = matrix_data[i][j] + x;
    }

    return *this;
}
Matrix &Matrix::operator-=(float x)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
            matrix_data[i][j] = matrix_data[i][j] - x;
    }
    return *this;
}
Matrix &Matrix::operator*=(float x)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
            matrix_data[i][j] = matrix_data[i][j] * x;
    }
    return *this;
}
Matrix &Matrix::operator/=(float x)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
            matrix_data[i][j] = matrix_data[i][j] / x;
    }
    return *this;
}
int Matrix::get_row()
{
    return row;
}
int Matrix::get_column()
{
    return column;
}