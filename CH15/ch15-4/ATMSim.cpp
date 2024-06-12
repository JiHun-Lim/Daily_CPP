#include <iostream>
#include <cstring>

using namespace std;

class DepositException
{
private:
    int reqDep;

public:
    DepositException(int money) : reqDep(money) {}

    void ShowExceptionReason()
    {
        cout << "[Exception Message : " << reqDep << " is not acceptable]" << endl;
    }

};

class WithDrawException
{
private:
    int balance;

public:
    WithDrawException(int money) : balance(money) {}
    void ShowExceptionReason()
    {
        cout << "[Exception Message : Balance " << balance << " is not acceptable]" << endl;
    }
};

class Account
{
private:
    char accNum[50];
    int balance;

public:
    Account(char * acc, int money) : balance(money)
    {
        strcpy(accNum, acc);
    }

    void Deposit(int money) throw (DepositException)
    {
        if(money<0)
        {
            DepositException expn(money);
            throw expn;
        }
        balance += money;
    }

    void WithDraw(int money) throw (WithDrawException)
    {
        if(money > balance)
        {
            throw WithDrawException(balance);
        }
        balance -= money;
    }

    void ShowMyMoney()
    {
        cout << "Balance : " << balance << endl << endl;
    }
};

int main(void)
{
    Account myAcc("56789-827120", 5000);

    try
    {
        myAcc.Deposit(2000);
        myAcc.Deposit(-300);
    }
    catch(DepositException &expn)
    {
        expn.ShowExceptionReason();
    }
    myAcc.ShowMyMoney();

    try
    {
        myAcc.WithDraw(3500);
        myAcc.WithDraw(4500);
    }
    catch(WithDrawException &expn)
    {
        expn.ShowExceptionReason();
    }
    myAcc.ShowMyMoney();

    return 0;
    
}