#pragma once
#include<string>
using namespace std;
class Shape
{
private:
    float height, width, x, y, area;
    static int *storing_subscript;
    static int shape_count;
    string name;
    int id;

public:
    // provide definitions of following functions...
    Shape();

    Shape(int, int); // parameterized constructor that will allow to initialize differenttypes of instances
    // implement mutators for all private data members
    // implement accessors for all private data members
    // you have to implement the following functions
    //  think about the parameters required and return type of the following functions
    static void storing_subscript_function(int, int);
    string getname();
    void set_Area();
    float getx();
    float gety();
    int getid();
    float getwidth();
    float getheight();
    static int returning_subscript_value(int);
    static void destroying();
    float getArea(); // prints area
    static Shape returnLargestShape(int, Shape[]);
    void overlapping(Shape, int, int); // determines if two Shapes are overlapping or not//
    //     overlappingShapes();  // a static function that returns an array of Shapes
    // overlapping the largest Shape, this functions should only work for the same shapes
    // ~Shape();
    string operator[](string); // whenever you have to access any information of shape
};
class Canvas
{
    private:
    Shape* shapes_in_canvas;
    static int number_of_canvas;
    int number_of_shapes_in_canvas;

    // think of private data member carefully
public:
    static int count_for_operatorstring;

    // implement necessary constructors
    Canvas ();
    Canvas (int);
    int getnumberofshapes();
    void DisplayShapes();
    void Choosing_Shapes(Shape [],int  );
    void operator()(int, int);
    Shape operator[](Shape &); // returns the appropriate reference to add or remove the shape from the canvas
    Shape operator[](string); // Returns the shapes of a certain type “Circle” – all circles
    Canvas* operator+(Canvas &);  // adds two canvas and creates a third one with shapes of first two canvases – be careful of the limit of shapes per canvas
     operator string(); // converts the canvas information into a well-formatted string.It should include information of all types and shapes in it.
    ~Canvas();
};