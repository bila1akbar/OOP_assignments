#include <iostream>
#include <cstdlib>
#include<string>
#include<fstream>
using namespace std;
struct Customer
{
    int cust_No;
    int C_Gender;
    int age;
    float food_purchased = 0;
};
struct Sales_Person
{
    int emp_ID;
    char emp_Name[20];
    double Sales = 0;
};
struct Salary
{
    float fixedSalary = 15000;
    double comission;
};
struct FoodItem
{
    int id[10];
    string *itemName;
    int price[10];
};
void increasing_size_of_array(int *&oldArr,  int& count)
{
    int *newArr = new int[count];
    copy(oldArr, oldArr + (count - 1), newArr);
    delete[] oldArr;
    oldArr = newArr;
}
void increasing_size_of_array_customer(Customer *&oldArr,  int& count)
{
    Customer *newArr = new Customer [count];
    copy(oldArr, oldArr + (count - 1), newArr);
    delete[] oldArr;
    oldArr = newArr;
}
// int price;
void managing_customer(Customer* &customer_data, int &count_for_customer, string fooditems[], FoodItem &food_items_structure, Sales_Person sales_person_data[], int &count_for_employee_name, int* &food_items_name, int &food_items_name_count)
{

    food_items_structure.itemName = fooditems;
    food_items_structure.price[0] = 100;
    food_items_structure.price[1] = 110;
    food_items_structure.price[2] = 50;
    food_items_structure.price[3] = 70;
    food_items_structure.price[4] = 30;
    food_items_structure.price[5] = 50;
    food_items_structure.price[6] = 80;
    food_items_structure.price[7] = 70;
    food_items_structure.price[0] = 25;
    food_items_structure.price[0] = 80;
    int choose = 0;
    customer_data[count_for_customer].cust_No = count_for_customer;
  
    cout << "****Customer# " << customer_data[count_for_customer].cust_No<<" ****"<<endl;
    cout << "Choose the gender of the customer #" <<customer_data[count_for_customer].cust_No<<" : \n1.Male\n2.Female\n3.Prefer not to say\n";
    cin>> customer_data[count_for_customer].C_Gender;
    cout << "Enter the age of the customer #" <<customer_data[count_for_customer].cust_No<<" : ";
    cin>> customer_data[count_for_customer].age;
    cout << "Select the food item \n1.Apple Juice \n2.Orange-Juice \n3.Samosa \n4.Pepsi \n5.Lays \n6.chana-chat \n7.Fries \n8.Sprite \n9.Biscuit \n10.Boiled_Potato \n11.Exit"<<endl;
    while (choose != 11) 
    {
        if (choose!=0)
        cout<<"Select another food item or Press 11"<<endl;
        cin >> choose;
        if (choose != 11  && (choose>=1 && choose<=11))
        {
            customer_data[count_for_customer].food_purchased = food_items_structure.price[choose - 1] + customer_data[count_for_customer].food_purchased;
            sales_person_data[count_for_employee_name].Sales++;
            food_items_name[food_items_name_count - 1]=choose;
            increasing_size_of_array(food_items_name, ++food_items_name_count);
            
        }
    }
    
            increasing_size_of_array_customer(customer_data, ++count_for_customer);
    
}
void TotalSales(Sales_Person salesperson_data[])
{
    int total = 0;

    for (int i = 0; i < 3; i++)
    {
        total = salesperson_data[i].Sales + total;
    }
    cout << "The total sales by the Sales Person is : " << total<<endl;
}
void totalsalesbysalesPerson(Sales_Person salesperson_data[])
{

    for (int i = 0; i < 3; i++)
    {
        cout << "Sales by " << salesperson_data[i].emp_Name << " ( " << salesperson_data[i].emp_ID << " ) are : " << salesperson_data[i].Sales << endl;
    }
}
void topSalePerson(Sales_Person salesperson_data[])
{
    int highest = salesperson_data[0].Sales, secoundhighest = salesperson_data[0].Sales;
    int high=0, sechigh=0;
    for (int i = 0; i < 3; i++)
    {
        if (salesperson_data[i].Sales > highest)
        {
            highest = salesperson_data[i].Sales;
            high = i;
        }
        for (int j = 0; j < 3; j++)
        {
            if (salesperson_data[j].Sales > salesperson_data[i].Sales && salesperson_data[j].Sales < highest)
            {
                secoundhighest = salesperson_data[j].Sales;
                sechigh = j;
            }
        }
    }
    for (int i = 0; i < 3; i++)
    {
        if (high == i)
            cout << "Most sales is by " << salesperson_data[i].emp_Name << " ( " << salesperson_data[i].emp_ID << " ) are " << salesperson_data[i].Sales << endl;
        else if (sechigh == i)
            cout << "Secound Highest sales is by " << salesperson_data[i].emp_Name << " ( " << salesperson_data[i].emp_ID << " ) are " << salesperson_data[i].Sales << endl;
        else
            cout << "Lastly sales by " << salesperson_data[i].emp_Name << " ( " << salesperson_data[i].emp_ID << " ) are " << salesperson_data[i].Sales << endl;
    }
}
void commission(Salary employees_salary[], Sales_Person salesperson_data[])
{
    for (int i = 0; i < 3; i++)
    {
        employees_salary[i].comission = (salesperson_data[i].Sales / 100) * 2;
    }
    for (int i = 0; i < 3; i++)
    {
        cout << "The commission for " << salesperson_data[i].emp_Name << " ( " << salesperson_data[i].emp_ID << " ) is " << employees_salary[i].comission << endl;
    }
}
void totalsalary(Salary employees_salary[], Sales_Person salesperson_data[])
{
    commission( employees_salary,  salesperson_data);
    for (int i = 0; i < 3; i++)
    {
        cout << "The Salary of " << salesperson_data[i].emp_Name << " ( " << salesperson_data[i].emp_ID << " ) is " << employees_salary[i].fixedSalary + employees_salary[i].comission << endl;
    }
}
void salesByType(int* &Food_items_name, int &food_items_name_count)
{
    int foods_items_categorywise_count[10]={};
    int choose=0;
    for (int i = 0; i < food_items_name_count; i++)
    {
        if (Food_items_name[i] == 1)
        foods_items_categorywise_count[0]++;
        else if (Food_items_name[i] == 2)
            foods_items_categorywise_count[1]++;
        else if (Food_items_name[i] == 3)
            foods_items_categorywise_count[2]++;
        else if (Food_items_name[i] == 4)
            foods_items_categorywise_count[3]++;
        else if (Food_items_name[i] == 5)
            foods_items_categorywise_count[4]++;
        else if (Food_items_name[i] == 7)
            foods_items_categorywise_count[6]++;
        else if (Food_items_name[i] == 8)
            foods_items_categorywise_count[7]++;
        else if (Food_items_name[i] == 9)
            foods_items_categorywise_count[8]++;
        else if (Food_items_name[i] == 10)
            foods_items_categorywise_count[9]++;
        else if (Food_items_name[i] == 6)
            foods_items_categorywise_count[5]++;
    }
    cout << "Select the food item \n1.Apple Juice \n2.Orange-Juice \n3.Samosa \n4.Pepsi \n5.Lays \n6.chana-chat \n7.Fries \n8.Sprite \n9.Biscuit \n10.Boiled_Potato \n11.Exit" << endl;
    while (choose != 11)
    {
        if (choose!=0)
        cout<<"Select another food item or Press 11"<<endl;
        cin >> choose;
        
        switch (choose)
        {
        case 1:
            cout << "The amount of Apple Juice Sold are : " << foods_items_categorywise_count[0] << endl;
            break;
        case 2:
            cout << "The amount of Orange Juice Sold are : " << foods_items_categorywise_count[1] << endl;
            break;
        case 3:
            cout << "The amount of Samosa Sold are : " << foods_items_categorywise_count[2] << endl;
            break;
        case 4:
            cout << "The amount of Pepsi Sold are : " << foods_items_categorywise_count[3] << endl;
            break;
        case 5:
            cout << "The amount of Lays Sold are : " << foods_items_categorywise_count[4] << endl;
            break;
        case 6:
            cout << "The amount of chana-chat Sold are : " << foods_items_categorywise_count[5] << endl;
            break;
        case 7:
            cout << "The amount of Fries Sold are : " << foods_items_categorywise_count[6] << endl;
            break;
        case 8:
            cout << "The amount of Sprite Sold are : " << foods_items_categorywise_count[7] << endl;
            break;
        case 9:
            cout << "The amount of Biscuit Sold are : " << foods_items_categorywise_count[8] << endl;
            break;
        case 10:
            cout << "The amount of Boiled potato Sold are : " << foods_items_categorywise_count[9] << endl;
            break;
        default:
            cout << "Not choosing from the menu" << endl;
            break;
        }
    }
}
int main()
{
  
    int food_items_name_count = 1;
    int *food_items_name = new int[food_items_name_count];
    FoodItem food_items_structure;
    string fooditems[10] = {"Apple-Juice", "Orange-Juice", "Samosa", "Pepsi", "Lays", "chana-chat", "Fries", "Sprite", "Biscuit", "Boiled_Potato"};
    Sales_Person salesperson_data[3];
    Salary employees_salary[3];
    Customer *customer_data=new Customer [1];
    int choose = 0, count_for_employee_name = 0, checking_id_number, count_for_customer=0;
    bool validitng_id_of_employees = false;
    for (int i = 0; i < 3; i++)
    {
        cout << "Enter the id of employee #" << i + 1 << " : ";
        cin >> salesperson_data[i].emp_ID;
        for (int j = 3; j >= 0; j--)
        {
            while (salesperson_data[j].emp_ID == salesperson_data[i].emp_ID && i != j)
            {
                cout << "Id already in use, Enter again :";
                cin >> salesperson_data[i].emp_ID;
            }
        }
        cout << "Enter the name of employee #" << i + 1 << " : ";
        cin.ignore();
        cin.getline( salesperson_data[i].emp_Name,20);
    }

    while (choose != 8)
    {
        cout << "Choose from the menu : \n\t1.Dealing with Customers\n\t2.Total Sales\n\t3.Sales by Employee\n\t4.Highest Sales by Employee\n\t5.commisionSalesPerson\n\t6.TotalSalary\n\t7.Sales By type\n\t8.Exit" << endl;
        cin >> choose;
        switch (choose)
        {
        case 1:
        {

            while (validitng_id_of_employees == false)
            {
                cout << "Enter your id to continue : ";
                cin >> checking_id_number;
                for (int i = 0; i < 3; i++)
                {
                    if (checking_id_number == salesperson_data[i].emp_ID)
                    {
                        validitng_id_of_employees = true;
                        count_for_employee_name = i;
                    }
                }
                if (validitng_id_of_employees == false)
                    cout << "Invalid Id number !" << endl;
            }

            if (validitng_id_of_employees)
                cout << "Hello " << salesperson_data[count_for_employee_name].emp_Name;
            validitng_id_of_employees=false;
            managing_customer(customer_data, count_for_customer, fooditems, food_items_structure, salesperson_data, count_for_employee_name, food_items_name, food_items_name_count);
        }
        break;
        case 2:
            TotalSales(salesperson_data);
            break;
        case 3:
            totalsalesbysalesPerson(salesperson_data);
            break;
        case 4:
            topSalePerson(salesperson_data);
            break;
        case 5:
            commission(employees_salary, salesperson_data);
            break;
        case 6:
            totalsalary(employees_salary, salesperson_data);
            break;
        case 7:
            salesByType(food_items_name, food_items_name_count);
            break;
            case 8:
            break;
        default:
        cout<<"Not choosing from the menu, Choose again !"<<endl;
        }
    }
    // int count=0;
    // ofstream myfile;
    // myfile.open("customer_data.txt");
    // while (count<count_for_customer){
    // myfile<<customer_data[count].cust_No<< ',';
    // myfile<<customer_data[count].C_Gender<< ',';
    // myfile<<customer_data[count].age<<'\n';
    // }
    // myfile.close();
    delete[] customer_data;
    delete[] food_items_name;

    return 0;
}