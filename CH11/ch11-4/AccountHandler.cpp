#include "AccountHandler.h"
#include "Account.h"
#include "BankingCommonDecl.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"


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
