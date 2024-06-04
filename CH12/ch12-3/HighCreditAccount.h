#ifndef __HIGHCREDIT_ACCOUNT_H__
#define __HIGHCREDIT_ACCOUNT_H__

#include "String.h"

class HighCreditAccount : public NormalAccount
{
private:
    int specialRate;

public:
    HighCreditAccount(int ID, int money, String name, int rate, int special) : NormalAccount(ID, money, name, rate), specialRate(special) {}

    virtual void Deposit(int money)
    {
        NormalAccount::Deposit(money);
        NormalAccount::Deposit(money * specialRate / 100);
    }
};

#endif