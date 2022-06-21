#include "shape.h"
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
}
void Shape:: set_Area(){
area = 0;
}
Shape ::Shape(int shape_number, int subscript_number)
{
    if (shape_number == Circle)
    {
        // cricle
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
float distance_between_two_points(int x1, int y1, int x2, int y2,int xc,int yc)
{
    float Xn = max(x1, min(xc, x2));
    float Yn = max(y1, min(yc, y2));
    float distance = ((Xn) * (Xn)) + ((Yn) * (Yn));
    distance = sqrt(distance);
    return distance;
}
void Shape::overlapping(Shape obj2, int shape1_subscript, int shape2_subscript)
{
    bool overlapping_check = true;
    
     if (storing_subscript[shape1_subscript] == Circle && storing_subscript[shape2_subscript] == Circle)
    {
        float distance = (((obj2.getx() -x)*(obj2.getx() -x))+((obj2.gety()- y)*(obj2.gety()- y)));
        // cout<<distance<<endl;
        distance= sqrt(distance);
        // cout<<distance<<endl;
        // cout<<(obj2.getx() -x)*(obj2.getx() -x)<<endl;
        // cout<<((obj2.gety()- y)*(obj2.gety()- y))<<endl;
        // cout<<x<<" "<<y<<" "<<obj2.getx()<<" "<<obj2.gety()<<" "<<obj2.getheight()<<" "<<height<<endl;
        if (distance > height + obj2.getheight())
        overlapping_check = false;
    }
    else if (storing_subscript[shape1_subscript] == Circle )
    {
        if (distance_between_two_points (obj2.getx(),obj2.gety(),obj2.getx()+obj2.getwidth(),obj2.gety()+obj2.getheight(),x,y) > height)
        overlapping_check = false;
    }
    else if (storing_subscript[shape1_subscript] == Square || storing_subscript[shape2_subscript] == Square || storing_subscript[shape1_subscript] == Rectangle || storing_subscript[shape2_subscript] == Rectangle)
    {
        if ((x > (obj2.getx() + obj2.getwidth()) /*bottom right point of secound shape*/ || obj2.getx() > (x + width) /*bottom right point of first shape*/))
        {
            cout << "sd";
            overlapping_check = false;
        }
        if (((y + height) < obj2.gety()) || ((obj2.gety() + obj2.getheight()) < y))
        {
            cout << y << " " << height << " " << obj2.gety() << " " << obj2.getheight() << endl;
            cout << "asd";
            overlapping_check = false;
        }
       
    }
     if (overlapping_check == false)
        {
            cout << "Shapes " << shapes_name_string[Shape::returning_subscript_value(shape1_subscript)] << shape1_subscript + 1 << " and " << shapes_name_string[Shape::returning_subscript_value(shape2_subscript)] << shape2_subscript + 1 << " are not ovelapping ! \n";
        }
     if (overlapping_check)
            cout << "Shapes " << shapes_name_string[Shape::returning_subscript_value(shape1_subscript)] << shape1_subscript + 1 << " and " << shapes_name_string[Shape::returning_subscript_value(shape2_subscript)] << shape2_subscript + 1 << " are ovelapping ! \n";
}