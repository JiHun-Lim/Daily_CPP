#include <iostream>
#include <cstring>

using namespace std;

class PermanentWorker
{
private:
    char name[100];
    int salary;

public:
    PermanentWorker(char* myname, int money) : salary(money)
    {
        strcpy(this->name, myname);
    }

    int GetPay() const
    {
        return salary;
    }

    void ShowSalaryInfo() const
    {
        cout << "Name : " << name << endl;
        cout << "Salary : " << salary << endl;
    }

};

class EmployeeHandler
{
private:
    PermanentWorker* empList[50];
    int empNum;

public:
    EmployeeHandler() : empNum(0) {}

    void AddEmployee(PermanentWorker* emp)
    {
        empList[empNum++] = emp;
    }

    void ShowAllSalaryInfo() const
    {
        for (int i=0; i<empNum; i++)
            empList[i]->ShowSalaryInfo();
    }

    void ShowTotalSalary() const
    {
        int sum = 0;
        for (int i = 0; i < empNum; i++)
            sum += empList[i]->GetPay();
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
