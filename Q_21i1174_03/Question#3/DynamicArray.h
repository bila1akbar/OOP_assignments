#pragma once
#include "string"
using namespace std;
struct node
{
    int value;
    node *next;
};

class DynamicArray
{
private:
    node *head;
    // think about the private data members...
public:
    // provide definitions of following functions...
    DynamicArray();                              // a default constructor
    DynamicArray(int size);                      // a parametrized constructor initializing an Array
    DynamicArray(int arr[], int size);           // initializes the Array with an existing
    DynamicArray(const DynamicArray &);          // copy constructor
    const int operator[](string) const;           // returns the integer at index [i]
    int getsize();
    int &operator[](int);                        // set the value at index [i]
    DynamicArray *operator()(int pos, int size); // returns subArray of ‘size’ from ‘pos’
    DynamicArray *operator()(int pos);           // returns a sub-Array from ‘pos’ to end
    void appendNode(int);
    void displayList() const;
     void operator=(const DynamicArray &d2);
    DynamicArray &operator+=(int a); // adds an element to the end of the array
    int operator-=(int);             // removes and returns the last element of the array
    operator string();               // this should print the matrix in correct format
    operator int();                  // returns the size of the Array
    bool operator==(DynamicArray &); // should return true if both Arrays are same
    bool operator!=(DynamicArray &); // compares if the length of two arrays is same returns true if not
    ~DynamicArray();
};