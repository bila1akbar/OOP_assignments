#include <iostream>
#include "DynamicArray.cpp"
using namespace std;
#include "string.h"
int main()
{
    int d1_size, d2_size, value, size;
    string temp;
    DynamicArray *d3 = NULL;
    DynamicArray d1, d2;
    cout << "Initialzing array d1 : \n";
    cout << "Enter the size of array d1 : ";
    cin >> d1_size;
    for (int i = 0; i < d1_size; i++)
    {
        cout << "Enter the element of the " << i + 1 << " index of array d1 : ";
        cin >> value;
        d1.appendNode(value);
    }
    cout << "Initialzing array d2 : \n";
    cout << "Enter the size of array d2 : ";
    cin >> d2_size;
    for (int i = 0; i < d2_size; i++)
    {
        cout << "Enter the element of the " << i + 1 << " index of array d2: ";
        cin >> value;
        d2.appendNode(value);
    }
    int choose = 0;
    while (choose != 12)
    {
        cout << "Choose from the menu : \n1.Getting value at i index\n2.Setting the value at i index\n3.Return subarray of size from pos\n4.Return a sub array from pos to end\n5.Adding element to the end of the array\n6.Removing and returning the last element of the array\n7.To string\n8.Returning the size of the array\n9.If the arrays are same\n10.If the arrays are not equal\n11.Displaying Array\n12.End\n Choose : ";
        cin >> choose;
        switch (choose)
        {
        case 1:
            cout << "Enter the index of which you want the value of array d1: ";
            cin >> temp;
            cout << "The value at this index of array d1 is " << d1[temp] << endl;
            cout << "Enter the index of which you want the value of array d2: ";
            cin >> temp;
            cout << "The value at this index of array d2 is " << d2[temp] << endl;
            break;
        case 2:
            cout << "Enter the index of array d1 which you want to change : ";
            cin >> temp;
            value = stoi(temp);
            cout << "Enter the value of the index : ";
            cin >> size;
            d1[value - 1] = size;
            cout << "Now the value at this index of array d1 is " << d1[temp] << endl;
            cout << "Enter the index of array d2 which you want to change : ";
            cin >> temp;
            value = stoi(temp);
            cout << "Enter the value of the index : ";
            cin >> size;
            d2[value - 1] = size;
            cout << "Now the value at this index of array d2 is " << d2[temp] << endl;
            break;
        case 3:
            cout << "Enter the size of the new array : ";
            cin >> size;
            cout << "Enter the position from where you want to copy : ";
            cin >> value;
            if (d3 != NULL)
                delete d3;
            d3 = new DynamicArray();
            d3 = d1(value, size);
            d1.displayList();
            cout << endl;
            d3->displayList();
            break;
        case 4:
            cout << "Enter the position from where you want to copy : ";
            cin >> size;
            if (d3 != NULL)
                delete d3;
            d3 = new DynamicArray();
            d3 = d1(size);
            d1.displayList();
            cout << endl
                 << "Displaying the new sub array : \n";
            d3->displayList();
            break;
        case 5:
            cout << "Enter the element you want to add to the end of the array d1 : ";
            cin >> value;
            d1 += value;
            d1.displayList();
            cout << "Enter the element you want to add to the end of the array d2 : ";
            cin >> value;
            d2 += value;
            d2.displayList();
            break;
        case 6:
            cout << "Removing and returning the last element of array d1 : ";
            cout << (d1 -= 1) << endl
                 << "Displaying d1 array : \n";
            d1.displayList();
            cout << "Removing and returning the last element of array d2 : ";
            cout << (d2 -= 1) << endl
                 << "Displaying d2 array : " << endl;
            d2.displayList();
            break;
        case 7:
            temp = string(d1);
            cout << temp << endl;
            break;
        case 8:
            cout << "The size of array d1 is : ";
            size = d1;
            cout << size << endl;
            cout << "The size of array d2 is : ";
            size = d2;
            cout << size << endl;
            break;
        case 9:
            cout << "Array d1 and d2 are " << (d1 == d2) << endl;
            break;
        case 10:
            cout << "Array d1 and d2 are " << (d1 != d2) << endl;
            break;
        case 11:
            break;
            case 12:
            cout<<"Displaying D1 : \n";
            d1.displayList();
            cout<<"Displaying D2 : \n";
            d2.displayList();
            break;
        default:
            cout << " Not choosing from the menu : ";
            break;
        }
    }
    if (d3 != NULL)
        delete d3;
    return 0;
}