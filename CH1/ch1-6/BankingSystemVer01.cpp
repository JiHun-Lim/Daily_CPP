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

typedef struct
{
    int accID;
    int balance;
    char cusName[NAME_LEN];
} Account;

Account accArr[100];
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

    accArr[accNum].accID = id;
    accArr[accNum].balance = balance;
    strcpy(accArr[accNum].cusName, name);
    accNum++;

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
        if (accArr[i].accID == id)
        {
            accArr[i].balance += money;
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
        if (accArr[i].accID == id)
        {
            if(accArr[i].balance > money)
            {
                accArr[i].balance -= money;
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
    int id;

    cout << "[Account Info]" << endl;
    cout << "Account ID : ";
    cin >> id;

    for(int i=0; i < accNum; i++)
    {
        if (accArr[i].accID == id)
        {
            cout << "ID : " << id << endl;
            cout << "Name : " << accArr[i].cusName << endl;
            cout << "Balance : " << accArr[i].balance << endl;
            return;
        }
    }

    cout << "Not a valid ID" << endl;
}