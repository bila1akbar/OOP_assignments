#include <iostream>
#include "shape.cpp"
using namespace std;

int main()
{
    int number_of_shapes, choose = 0,choose_shape_1,choose_shape_2;
    cout << "Enter the number of shapes you want to create : ";
    cin >> number_of_shapes;
    int choose_shape;
    Shape temp;
    Shape *shape_Data = new Shape[number_of_shapes];
    Shape::storing_subscript_function(number_of_shapes, 0);
    for (int i = 0; i < number_of_shapes; i++)
    {
        cout << "Choose from the menu Shape#" << i + 1 << "\n1.Circle\n2.Rectangle\n3.Triangle\n4.Square\n Choose : ";
        cin >> choose_shape;
        shape_Data[i] = Shape(choose_shape - 1, i);
    }
    while (choose != 4)
    {
        cout << "Choose from the menu : \n1.Get Area\n2.Largest shapes\n3.Overlapping shapes\n4.End\n Choose : ";
        cin >> choose;
        switch (choose)
        {
        case 1:
            for (int i = 0; i < number_of_shapes; i++)
            {
                cout << i + 1 << ".The Area of " << shapes_name_string[Shape::returning_subscript_value(i)] << "#" << i + 1 << " is " << shape_Data[i].getArea() << endl;
            }
            break;
        case 2:
            cout << "Choose from the menu which largest shape of type you want  : \n1.Circle\n2.Rectangle\n3.Triangle\n4.Square\n Choose : ";
            cin >> choose;
            temp = Shape::returnLargestShape(choose - 1, shape_Data);
            cout << "The largest shape of the choosen category is : " << shapes_name_string[choose - 1] <<" with an Area of  : " << temp.getArea() << endl;
            choose = 2;
            temp.set_Area();
            break;
        case 3:
            for (int i = 0; i < number_of_shapes; i++)
            {
                if (shapes_name_string[Shape::returning_subscript_value(i)] == "Circle")
                                cout << i + 1 << ". " << shapes_name_string[Shape::returning_subscript_value(i)] << "#" << i + 1 << " is (" <<  shape_Data[i].getx() << ',' << shape_Data[i].gety() << ") with a radius of : "<<shape_Data[i].getheight() << endl;
                else
                cout << i + 1 << ". " << shapes_name_string[Shape::returning_subscript_value(i)] << "#" << i + 1 << " is (" <<  shape_Data[i].getx() << ',' << shape_Data[i].gety() << ") with a width of : "<<shape_Data[i].getwidth()<<" and height of  : "<<shape_Data[i].getheight() << endl;
            }
            cout<<" Choose Shape 1: ";
            cin>>choose_shape_1;
            cout<<" Choose Shape 2: ";
            cin>>choose_shape_2;
            shape_Data[choose_shape_1 - 1].overlapping(shape_Data[choose_shape_2 - 1],choose_shape_1 - 1,choose_shape_2 - 1);
            break;
        case 4 :
        break;
        default:
            cout<<"Not choosing from the menu ! \n";
            break;
        }
    }
    delete[] shape_Data;

    Shape::destroying();
    return 0;
}