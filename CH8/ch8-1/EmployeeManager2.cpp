#include <iostream>
#include <cstring>

using namespace std;

class Employee
{
private:
    char name[100];

public:
    Employee(char * name)
    {
        strcpy(this->name, name);
    }

    void ShowYourName() const
    {
        cout << "Name : " << name << endl;
    }

};

class PermanentWorker : public Employee
{
private:
    int salary;

public:
    PermanentWorker(char* myname, int money) : Employee(myname), salary(money) {}

    int GetPay() const
    {
        return salary;
    }

    void ShowSalaryInfo() const
    {
        ShowYourName();
        cout << "Salary : " << GetPay() << endl;
    }

};

class EmployeeHandler
{
private:
    Employee* empList[50];
    int empNum;

public:
    EmployeeHandler() : empNum(0) {}

    void AddEmployee(Employee* emp)
    {
        empList[empNum++] = emp;
    }

    void ShowAllSalaryInfo() const
    {
        // for (int i=0; i<empNum; i++)
        //     empList[i]->ShowSalaryInfo();
    }

    void ShowTotalSalary() const
    {
        int sum = 0;
        // for (int i = 0; i < empNum; i++)
        //     sum += empList[i]->GetPay();
        cout << "Total Salary : " << sum << endl;
    }

    ~EmployeeHandler()
    {
        for (int i=0; i<empNum; i++)
            delete empList[i];
    }

};

int main(void)
{
    EmployeeHandler handler;

    handler.AddEmployee(new PermanentWorker("Lim", 1000));
    handler.AddEmployee(new PermanentWorker("Lim", 1000));
    handler.AddEmployee(new PermanentWorker("Kim", 1000));

    handler.ShowAllSalaryInfo();

    handler.ShowTotalSalary();

    return 0;
}
