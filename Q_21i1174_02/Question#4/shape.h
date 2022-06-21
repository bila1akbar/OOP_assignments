#pragma once
class Shape
{
private:
    float height, width, x, y, area;
    static int *storing_subscript;
    static int shape_count;

public:
    // provide definitions of following functions...
    Shape ();
    Shape(int ,int); // parameterized constructor that will allow to initialize differenttypes of instances
    // implement mutators for all private data members
    // implement accessors for all private data members
    // you have to implement the following functions
    //  think about the parameters required and return type of the following functions
    static void storing_subscript_function(int,int);
    void set_Area();
    float getx();
    float gety();
    float getwidth();
    float getheight();
    static int returning_subscript_value(int);
    static void destroying();
    float getArea();      // prints area
    static Shape returnLargestShape(int,Shape[]);
    void overlapping(Shape,int ,int);        // determines if two Shapes are overlapping or not//   
//     overlappingShapes();  // a static function that returns an array of Shapes
// overlapping the largest Shape, this functions should only work for the same shapes
// ~Shape();
};
