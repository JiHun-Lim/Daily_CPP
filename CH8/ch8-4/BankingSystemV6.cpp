#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN = 20;

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

enum { Level_A = 7, Level_B = 4, Level_C = 2};

enum { Normal = 1, Credit = 2};

class Account
{
private:
    int accID;
    int balance;
    char * cusName;
public:
    Account(int ID, int money, char *name);
    Account(const Account & copy);

    int GetACCID() const;
    virtual void Deposit(int money);
    int Withdraw(int money);
    void ShowAccInfo() const;
    ~Account();
};

Account::Account(int ID, int money, char *name) : accID(ID), balance(money)
{
    cusName = new char[strlen(name) +1];
    strcpy(cusName, name);
}

Account::Account(const Account& copy): accID(copy.accID), balance(copy.balance)
{
    cusName = new char[strlen(copy.cusName) +1];
    strcpy(cusName, copy.cusName);
}

int Account::GetACCID() const
{
    return accID;
}

void Account::Deposit(int money)
{
    balance += money;
}

int Account::Withdraw(int money)
{
    if (balance < money)
        return 0;
    
    balance -= money;
    return money;
}

void Account::ShowAccInfo() const
{
    cout << "ID : " << accID << endl;
    cout << "Name : " << cusName << endl;
    cout << "Balance : " << balance << endl;

}

Account::~Account()
{
    delete []cusName;
}

class NormalAccount : public Account
{
private:
    int interRate;

public:
    NormalAccount(int ID, int money, char * name, int rate) : Account(ID, money, name), interRate(rate) {}

    virtual void Deposit(int money)
    {
        Account::Deposit(money);
        Account::Deposit(money * interRate / 100);
    }

};

class HighCreditAccount : public NormalAccount
{
private:
    int specialRate;

public:
    HighCreditAccount(int ID, int money, char * name, int rate, int special) : NormalAccount(ID, money, name, rate), specialRate(special) {}

    virtual void Deposit(int money)
    {
        NormalAccount::Deposit(money);
        NormalAccount::Deposit(money * specialRate / 100);
    }
};

class AccountHandler
{
private:
    Account * accArr[100];
    int accNum ;

public:
    AccountHandler();
    void ShowMenu(void) const;
    void MakeAccount(void);
    void DepositMoney(void);
    void WithdrawMoney(void);
    void ShowAllAccInfo(void) const;
    ~AccountHandler();

protected:
    void MakeNormalAccount(void);
    void MakeCreditAccount(void);
};

AccountHandler::AccountHandler() : accNum(0) {}

void AccountHandler::ShowMenu(void) const
{
    cout << "--------Menu--------" << endl;
    cout << "1. Make an account" << endl;
    cout << "2. Make a deposit" << endl;
    cout << "3. Make a withdraw" << endl;
    cout << "4. Print accout information" << endl;
    cout << "5. Program exit" << endl;
}

void AccountHandler::MakeAccount(void)
{
    int sel;

    cout << "Choose Account Type" << endl;

    cout << "1. Normal Account" << endl;
    cout << "2. Credit Account" << endl;

    cout << "Choose";

    cin >> sel;

    if(sel == 1)
        MakeNormalAccount();
    else
        MakeCreditAccount();
}

void AccountHandler::MakeNormalAccount(void)
{
    int id;
    char name[NAME_LEN];
    int balance;
    int interRate;

    cout << "[Make Account]" << endl;
    cout << "Account ID : ";
    cin >> id;
    cout << "Name : ";
    cin >> name;
    cout << "Balance : ";
    cin >> balance;
    cout << "Rate : ";
    cin >> interRate;
    cout << endl;

    accArr[accNum++] = new NormalAccount(id, balance, name, interRate);

}

void AccountHandler::MakeCreditAccount(void)
{
    int id;
    char name[NAME_LEN];
    int balance;
    int interRate;
    int creditLevel;

    cout << "[Make Account]" << endl;
    cout << "Account ID : ";
    cin >> id;
    cout << "Name : ";
    cin >> name;
    cout << "Balance : ";
    cin >> balance;
    cout << "Rate : ";
    cin >> interRate;
    cout << "Credit Level(1toA, 2toB, 3toC) : ";
    cin >> creditLevel;
    cout << endl;

    switch(creditLevel)
    {
    case 1:
        accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, Level_A);
        break;
    case 2:
        accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, Level_B);
        break;
    case 3:
        accArr[accNum++] = new HighCreditAccount(id, balance, name, interRate, Level_C);
    }
}

void AccountHandler::DepositMoney(void)
{
    int money;
    int id;

    cout << "[Deposit]";
    cout << "Account ID : ";
    cin >> id;
    cout << "Money : ";
    cin >> money;

    for (int i = 0; i < accNum; i++)
    {
        if (accArr[i]->GetACCID() == id)
        {
            accArr[i]->Deposit(money);
            cout << "Deposit Finished" << endl;
            return;
        }
    }
    cout << "Not a valid ID" << endl << endl;
}

void AccountHandler::WithdrawMoney(void)
{
    int money;
    int id;

    cout << "[Withdraw]" << endl;
    cout << "Account ID : ";
    cin >> id;
    cout << "Money : ";
    cin >> money;

    for (int i = 0; i< accNum; i++)
    {
        if (accArr[i]->GetACCID() == id)
        {
            if(accArr[i]->Withdraw(money) != 0)
            {
                cout << "Withdraw Finished" << endl;
                return;
            }
            else
            {
                cout << "Not enough Money" << endl;
                return;
            }
        }
    }

    cout << "Not a valid ID" << endl;
}

void AccountHandler::ShowAllAccInfo(void) const
{

    for(int i=0; i < accNum; i++)
    {
        accArr[i]->ShowAccInfo();
        cout << endl;
    }
}

AccountHandler::~AccountHandler()
{
    for (int i = 0; i< accNum; i++)
    {
        delete accArr[i];
    }
}

int main(void)
{
    AccountHandler manager;

    int choice;

    while(1)
    {
        manager.ShowMenu();
        cout << "Choose : ";
        cin >> choice;
        cout << endl;
        switch(choice)
        {
        case MAKE:
            manager.MakeAccount();
            break;
        case DEPOSIT:
            manager.DepositMoney();
            break;
        case WITHDRAW:
            manager.WithdrawMoney();
            break;
        case INQUIRE:
            manager.ShowAllAccInfo();
            break;
        case EXIT:
            return 0;
        default:
            cout << "Illegal selection.." << endl;
        }
    }
    return 0;
}




