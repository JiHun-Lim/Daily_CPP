#include <iostream>
#include <cstring>

using namespace std;

class AccountException
{
public:
    virtual void ShowExceptionReason() = 0;
};

class DepositException : public AccountException
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

class WithDrawException : public AccountException
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

    void Deposit(int money) throw (AccountException)
    {
        if(money<0)
        {
            DepositException expn(money);
            throw expn;
        }
        balance += money;
    }

    void WithDraw(int money) throw (AccountException)
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
    catch(AccountException &expn)
    {
        expn.ShowExceptionReason();
    }
    myAcc.ShowMyMoney();

    try
    {
        myAcc.WithDraw(3500);
        myAcc.WithDraw(4500);
    }
    catch(AccountException &expn)
    {
        expn.ShowExceptionReason();
    }
    myAcc.ShowMyMoney();

    return 0;
    
}