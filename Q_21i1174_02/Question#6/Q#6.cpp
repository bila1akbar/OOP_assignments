#include <iostream>
#include "HR.cpp"
using namespace std;

void set_employee_salary(Employee employee_data[], int number_of_employees, HRManager *&HR_data)
{
    int id;
    bool id_check = false;
    cout << "Enter the id of the employee : ";
    cin >> id;
    for (int i = 0; i < number_of_employees; i++)
    {
        if (id == employee_data[i].getID())
            id_check = true;
    }
    while (id_check == false)
    {
        cout << "Incorrect id entered ! Enter again : ";
        cin >> id;
        for (int i = 0; i < number_of_employees; i++)
        {
            if (id == employee_data[i].getID())
                id_check = true;
        }
    }

    if (id_check)
    {
        cout << " The old salary for employee : " << employee_data[id - 1].getID() << " was : " << employee_data[id - 1].getSalary() << endl;

        employee_data[id - 1].setSalary();
        cout << " The new  salary for employee : " << employee_data[id - 1].getID() << " is : " << employee_data[id - 1].getSalary() << endl;
    }
    HR_data = HRManager::getHR_Instance(employee_data, id - 1);
    cout << HR_data[id - 1].getSalary() << endl;
}
void set_employee_Age(Employee employee_data[], int number_of_employees, HRManager *&HR_data)
{
    int id;
    bool id_check = false;
    cout << "Enter the id of the employee : ";
    cin >> id;
    for (int i = 0; i < number_of_employees; i++)
    {
        if (id == employee_data[i].getID())
            id_check = true;
    }
    while (id_check == false)
    {
        cout << "Incorrect id entered ! Enter again : ";
        cin >> id;
        for (int i = 0; i < number_of_employees; i++)
        {
            if (id == employee_data[i].getID())
                id_check = true;
        }
    }

    if (id_check)
    {
        cout << "  The Age of employee : " << employee_data[id - 1].getID() << " was : " << employee_data[id - 1].getAge() << endl;

        employee_data[id - 1].setAge();
        cout << " Now the Age of employee : " << employee_data[id - 1].getID() << " is : " << employee_data[id - 1].getAge() << endl;
    }
    HR_data = HRManager::getHR_Instance(employee_data, id - 1);
    cout << HR_data[id - 1].getAge() << endl;
}
void set_employee_status(Employee employee_data[], int number_of_employees, HRManager *&HR_data)
{
    int id;
    bool id_check = false;
    cout << "Enter the id of the employee : ";
    cin >> id;
    for (int i = 0; i < number_of_employees; i++)
    {
        if (id == employee_data[i].getID())
            id_check = true;
    }
    while (id_check == false)
    {
        cout << "Incorrect id entered ! Enter again : ";
        cin >> id;
        for (int i = 0; i < number_of_employees; i++)
        {
            if (id == employee_data[i].getID())
                id_check = true;
        }
    }

    if (id_check)
    {
        cout << " The status of employee : " << employee_data[id - 1].getID() << " was : " << employee_data[id - 1].getStatus() << endl;

        employee_data[id - 1].setStatus();
        cout << " The new status for employee : " << employee_data[id - 1].getID() << " is : " << employee_data[id - 1].getStatus() << endl;
    }
    HR_data = HRManager::getHR_Instance(employee_data, id - 1);
}

void set_employee_casual_leaves(Employee employee_data[], int number_of_employees, HRManager *&HR_data)
{
    int id;
    bool id_check = false;
    cout << "Enter the id of the employee : ";
    cin >> id;
    for (int i = 0; i < number_of_employees; i++)
    {
        if (id == employee_data[i].getID())
            id_check = true;
    }
    while (id_check == false)
    {
        cout << "Incorrect id entered ! Enter again : ";
        cin >> id;
        for (int i = 0; i < number_of_employees; i++)
        {
            if (id == employee_data[i].getID())
                id_check = true;
        }
    }

    if (id_check)
    {
        cout << " The old causal leaves for employee : " << employee_data[id - 1].getID() << " was : " << employee_data[id - 1].getCasualLeaves() << endl;

        employee_data[id - 1].setCasualLeaves();
        cout << " The new causal leaves for employee : " << employee_data[id - 1].getID() << " is : " << employee_data[id - 1].getCasualLeaves() << endl;
    }
    HR_data = HRManager::getHR_Instance(employee_data, id - 1);
}
void set_employee_avail_casual_leaves(Employee employee_data[], int number_of_employees, HRManager *&HR_data)
{
    int id;
    bool id_check = false;
    cout << "Enter the id of the employee : ";
    cin >> id;
    for (int i = 0; i < number_of_employees; i++)
    {
        if (id == employee_data[i].getID())
            id_check = true;
    }
    while (id_check == false)
    {
        cout << "Incorrect id entered ! Enter again : ";
        cin >> id;
        for (int i = 0; i < number_of_employees; i++)
        {
            if (id == employee_data[i].getID())
                id_check = true;
        }
    }

    if (id_check)
    {
        // cout << " The avail leaves for employee : " << employee_data[id - 1].getID() << " was : " << employee_data[id - 1].getAvailCasualLeave() << endl;
        // employee_data[id - 1].AvailCasualLeave();
        cout << " The available casual leaves for employee : " << employee_data[id - 1].getID() << " is : " << employee_data[id - 1].getAvailCasualLeave() << endl;
    }
    HR_data = HRManager::getHR_Instance(employee_data, id - 1);
}
void set_employee_earned_leaves(Employee employee_data[], int number_of_employees, HRManager *&HR_data)
{
    int id;
    bool id_check = false;
    cout << "Enter the id of the employee : ";
    cin >> id;
    for (int i = 0; i < number_of_employees; i++)
    {
        if (id == employee_data[i].getID())
            id_check = true;
    }
    while (id_check == false)
    {
        cout << "Incorrect id entered ! Enter again : ";
        cin >> id;
        for (int i = 0; i < number_of_employees; i++)
        {
            if (id == employee_data[i].getID())
                id_check = true;
        }
    }

    if (id_check)
    {
        cout << " The earned leave for employee : " << employee_data[id - 1].getID() << " was : " << employee_data[id - 1].getAvailEarnedLeave() << endl;
        employee_data[id - 1].setAge();
        cout << " The earned leave for employee : " << employee_data[id - 1].getID() << " is : " << employee_data[id - 1].getAvailEarnedLeave() << endl;
    }
    HR_data = HRManager::getHR_Instance(employee_data, id - 1);
}
void compare_employees(Employee employee_data[], int number_of_employees, HRManager *&HR_data)
{
    int id[2];
    bool id_check = false;
    cout << "Enter the id for the first employee : ";
    cin >> id[0];
    for (int i = 0; i < number_of_employees; i++)
    {
        if (id[0] == employee_data[i].getID())
            id_check = true;
    }
    while (id_check == false)
    {
        cout << "Incorrect id entered ! Enter again : ";
        cin >> id[0];
        for (int i = 0; i < number_of_employees; i++)
        {
            if (id[1] == employee_data[i].getID())
                id_check = true;
        }
    }

    id_check = false;
    cout << "Enter the id for the secound employee : ";
    cin >> id[1];
    for (int i = 0; i < number_of_employees; i++)
    {
        if (id[1] == employee_data[i].getID())
            id_check = true;
    }
    while (id_check == false)
    {
        cout << "Incorrect id entered ! Enter again : ";
        cin >> id[1];
        for (int i = 0; i < number_of_employees; i++)
        {
            if (id[1] == employee_data[i].getID())
                id_check = true;
        }
    }

    if (employee_data[id[0] - 1].getSalary() > employee_data[id[1] - 1].getSalary())
        cout << "Employee id : " << employee_data[id[0] - 1].getID() << " has more salary (" << employee_data[id[0] - 1].getSalary() << ") than " << employee_data[id[1] - 1].getID() << " (" << employee_data[id[1] - 1].getSalary() << ") " << endl;
    else if (employee_data[id[0] - 1].getSalary() < employee_data[id[1] - 1].getSalary())
        cout << "Employee id : " << employee_data[id[1] - 1].getID() << " has more salary (" << employee_data[id[1] - 1].getSalary() << ") than " << employee_data[id[0] - 1].getID() << " (" << employee_data[id[0] - 1].getSalary() << ") " << endl;
        else 
                cout << "Employee id : " << employee_data[id[1] - 1].getID() << " has equal salary (" << employee_data[id[1] - 1].getSalary() << ") as compare to " << employee_data[id[0] - 1].getID() << " (" << employee_data[id[0] - 1].getSalary() << ") " << endl;


}

int main()
{
    int number_of_employees;
    cout << "Enter the number of employees : ";
    cin >> number_of_employees;
    Employee *employee_data = new Employee[number_of_employees];
    HRManager *HR_data;
    HR_data = HRManager::getHR_Instance(employee_data, number_of_employees);
    for (int i = 0; i < number_of_employees; i++)
    {
        employee_data[i].setSalary();
        employee_data[i].setStatus();
        employee_data[i].setCasualLeaves();
        employee_data[i].setID(i + 1);
        employee_data[i].setAge();
        employee_data[i].AvailEarnedLeave();

        HR_data = HRManager::getHR_Instance(employee_data, i);
    }
    int choose = 0;
    while (choose != 3)
    {
        cout << "Choose from the menu : \n1.HR operations \n2.Employee related operations\n3.End\n Choose : ";
        cin >> choose;
        switch (choose)
        {
        case 2:
            choose = 0;
            while (choose != 8)
            {
                cout << " Choose from the menu :\n1.Employee salary\n2.Employee Age\n3.status \n4.Set Casual leaves\n5.Availed Casual leaves \n6.Earned leaves \n7.Compare Employees \n8.End \nChoose : ";
                cin >> choose;
                switch (choose)
                {
                case 1:
                    set_employee_salary(employee_data, number_of_employees, HR_data);
                    break;
                case 2:
                    set_employee_Age(employee_data, number_of_employees, HR_data);
                    break;
                case 3:
                    set_employee_status(employee_data, number_of_employees, HR_data);
                    break;
                case 4:
                    set_employee_casual_leaves(employee_data, number_of_employees, HR_data);
                    break;
                case 5:
                    set_employee_avail_casual_leaves(employee_data, number_of_employees, HR_data);
                    break;
                case 6:
                    set_employee_earned_leaves(employee_data, number_of_employees, HR_data);
                    break;
                case 7:
                    compare_employees(employee_data, number_of_employees, HR_data);
                }
            }
            break;
            case 1 :
            {
                while (choose != 5)
                {
                    choose = 0;
                    cout << " Choose from the menu : \n1.Print status of the Employees \n2.Leave Balance of the employees \n3.Salaries of the employees\n4.Specific Employee report \n5.End\n";
                    cin >> choose;
                    switch (choose)
                    {
                    case 1:
                        cout << "The status of the employee(s) is(are) : \n";
                        HRManager::employeeStatus();

                        break;
                    case 3:
                        cout << " The salaries of the employee(s) is(are) : \n";
                        HRManager::printSalaryReport();
                        break;
                    case 2:
                        cout << "The leave balance of the employee(s) is(are) : \n";
                        HRManager::printLeaveBalance();
                        break;
                    case 4:
                    {
                        Employee *temp;
                        int id;
                        bool id_check = false;
                        cout << "Enter the id of the employee : ";
                        cin >> id;
                        for (int i = 0; i < number_of_employees; i++)
                        {
                            if (id == employee_data[i].getID())
                                id_check = true;
                        }
                        while (id_check == false)
                        {
                            cout << "Incorrect id entered ! Enter again : ";
                            cin >> id;
                            for (int i = 0; i < number_of_employees; i++)
                            {
                                if (id == employee_data[i].getID())
                                    id_check = true;
                            }
                        }

                        if (id_check)
                        {
                            temp = HR_data->getEmployee(employee_data, id - 1);
                            cout << "Employee id # " << temp->getID() << endl;
                            cout << "Employee age " << temp->getAge() << endl;
                            cout << "Employee salary " << temp->getSalary() << endl;
                            cout << "Employee status " << temp->getStatus() << endl;
                            cout << "Employee Casual leaves " << temp->getCasualLeaves() << endl;
                            cout << "Employee avail casual leaves " << temp->getAvailCasualLeave() << endl;
                            cout << "Employee Earned leaves " << temp->getAvailEarnedLeave() << endl;
                        }
                        break;
                    }
                    }
                }
            }
            break;
        }
    }
    delete[] employee_data;
    // HRManager::destroying();
    return 0;
}