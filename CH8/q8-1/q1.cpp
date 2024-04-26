#include <iostream>
#include <cstring>

using namespace std;

enum RISK_LEVEL {RISK_A = 30, RISK_B = 20, RISK_C = 10};

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

    virtual int GetPay() const
    {
        return 0;
    }
    
    virtual void ShowSalaryInfo() const {}

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

class TemporaryWorker : public Employee
{
private:
    int workTime;
    int payPerHour;

public:
    TemporaryWorker(char * name, int pay) : Employee(name), workTime(0), payPerHour(pay) {}

    void AddWorkTime(int time)
    {
        workTime += time;
    }

    int GetPay() const
    {
        return workTime * payPerHour;
    }

    void ShowSalaryInfo() const
    {
        Employee::ShowYourName();
        cout << "Salary : " << GetPay() << endl;
    }

};

class SalesWorker : public PermanentWorker
{
private:
    int salesResult;
    double bonusRatio;

public:
    SalesWorker(char * name, int money, double ratio) : PermanentWorker(name, money), salesResult(0), bonusRatio(ratio) {}

    void AddSalesResult (int value)
    {
        salesResult += value;
    }

    int GetPay() const
    {
        return PermanentWorker::GetPay() + (int)(salesResult * bonusRatio);
    }

    void ShowSalesInfo() const
    {
        PermanentWorker::ShowYourName();
        cout << "Salary : " << GetPay() << endl;
    }

};

class ForeignSalesWorker : public SalesWorker
{
private:
    int risk;

public:
    ForeignSalesWorker(char * name, int money, double rate, int risk_level) : SalesWorker(name, money, rate), risk(risk_level) {}

    void AddSalesResult(int value)
    {
        SalesWorker::AddSalesResult(value);
    }

    void ShowSalaryInfo() const
    {
        SalesWorker::ShowSalaryInfo();
        cout << "Risk Pay : " << SalesWorker::GetPay() * risk / 100 << endl;
        cout << "Sum : " << SalesWorker::GetPay() * risk / 100 + SalesWorker::GetPay() << endl << endl;
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

    ForeignSalesWorker * fseller1 = new ForeignSalesWorker("Lim", 1000, 0.1, RISK_LEVEL::RISK_A);
    fseller1->AddSalesResult(7000);
    handler.AddEmployee(fseller1);

    ForeignSalesWorker * fseller2 = new ForeignSalesWorker("Kim", 1000, 0.1, RISK_LEVEL::RISK_B);
    fseller2->AddSalesResult(7000);
    handler.AddEmployee(fseller2);

    ForeignSalesWorker * fseller3 = new ForeignSalesWorker("Joo", 3000, 0.1, RISK_LEVEL::RISK_C);
    fseller3->AddSalesResult(14000);
    handler.AddEmployee(fseller3);

    handler.ShowAllSalaryInfo();

    return 0;
}
