#include <iostream>
#include "string.h"
#include "DynamicArray.h"
using namespace std;
DynamicArray::DynamicArray()
{
    head = NULL;
}
DynamicArray::DynamicArray(int size)
{
    head = NULL;
    int value;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the value of array subscript#" << i + 1 << " : ";
        cin >> value;
        appendNode(value);
    }
}
DynamicArray::DynamicArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        appendNode(arr[i]);
    }
}
DynamicArray::DynamicArray(const DynamicArray &d2)
{
    node *d2_nodeptr;
    node *newNode;
    node *nodeptr;

    if (d2.head == NULL)
    {
        cout << "Array cannot be initialized because d2 is not initialized ! \n";
    }
    else
    {
        d2_nodeptr = d2.head;
        while (d2_nodeptr != NULL)
        {
            appendNode(d2_nodeptr->value);
            d2_nodeptr = d2_nodeptr->next;
        }
    }
}

void DynamicArray::appendNode(int value)
{
    node *newNode; // to point to the new value
    node *nodeptr; // To move through the list
    // Allocate a new node and store num there.
    newNode = new node;
    newNode->value = value;
    newNode->next = NULL;
    if (head == NULL)
        head = newNode;
    else
    {
        nodeptr = head;
        while (nodeptr->next != NULL)
            nodeptr = nodeptr->next;

        nodeptr->next = newNode;
    }
}
void DynamicArray::displayList() const
{
    node *nodeptr;
    nodeptr = head;
    int i = 1;
    while (nodeptr != NULL)
    {
        // Display the value in this node.
        cout << "The value at " << i << " index is = " << nodeptr->value << endl;
        // Move to the next node.
        i++;
        nodeptr = nodeptr->next;
    }
}
DynamicArray &DynamicArray ::operator+=(int a)
{
    appendNode(a);
    return *this;
}
int DynamicArray::operator-=(int)
{
    node *nodeptr;
    int last_value;
    int count = getsize() - 1, i = 1;
    if (head != NULL)
    {
        if (head->next == NULL)
        {
            delete head;
            return 0;
        }
        else
        {
            nodeptr = head;
            while (nodeptr->next->next != NULL)
            {
                nodeptr = nodeptr->next;
            }
            last_value = nodeptr->next->value;
            delete (nodeptr->next);
            nodeptr->next = NULL;
        }
    }
    return last_value;
}
DynamicArray::operator int()
{
    int count = 1;
    node *nodeptr;
    if (head == NULL)
        return 0;
    else
    {
        nodeptr = head;
        while (nodeptr->next != NULL)
        {
            nodeptr = nodeptr->next;
            count++;
        }
    }
    return count;
}
int DynamicArray::getsize()
{
    int count = 1;
    node *nodeptr;
    if (head == NULL)
        return 0;
    else
    {
        nodeptr = head;
        while (nodeptr != NULL)
        {
            nodeptr = nodeptr->next;
            count++;
        }
    }
    return count;
}
bool DynamicArray::operator!=(DynamicArray &d2)
{
    node *nodeptr;
    node *nodeptr_d2;
    if (head == NULL || d2.head == NULL)
        return 1;
    else
    {
        nodeptr = head;
        nodeptr_d2 = d2.head;
        while (nodeptr != NULL)
        {
            if (nodeptr->value != nodeptr_d2->value)
                return 1;
            nodeptr = nodeptr->next;
            nodeptr_d2 = nodeptr_d2->next;
        }
    }
    return 0;
}
bool DynamicArray::operator==(DynamicArray &d2)
{
    node *nodeptr;
    node *nodeptr_d2;
    if (head == NULL || d2.head == NULL)
        return 0;
    else
    {
        nodeptr = head;
        nodeptr_d2 = d2.head;
        while (nodeptr->next != NULL)
        {
            if (nodeptr->value != nodeptr_d2->value)
                return 0;
            nodeptr = nodeptr->next;
            nodeptr_d2 = nodeptr_d2->next;
        }
        if (nodeptr->value != nodeptr_d2->value)
            return 0;
    }
    return 1;
}
const int DynamicArray::operator[](string i) const
{
    int num = std::stoi(i);
    num = num - 1;
    node *nodeptr;
    int count = 0;
    if (head == NULL)
        return 0;
    else
    {
        nodeptr = head;
        while (nodeptr->next != NULL)
        {
            if (count == num)
            {

                return nodeptr->value;
            }
            count++;
            nodeptr = nodeptr->next;
        }
        return nodeptr->value;
    }
}
int &DynamicArray::operator[](int i)
{

    node *nodeptr;
    int count = 0;
    nodeptr = head;
    while (nodeptr->next != NULL)
    {
        if (count == i)
        {
            nodeptr->value = i;
            return nodeptr->value;
        }
        count++;
        nodeptr = nodeptr->next;
    }
    nodeptr->value = i;
    return nodeptr->value;
}
DynamicArray *DynamicArray::operator()(int pos, int size)
{
    DynamicArray *temp;
    temp = new DynamicArray;
    node *nodeptr;
    int count = 1;
    if (head == NULL)
        return temp;
    else
    {
        nodeptr = head;
        while (nodeptr != NULL)
        {
            if (count >= pos)
            {
                if (count < (pos + size))
                {
                    temp->appendNode(nodeptr->value);
                }
            }
            nodeptr = nodeptr->next;
            count++;
        }
    }
    return temp;
}
DynamicArray *DynamicArray::operator()(int pos)
{
    DynamicArray *temp;
    temp = new DynamicArray;
    node *nodeptr;
    int count = 1;
    if (head == NULL)
        return temp;
    else
    {
        nodeptr = head;
        while (nodeptr->next != NULL)
        {
            if (count >= pos)
            {
                temp->appendNode(nodeptr->value);
            }
            count++;
            nodeptr = nodeptr->next;
        }
        temp->appendNode(nodeptr->value);
    }
    return temp;
}
DynamicArray::~DynamicArray()
{
    node *nodePtr;
    node *nextNode;
    nodePtr = head;

    while (nodePtr != NULL)
    {

        nextNode = nodePtr->next;
        delete nodePtr;

        nodePtr = nextNode;
    }
}
DynamicArray::operator string()
{
    string temp="";
    node *nodeptr;
    int count = 0;
    nodeptr = head;
    while (nodeptr != NULL)
    {
        temp = temp + std::to_string(nodeptr->value) ;
        temp = temp + " ";
        nodeptr = nodeptr->next;
        count++;
        if (count % 2 == 0)
            temp = temp + '\n';
    }
   
    return temp;
}