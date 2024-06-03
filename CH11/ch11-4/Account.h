#ifndef __ACCOUNT__H__
#define __ACCOUNT__H__

class Account
{
private:
    int accID;
    int balance;
    char * cusName;

public:
    Account(int ID, int money, char *name);
    Account(const Account & copy);
    Account& operator=(const Account& copy);

    int GetACCID() const;
    virtual void Deposit(int money);
    int Withdraw(int money);
    void ShowAccInfo() const;
    ~Account();
};

#endif