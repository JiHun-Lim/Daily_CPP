#include <iostream>
using namespace std;

class FruitSeller
{
private:
    int APPLE_PRICE;
    int numOfApples;
    int myMoney;

public:
    void InintMembers(int price, int num, int money)
    {
        APPLE_PRICE = price;
        numOfApples = num;
        myMoney = money;
    }
    
    int SaleApples(int money)
    {
        int num = money / APPLE_PRICE;
        numOfApples -= num;
        myMoney += money;
        return num;
    }

    void ShowSalesResult() const
    {
        cout << "Apple left : " << numOfApples << endl;
        cout << "Margin left : " << myMoney << endl;
    }

};

class FruitBuyer
{
private:
    int myMoney;
    int numOfApples;

public:
    void InitMembers(int money)
    {
        myMoney = money;
        numOfApples = 0;
    }

    void BuyApples(FruitSeller &seller, int money)
    {
        if (money < 0)
        {
            cout << "Not enough money for buy" << endl;
            return;
        }

        numOfApples += seller.SaleApples(money);
        myMoney -= money;
    }

    void ShowBuyResult() const
    {
        cout << "Current Account : " << myMoney << endl;
        cout << "Number of Apples : " << numOfApples << endl;
    }

};

int main(void)
{
    FruitSeller seller;
    seller.InintMembers(1000, 20, 0);
    FruitBuyer buyer;
    buyer.InitMembers(5000);
    buyer.BuyApples(seller, 2000);

    cout << "Current status of Sales" << endl;
    seller.ShowSalesResult();
    cout << "Current status of Buyer" << endl;
    buyer.ShowBuyResult();

    buyer.BuyApples(seller, -2000);
    buyer.ShowBuyResult();

    return 0;
}