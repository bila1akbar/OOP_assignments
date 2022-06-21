#include <iostream>
#include <time.h>
#include "HR.h"
using namespace std;
int Employee::empCount(0);
Employee::Employee()
{
    empCount++;
}
HRManager *HRManager::HR_data(NULL);
HRManager *HRManager::getHR_Instance(const Employee employee_data[], int Id)
{

    if (HR_data == NULL)
    {
        HR_data = new HRManager[Id];
    }
    else
    HR_data[Id].id = Id + 1;
    HR_data[Id].age = employee_data[Id].getAge();
    HR_data[Id].status = employee_data[Id].getStatus();
    HR_data[Id].salary = employee_data[Id].getSalary();
    HR_data[Id].casual_leaves = employee_data[Id].getCasualLeaves();
    HR_data[Id].casual_leaves_availed = employee_data[Id].getAvailCasualLeave();
    HR_data[Id].earned_leaves = employee_data[Id].getAvailEarnedLeave();
    return HR_data;
}
void HRManager::destroying()
{
    delete HR_data;
    // HR_data = NULL;
}
// HRManager::~HRManager()
// {
//     delete[] HR_data;
//     HR_data = NULL;
//     cout << " Destructor has been called ! \n";
// }
void Employee::setSalary()
{
    srand(time(NULL));
    int x = 1000 + (rand() % (10000));
    salary = x;

    return;
}
void Employee::setStatus()
{
    srand(time(NULL));
    bool x = (0 + (rand() % (1 - 0 + 1)) == 1);
    status = x;
    return;
}
void Employee::setID(int x)
{
    id = x;
    return;
}
// void HRManager::setSalary()
// {
//     srand(time(NULL));
//     int x = 1 + (rand() % (10000));
//     salary = x;
//     return;
// }
// void HRManager::setStatus()
// {
//     srand(time(NULL));
//         bool x =(0 + (rand() % (1 - 0 + 1)) == 1);
//     status = x;
//     return;
// }
// void HRManager::setID(int x)
// {
//     id = x;
//     return;
// }
// void HRManager::setAge()
// {
//     srand(time(NULL));
//     int x;
//     x = 20 + (rand() % (60));
//     age=x;
//     return;
// }
void Employee::setAge()
{
    srand(time(0));
    int x;
    x = rand() % (20 - 60 + 1) + 20;
    age = x;
    return;
}
int Employee::getSalary() const
{
    return salary;
};
int Employee::getStatus() const
{
    return status;
};
int Employee::getAge() const
{
    return age;
};
int Employee::getID() const
{
    return id;
};
void Employee::setCasualLeaves()
{
    srand(time(NULL));
    int x;
    x = 1 + (rand() % (10));
    casual_leaves = x;
    casual_leaves_availed = 10 - casual_leaves;
};
void Employee::AvailEarnedLeave()
{
    srand(time(NULL));
    int x;
    x = 20 - (1 + (rand() % (20)));
    earned_leaves = x;
};
int Employee::getCasualLeaves() const
{
    return casual_leaves;
};
int Employee ::getAvailCasualLeave() const
{
    return casual_leaves_availed;
};
int Employee ::getAvailEarnedLeave() const
{
    return earned_leaves;
};
int Employee::get_emp_count()
{
    return empCount;
}
// void HRManager::AvailEarnedLeave()
// {
//     srand(time(NULL));
//     int x;
//     x = 20 - 1 + (rand() % (20));
//     earned_leaves=x;
// };
int HRManager::getCasualLeaves() const
{
    return casual_leaves;
};
int HRManager ::getAvailCasualLeave() const
{
    return casual_leaves_availed;
};
int HRManager ::getAvailEarnedLeave() const
{
    return earned_leaves;
};
int HRManager::getSalary() const
{
    return salary;
};
int HRManager::getStatus() const
{
    return status;
};
int HRManager::getAge() const
{
    return age;
};
int HRManager::getID() const
{
    return id;
};
Employee *HRManager::getEmployee(Employee employee_data[], int Id)
{
    return (employee_data + Id);
}
void HRManager::employeeStatus()
{
    for (int i = 0; i < Employee::get_emp_count(); i++)
    {
        cout<<"Employee id#"<<HR_data[i].getID()<<" status is "<<HR_data[i].getStatus()<<endl;
    }
}
void HRManager::printSalaryReport()
{
    for (int i = 0; i < Employee::get_emp_count(); i++)
    {
        cout<<"Employee id#"<<HR_data[i].getID()<<" salary is "<<HR_data[i].getSalary()<<endl;
    }
}
void HRManager::printLeaveBalance()
{
    for (int i = 0; i < Employee::get_emp_count(); i++)
    {
        cout<<"Employee id#"<<HR_data[i].getID()<<" leave balance is "<<HR_data[i].getAvailCasualLeave() + HR_data[i].getAvailEarnedLeave()<<endl;
    }
}