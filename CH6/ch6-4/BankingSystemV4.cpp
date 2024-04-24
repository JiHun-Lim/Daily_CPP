#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN = 20;

void ShowMenu(void);
void MakeAccount(void);
void DepositMoney(void);
void WithdrawMoney(void);
void ShowYourAccInfo(void);

enum {MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};

class Account
{
private:
    int accID;
    int balance;
    char * cusName;
public:
    Account(int ID, int money, char *name) : accID(ID), balance(money)
    {
        cusName = new char[strlen(name) +1];
        strcpy(cusName, name);
    }

    Account(const Account& copy): accID(copy.accID), balance(copy.balance)
    {
        cusName = new char[strlen(copy.cusName) +1];
        strcpy(cusName, copy.cusName);
    }

    int GetACCID() const
    {
        return accID;
    }

    void Deposit(int money)
    {
        balance += money;
    }

    int Withdraw(int money)
    {
        if (balance < money)
            return 0;
        
        balance -= money;
        return money;
    }

    void ShowAccInfo() const
    {
        cout << "ID : " << accID << endl;
        cout << "Name : " << cusName << endl;
        cout << "Balance : " << balance << endl;
   
    }

    ~Account()
    {
        delete []cusName;
    }

};

Account * accArr[100];
int accNum = 0;


int main(void)
{
    int choice;

    while(1)
    {
        ShowMenu();
        cout << "Choose : ";
        cin >> choice;
        cout << endl;
        switch(choice)
        {
        case MAKE:
            MakeAccount();
            break;
        case DEPOSIT:
            DepositMoney();
            break;
        case WITHDRAW:
            WithdrawMoney();
            break;
        case INQUIRE:
            ShowYourAccInfo();
            break;
        case EXIT:
            return 0;
        default:
            cout << "Illegal selection.." << endl;
        }
    }
    return 0;
}

void ShowMenu(void)
{
    cout << "--------Menu--------" << endl;
    cout << "1. Make an account" << endl;
    cout << "2. Make a deposit" << endl;
    cout << "3. Make a withdraw" << endl;
    cout << "4. Print accout information" << endl;
    cout << "5. Program exit" << endl;
}

void MakeAccount(void)
{
    int id;
    char name[NAME_LEN];
    int balance;

    cout << "[Make Account]" << endl;
    cout << "Account ID : ";
    cin >> id;
    cout << "Name : ";
    cin >> name;
    cout << "Balance : ";
    cin >> balance;
    cout << endl;

    accArr[accNum++] = new Account(id, balance, name);

}

void DepositMoney(void)
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

void WithdrawMoney(void)
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

void ShowYourAccInfo(void)
{

    for(int i=0; i < accNum; i++)
    {
        accArr[i]->ShowAccInfo();
        cout << endl;
    }
}