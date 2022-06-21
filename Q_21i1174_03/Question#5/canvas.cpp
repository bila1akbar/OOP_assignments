#include "canvas.h"
#include <time.h>
#include <iostream>
#include <cmath>
using namespace std;
enum shapes_name
{
    Circle,
    Rectangle,
    Triangle,
    Square
};
Shape temporary_shape;
Shape *shape_Data;
int Shape::shape_count(0);
string shapes_name_string[] = {"Circle",
                               "Rectangle",
                               "Triangle",
                               "Square"};
Shape ::Shape()
{
    x = 0;
    y = 0;
    height = 0;
    width = 0;
    shape_count++;
    id = 0;
}
void Shape::set_Area()
{
    area = 0;
}
int Shape::getid()
{
    return id;
}
Shape ::Shape(int shape_number, int subscript_number)
{
    id = subscript_number + 1;
    if (shape_number == Circle)
    {
        // cricle
        name = "Circle";
        cout << "Setting Random values for Circle : \n";
        srand(time(NULL));
        x = rand() % 50 + 1;
        y = rand() % 50 + 1;
        height = rand() % 20 + 1; // can be the radius for circle
        area = (3.14) * (height * height);
        cout << "The coordinates for this circle is : (" << x << ',' << y << ") with a radius of : " << height << endl;
    }
    else if (shape_number == Rectangle)
    {
        name = "Rectangle";
        cout << "Setting Random values for Rectangle : \n";
        srand(time(NULL));
        x = rand() % 50 + 1;
        y = rand() % 50 + 1;
        height = rand() % 20 + 1;
        width = rand() % 40 + 1;
        area = height * width;
        cout << "The coordinates for this rectangle is : (" << x << ',' << y << ") with a height of : " << height << ", and a width of " << width << endl;
    }
    else if (shape_number == Triangle)
    {
        name = "Triangle";
        cout << "Setting Random values for Triangle : \n";
        srand(time(NULL));
        x = rand() % 50 + 1;
        y = rand() % 50 + 1;
        height = rand() % 20 + 1;
        width = rand() % 30 + 1;
        area = (height * width) / 2;
        cout << "The coordinates for this Triangle is : (" << x << ',' << y << ") with a height of : " << height << ", and a base of " << width << endl;
    }
    else if (shape_number == Square)
    {
        name = "Square";
        srand(time(NULL));
        cout << "Setting Random values for square : \n";
        x = rand() % 50 + 1;
        y = rand() % 50 + 1;
        height = rand() % 20 + 1;
        area = (height * height);
        cout << "The coordinates for this Square is : (" << x << ',' << y << ") with a height of : " << height << ", and a width of " << height << endl;
    }
    storing_subscript_function(shape_number, subscript_number);
}
int *Shape::storing_subscript = NULL;
void Shape::storing_subscript_function(int x, int subscript_number) // x is the number of shapes
{
    if (storing_subscript == NULL)
    {
        storing_subscript = new int[x];
    }
    else
        storing_subscript[subscript_number] = x;
}
int Shape::returning_subscript_value(int i)
{
    return storing_subscript[i];
}
float Shape::getArea()
{
    return area;
}
void Shape::destroying()
{
    delete[] storing_subscript;
}
Shape Shape::returnLargestShape(int shape_number, Shape shapes_data[])
{
    int highest = 0, storing_i;
    if (shape_number == Circle)
    {
        for (int i = 0; i < shape_count; i++)
        {
            if (shape_number == returning_subscript_value(i) && shapes_data[i].getArea() >= highest)
            {
                highest = shapes_data[i].getArea();
                storing_i = i;
            }
        }
    }
    else if (shape_number == Rectangle)
    {
        for (int i = 0; i < shape_count; i++)
        {
            if (shape_number == returning_subscript_value(i) && shapes_data[i].getArea() >= highest)
            {
                highest = shapes_data[i].getArea();
                storing_i = i;
            }
        }
    }
    else if (shape_number == Triangle)
    {
        for (int i = 0; i < shape_count; i++)
        {
            if (shape_number == returning_subscript_value(i) && shapes_data[i].getArea() >= highest)
            {
                highest = shapes_data[i].getArea();
                storing_i = i;
            }
        }
    }
    else if (shape_number == Square)
    {
        for (int i = 0; i < shape_count; i++)
        {
            if (shape_number == returning_subscript_value(i) && shapes_data[i].getArea() >= highest)
            {
                highest = shapes_data[i].getArea();
                storing_i = i;
            }
        }
    }
    return shapes_data[storing_i];
}
float Shape::getx()
{
    return x;
}
float Shape::gety()
{
    return y;
}
float Shape::getwidth()
{
    return width;
}
float Shape::getheight()
{
    return height;
}
float distance_between_two_points(int x1, int y1, int x2, int y2, int xc, int yc)
{
    float Xn = max(x1, min(xc, x2));
    float Yn = max(y1, min(yc, y2));
    float distance = ((Xn) * (Xn)) + ((Yn) * (Yn));
    distance = sqrt(distance);
    return distance;
}

string Shape::operator[](string x)
{
    int integer = stoi(x) - 1;
    if (shape_Data[integer].name == "Circle")
    {
        cout << "The coordinates for this circle is : (" << shape_Data[integer].getx() << ',' << shape_Data[integer].gety() << ") with a radius of : " << shape_Data[integer].getheight() << endl;
    }
    else if (shape_Data[integer].name == "Rectangle")
    {

        cout << "The coordinates for this rectangle is : (" << shape_Data[integer].getx() << ',' << shape_Data[integer].gety() << ") with a height of : " << shape_Data[integer].getheight() << ", and a width of " << shape_Data[integer].getwidth() << endl;
    }
    else if (shape_Data[integer].name == "Triangle")
    {

        cout << "The coordinates for this Triangle is : (" << shape_Data[integer].getx() << ',' << shape_Data[integer].gety() << ") with a height of : " << shape_Data[integer].getheight() << ", and a base of " << shape_Data[integer].getwidth() << endl;
    }
    else if (shape_Data[integer].name == "Square")
    {

        cout << "The coordinates for this Square is : (" << shape_Data[integer].getx() << ',' << shape_Data[integer].gety() << ") with a height of : " << shape_Data[integer].getheight() << ", and a width of " << shape_Data[integer].getwidth() << endl;
    }
    return x;
}
string Shape::getname()
{
    return name;
}
// ************************************************************************************
// ************************************************************************************
// ************************************************************************************
const int const_shape_limit = 10;
int Canvas::number_of_canvas(1);
Canvas::Canvas(int)
{
}
Canvas::Canvas()
{
    cout << "Enter the number of shapes, canvas " << number_of_canvas << " will have : ";
    cin >> number_of_shapes_in_canvas;
    while (number_of_shapes_in_canvas > 10)
    {
        cout<<"\n!!! Can't have more than 10 shapes in a single canvas !!!\nEnter Again : ";
        cin>>number_of_shapes_in_canvas;
    }
    number_of_canvas++;
    shapes_in_canvas = new Shape[number_of_shapes_in_canvas];
}
void Canvas::Choosing_Shapes(Shape shape_Data[], int number_of_shapes)
{
    // int choose;
    // for (int i = 0; i < number_of_shapes; i++)
    // {
    //     cout << i + 1 << ".  " << shapes_name_string[Shape::returning_subscript_value(i)] << "#" << i + 1 << endl;
    // }
    // cin >> choose;
    // shapes_in_canvas[count] = shape_Data[choose - 1];
    int choose = 0, pick_shape = 0, shape_limit = 0;
    while (choose != 2)
    {
        if (shape_limit == number_of_shapes_in_canvas || shape_limit == const_shape_limit)
        {
            cout << "Cant choose any more Shapes ! \n";
            return;
        }
        cout << "Choose :\n1.Pick a Shape\n2.End\n Choose :";
        cin >> choose;

        switch (choose)
        {
        case 1:

            for (int j = 0; j < number_of_shapes_in_canvas; j++)
            {
                cout << "Pick a shape\n";
                for (int i = 0; i < number_of_shapes; i++)
                {
                    cout << i + 1 << ".  " << shapes_name_string[Shape::returning_subscript_value(i)] << "#" << i + 1 << endl;
                }
                cout << number_of_shapes + 1 << ". End\n";
                cin >> pick_shape;
                cout << endl;
                if (pick_shape == (number_of_shapes + 1))
                    break;
                else
                {
                    shapes_in_canvas[j] = shape_Data[pick_shape - 1];
                    shape_limit++;
                }
            }
            break;
        case 2:
            break;
        default:
            break;
        }
    }
}
Canvas::~Canvas()
{
    cout << "Destructor called ! \n";
    delete shapes_in_canvas;
}
void increasing_assigned_shape_array_size(Shape *&oldArr, const int count)
{
    Shape *newArr = new Shape[count];
    for (int i = 0; i < count - 1; i++)
    {
        newArr[i] = oldArr[i];
    }
    delete[] oldArr;
    oldArr = newArr;
    newArr = NULL;
}
Shape Canvas::operator[](Shape &x)
{
    int choose = 0;
    bool checking_already_existence = false;
    int storing_subscript;
    int count = 0;
    cout << "Do you want to \n1.Add this shape \n2.remove it\n";
    cin >> choose;
    while (choose != 1 && choose != 2)
    {
        cout << "Not choosing 1 or 2 !\n";
        cout << "Choose -> Do you want to \n1.Add this shape \n2.remove it\n";
        cin >> choose;
    }
    switch (choose)
    {
    case 1:
        for (int i = 0; i < number_of_shapes_in_canvas; i++)
        {
            if (x.getid() == shapes_in_canvas[i].getid())
                checking_already_existence = true;
        }
        if (checking_already_existence)
        {
            cout << "Shape already exists !\n";
            DisplayShapes();
            return x;
        }
        else if (number_of_shapes_in_canvas <= 10)
        {
            increasing_assigned_shape_array_size(shapes_in_canvas, ++number_of_shapes_in_canvas);
            shapes_in_canvas[number_of_shapes_in_canvas - 1] = x;
            DisplayShapes();
            cout << "Successful addition of shape\n";
            return shapes_in_canvas[number_of_shapes_in_canvas - 1];
        }
        break;
    case 2:
        for (int i = 0; i < number_of_shapes_in_canvas; i++)
        {
            if (x.getid() == shapes_in_canvas[i].getid())
            {
                storing_subscript = i;
                checking_already_existence = true;
            }
        }
        if (checking_already_existence == false)
        {
            cout << "Shape doesn't exists in the canvas !\n";
            cout << "Shapes of this canvas are : ";
            DisplayShapes();
            return x;
        }
        else
        {
            number_of_shapes_in_canvas--;
            Shape *newArr = new Shape[number_of_shapes_in_canvas];
            for (int i = 0; i < number_of_shapes_in_canvas + 1; i++)
            {
                if (x.getid() == shapes_in_canvas[i].getid())
                    continue;
                else
                {
                    newArr[count] = shapes_in_canvas[i];
                    count++;
                }
            }
            delete[] shapes_in_canvas;
            shapes_in_canvas = newArr;
            newArr = NULL;
            cout << "Successful removal of Shape \n";
            DisplayShapes();
            return x;
        }
        break;
    default:
        return x;
        break;
    }

    // for (int i = 0; i < number_of_shapes_in_canvas; i++)
    // {
    //     if (shapes_name_string[Shape::returning_subscript_value(i)] == "Circle")
    //         cout << i + 1 << ". " << shapes_name_string[Shape::returning_subscript_value(i)] << "#" << i + 1 << " is (" << shape_Data[i].getx() << ',' << shape_Data[i].gety() << ") with a radius of : " << shape_Data[i].getheight() << endl;
    //     else
    //         cout << i + 1 << ". " << shapes_name_string[Shape::returning_subscript_value(i)] << "#" << i + 1 << " is (" << shape_Data[i].getx() << ',' << shape_Data[i].gety() << ") with a width of : " << shape_Data[i].getwidth() << " and height of  : " << shape_Data[i].getheight() << endl;
    // }
    // cin >> choose;
}
int Canvas::count_for_operatorstring(0);
int Canvas::getnumberofshapes()
{
    return number_of_shapes_in_canvas;
}
Shape Canvas::operator[](string x)
{
    cout<<"";
    if (x == shapes_in_canvas[count_for_operatorstring].getname())
        return shapes_in_canvas[count_for_operatorstring];
    else
        return temporary_shape;
}
void Canvas::DisplayShapes()
{
    for (int i = 0; i < number_of_shapes_in_canvas; i++)
    {
        if (shapes_in_canvas[i].getname() == "Circle")
            cout << i + 1 << '.' << shapes_in_canvas[i].getname() << " with  (" << shapes_in_canvas[i].getx() << ',' << shapes_in_canvas[i].gety() << ") and  a radius of : " << shapes_in_canvas[i].getheight() << '.' << endl;
        else
            cout << i + 1 << '.' << shapes_in_canvas[i].getname() << " with  (" << shapes_in_canvas[i].getx() << ',' << shapes_in_canvas[i].gety() << ") and  a width of : " << shapes_in_canvas[i].getwidth() << " and height of  : " << shapes_in_canvas[i].getheight() << "." << endl;
    }
}

void Canvas::operator()(int x, int y)
{
    bool checking_if_shapes_exists = false;
    for (int i = 0; i < number_of_shapes_in_canvas; i++)
    {
        if ((shapes_in_canvas[i].getx() == x) && (shapes_in_canvas[i].gety() == y))
        {
            checking_if_shapes_exists = true;

            if (shapes_in_canvas[i].getname() == "Circle")
                cout << i + 1 << '.' << shapes_in_canvas[i].getname() << " with  (" << shapes_in_canvas[i].getx() << ',' << shapes_in_canvas[i].gety() << ") and  a radius of : " << shapes_in_canvas[i].getheight() << '.' << endl;
            else
                cout << i + 1 << '.' << shapes_in_canvas[i].getname() << " with  (" << shapes_in_canvas[i].getx() << ',' << shapes_in_canvas[i].gety() << ") and  a width of : " << shapes_in_canvas[i].getwidth() << " and height of  : " << shapes_in_canvas[i].getheight() << "." << endl;
        }
    }
    if (checking_if_shapes_exists == false)
        cout << "No shape with x :" << x << " and y : " << y << " exists !\n";
}
Canvas *Canvas::operator+(Canvas &c2)
{
    Canvas *temp;
    int count = 0;
    temp = new Canvas(0);
    if (number_of_shapes_in_canvas + c2.number_of_shapes_in_canvas <= 10)
        temp->number_of_shapes_in_canvas = number_of_shapes_in_canvas + c2.number_of_shapes_in_canvas;
    else
        temp->number_of_shapes_in_canvas = 10;
    temp->shapes_in_canvas = new Shape[temp->number_of_shapes_in_canvas];
    int half = (temp->number_of_shapes_in_canvas / 2);
    for (int i = 0; i < half; i++, count++)
    {
        temp->shapes_in_canvas[count] = shapes_in_canvas[i];
    }
    for (int i = 0; count < temp->number_of_shapes_in_canvas; i++, count++)
    {
        temp->shapes_in_canvas[count] = c2.shapes_in_canvas[i];
    }
    return temp;
}
Canvas::operator std::string()
{
    string temp = "";
    for (int i = 0; i < number_of_shapes_in_canvas; i++)
    {

        if (shapes_in_canvas[i].getname() == "Circle")
        {
            temp = temp + to_string(i + 1) + ". ";
            temp = temp + shapes_in_canvas[i].getname() + " with (";
            temp = temp + to_string(shapes_in_canvas[i].getx()) + "," + to_string(shapes_in_canvas[i].gety()) + ") and  a radius of : " + to_string(shapes_in_canvas[i].getheight()) + ".\n";
        }
        else
        {

            temp = temp + to_string(i + 1) + ". ";
            temp = temp + shapes_in_canvas[i].getname() + " with (";
            temp = temp + to_string(shapes_in_canvas[i].getx()) + "," + to_string(shapes_in_canvas[i].gety()) + ") and  a width of : " + to_string(shapes_in_canvas[i].getwidth()) + " and height of  : " + to_string(shapes_in_canvas[i].getheight()) + ".\n";
        }
    }
    return temp;
}