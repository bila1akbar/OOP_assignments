#include <iostream>
#include "canvas.cpp"
using namespace std;

int main()
{
    Canvas *temp_canvas = NULL;
    int number_of_shapes, choose = 0, choose_shape_1, choose_shape_2;
    bool shape_doesnot_repeat = false;
    int x, y;
    cout << "Enter the number of shapes you want to create : ";
    cin >> number_of_shapes;
    int choose_shape;
    Shape temp;
    string temp_string;
    shape_Data = new Shape[number_of_shapes];

    Shape::storing_subscript_function(number_of_shapes, 0);

    for (int i = 0; i < number_of_shapes; i++)
    {
        cout << "Choose from the menu Shape#" << i + 1 << "\n1.Circle\n2.Rectangle\n3.Triangle\n4.Square\n Choose : ";
        cin >> choose_shape;
        shape_Data[i] = Shape(choose_shape - 1, i);
    }
    Canvas c1, c2;
    cout << "Assiginning shapes for canvas#1" << endl;
    c1.Choosing_Shapes(shape_Data, number_of_shapes);
    cout << "Assiginning shapes for canvas#2" << endl;
    c2.Choosing_Shapes(shape_Data, number_of_shapes);
    while (choose != 9)
    {
        cout << "Choose from the menu : \n1.Get Shape Data\n2.Access Shape data\n3.Adding or removing shape\n4.Returning shapes of similar name\n5.Specific (x,y)\n6.Adding two canvas\n7.Returning string\n8.Seeing canvas Shapes\n9.End\n Choose : ";
        cin >> choose;
        switch (choose)
        {
        case 1:
            for (int i = 0; i < number_of_shapes; i++)
            {
                if (shapes_name_string[Shape::returning_subscript_value(i)] == "Circle")
                    cout << i + 1 << ". " << shapes_name_string[Shape::returning_subscript_value(i)] << "#" << i + 1 << " is (" << shape_Data[i].getx() << ',' << shape_Data[i].gety() << ") with a radius of : " << shape_Data[i].getheight() << endl;
                else
                    cout << i + 1 << ". " << shapes_name_string[Shape::returning_subscript_value(i)] << "#" << i + 1 << " is (" << shape_Data[i].getx() << ',' << shape_Data[i].gety() << ") with a width of : " << shape_Data[i].getwidth() << " and height of  : " << shape_Data[i].getheight() << endl;
            }
            break;

        case 2:
            for (int i = 0; i < number_of_shapes; i++)
            {
                cout << i + 1 << ".  " << shapes_name_string[Shape::returning_subscript_value(i)] << "#" << i + 1 << endl;
            }
            cout << "Choose from the menu which shape data you want to access : ";
            cin >> temp_string;
            temp_string = shape_Data[0][temp_string];
            break;
        case 3:
        {
            cout << "1.c1\n2.c2\n";
            cin >> choose;
            switch (choose)
            {
            case 1:
                for (int i = 0; i < number_of_shapes; i++)
                {
                    if (shapes_name_string[Shape::returning_subscript_value(i)] == "Circle")
                        cout << i + 1 << ". " << shapes_name_string[Shape::returning_subscript_value(i)] << "#" << i + 1 << " is (" << shape_Data[i].getx() << ',' << shape_Data[i].gety() << ") with a radius of : " << shape_Data[i].getheight() << endl;
                    else
                        cout << i + 1 << ". " << shapes_name_string[Shape::returning_subscript_value(i)] << "#" << i + 1 << " is (" << shape_Data[i].getx() << ',' << shape_Data[i].gety() << ") with a width of : " << shape_Data[i].getwidth() << " and height of  : " << shape_Data[i].getheight() << endl;
                }
                cin >> choose;
                temp = c1[shape_Data[choose - 1]];

                cout << endl;
                if (temp.getname() == "Circle")
                    cout << choose << '.' << temp.getname() << " with  (" << temp.getx() << ',' << temp.gety() << ") and  a radius of : " << temp.getheight() << " has been added,removed or nothing ." << endl;
                else
                    cout << choose << '.' << temp.getname() << " with  (" << temp.getx() << ',' << temp.gety() << ") and  a width of : " << temp.getwidth() << " and height of  : " << temp.getheight() << " has been added,removed or nothing ." << endl;

                choose = 1;
                break;
            case 2:
                for (int i = 0; i < number_of_shapes; i++)
                {
                    if (shapes_name_string[Shape::returning_subscript_value(i)] == "Circle")
                        cout << i + 1 << ". " << shapes_name_string[Shape::returning_subscript_value(i)] << "#" << i + 1 << " is (" << shape_Data[i].getx() << ',' << shape_Data[i].gety() << ") with a radius of : " << shape_Data[i].getheight() << endl;
                    else
                        cout << i + 1 << ". " << shapes_name_string[Shape::returning_subscript_value(i)] << "#" << i + 1 << " is (" << shape_Data[i].getx() << ',' << shape_Data[i].gety() << ") with a width of : " << shape_Data[i].getwidth() << " and height of  : " << shape_Data[i].getheight() << endl;
                }
                cin >> choose;
                temp = c2[shape_Data[choose - 1]];
                cout << endl;
                if (temp.getname() == "Circle")
                    cout << choose << '.' << temp.getname() << " with  (" << temp.getx() << ',' << temp.gety() << ") and  a radius of : " << temp.getheight() << " has been added,removed or nothing." << endl;
                else
                    cout << choose << '.' << temp.getname() << " with  (" << temp.getx() << ',' << temp.gety() << ") and  a width of : " << temp.getwidth() << " and height of  : " << temp.getheight() << " has been added,removed or nothing." << endl;
                choose = 1;
                break;

            default:
                break;
            }
            choose = 3;
        }
        break;
        case 4:
            cout << "Choosing for c1 \n";
            cout << "Enter one of these \nCircle\nRectangle\nTriangle\nSquare\n Choose : ";
            cin >> temp_string;
            for (int i = 0; i < c1.getnumberofshapes(); i++)
            {
                temp = c1[temp_string];
                if (temp.getid() != 0 )
                {
                    if (temp.getname() == "Circle")
                        cout << temp.getname() << " with  (" << temp.getx() << ',' << temp.gety() << ") and  a radius of : " << temp.getheight() << " ." << endl;
                    else
                        cout << temp.getname() << " with  (" << temp.getx() << ',' << temp.gety() << ") and  a width of : " << temp.getwidth() << " and height of  : " << temp.getheight() << "  ." << endl;
                    shape_doesnot_repeat = true;
                    
                }
                Canvas::count_for_operatorstring++;
            }
            if (shape_doesnot_repeat == false)
            {
                cout << "No such shape exist !\n";
            }
            shape_doesnot_repeat = false;
            Canvas::count_for_operatorstring = 0;
            cout << "Choosing for c2 \n";
            cout << "Enter one of these \nCircle\nRectangle\nTriangle\nSquare\n Choose : ";
            cin >> temp_string;
            for (int i = 0; i < c2.getnumberofshapes(); i++)
            {
                temp = c2[temp_string];
                if (temp.getid() != 0)
                {
                    if (temp.getname() == "Circle")
                        cout << temp.getname() << " with  (" << temp.getx() << ',' << temp.gety() << ") and  a radius of : " << temp.getheight() << " ." << endl;
                    else
                        cout << temp.getname() << " with  (" << temp.getx() << ',' << temp.gety() << ") and  a width of : " << temp.getwidth() << " and height of  : " << temp.getheight() << "  ." << endl;
                    shape_doesnot_repeat = true;
                   
                }
                Canvas::count_for_operatorstring++;
            }
             if (shape_doesnot_repeat == false)
                {
                    cout << "No such shape exist !\n";
                    shape_doesnot_repeat = true;
                }
            shape_doesnot_repeat = false;
            Canvas::count_for_operatorstring = 0;
            break;
        case 5:
            cout << "Shapes of c1 : \n";
            c1.DisplayShapes();
            cout << "\nEntering data for canvas 1 : \n";
            cout << "Enter the value for x : ";
            cin >> x;
            cout << "Enter the value for y : ";
            cin >> y;
            c1(x, y);
            cout << "Shapes of c2 : \n";
            c2.DisplayShapes();
            cout << "\nEntering data for canvas 2 : \n";
            cout << "Enter the value for x : ";
            cin >> x;
            cout << "Enter the value for y : ";
            cin >> y;
            c2(x, y);
            break;
        case 6:
            cout << "Shapes of c1 : \n\n";
            c1.DisplayShapes();
            cout << "\nShapes of c2 : \n\n";
            c2.DisplayShapes();
            if (temp_canvas != NULL)
                delete temp_canvas;
            temp_canvas = c1 + c2;
            cout << endl
                 << "After adding c1 and c2 " << endl;
            temp_canvas->DisplayShapes();
            cout << endl;
            break;
        case 7:
            cout << "Returning string for canvas 1\n";
            temp_string = string(c1);
            cout << temp_string;
            cout << endl;
            cout << "Returning string for canvas 2\n";
            temp_string = string(c2);
            cout << temp_string;
            cout << endl;
            break;
        case 8:
            cout << "Canvas #1 shapes : \n";
            c1.DisplayShapes();
            cout << "Canvas #2 shapes : \n";
            c2.DisplayShapes();
            break;

        case 9:
            break;
        default:
            cout << "Not choosing from the menu ! \n";
            break;
        }
    }
    delete[] shape_Data;
    if (temp_canvas != NULL)
        delete temp_canvas;
    Shape::destroying();
    return 0;
}