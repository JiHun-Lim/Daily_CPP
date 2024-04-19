#include <iostream>

using namespace std;

class Sosimple
{
private:
    int num1;
    int num2;

public:
    Sosimple(int number1, int number2) : num1(number1), num2(number2) {}

    Sosimple(Sosimple &copy) : num1(copy.num1), num2(copy.num2)
    {
        cout << "Called Sosimple (Sosimple &copy)" << endl;
    }

    void ShowSimpleData()
    {
        cout << num1 << endl;
        cout << num2 << endl;
    }
};

int main(void)
{
    Sosimple sim1(15, 30);

    sim1.ShowSimpleData();

    cout << "Before Copy Construct" << endl;

    Sosimple sim2(sim1);

    sim2.ShowSimpleData();

    Sosimple sim3 = sim2;

    sim3.ShowSimpleData();

    return 0;
}