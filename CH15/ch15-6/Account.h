#ifndef __ACCOUNT__H__
#define __ACCOUNT__H__

#include "String.h"

class Account
{
private:
    int accID;
    int balance;
    String cusName;

public:
    Account(int ID, int money, String name);
    int GetACCID() const;
    virtual void Deposit(int money);
    int Withdraw(int money);
    void ShowAccInfo() const;
};

#endif