#pragma once
class Employee;
class HRManager
{ /*Special class with only one instance during execution of the
program, there is only one HR manager*/
private:
private:
    int id;
    int age;
    bool status;
    int salary;
    int casual_leaves, casual_leaves_availed, earned_leaves;
    static HRManager *HR_data;

public:
    // provide definitions of following functions...

    static HRManager *getHR_Instance(const Employee[], int); // always returns a pointer/instance to the one and only instance of HRManager, when called the first time create a record of N employees
    Employee *getEmployee(Employee[],int);                                // returns Employee instance with the given ID
    static void employeeStatus();                                // prints the status of all the employees
    static void printLeaveBalance();                        // prints the leave balance of all the employees
    static void printSalaryReport();                        // prints the salary of all employees
    int getSalary() const;
    int getStatus() const;
    int getAge() const;
    int getID() const;
    int getCasualLeaves() const;
    int getAvailCasualLeave() const;
    int getAvailEarnedLeave() const; 
    static void destroying();
    // same as above but for earned leaves
    // ~HRManager();
};
class Employee
{
private:
    int id;
    int age;
    bool status;
    int salary;
    int casual_leaves, casual_leaves_availed, earned_leaves;
    // private data members (id, age, status(idle-0/busy-1), salary, casual leaves total, casual leave availed, earned leaves)
    static int empCount;

public:
    Employee();
    // parameterized constructors (3)
    //  copy constructor
    // whenever an employee state is change HRManager instance is called from that function
    void setSalary();
    void setStatus();
    void setID(int);
    void setAge();
    int getSalary() const;
    int getStatus() const;
    int getAge() const;
    int getID() const;
    void setCasualLeaves();
    // void AvailCasualLeave(); // Employee avails casual leaves, leaves record will be updated and also updated for HRManager using its instance
    void AvailEarnedLeave();
    int getCasualLeaves() const;
    int getAvailCasualLeave() const;
    int getAvailEarnedLeave() const; // same as above but for earned leaves
    void CompareEmployee(Employee);  // compares two employees, return the one with higher salary
    static int get_emp_count();
};