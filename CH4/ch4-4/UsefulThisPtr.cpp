#include <iostream>

using namespace std;

class TwoNumber
{
private:
    int num1;
    int num2;

public:
    TwoNumber(int number1, int number2)
    {
        this->num1 = number1;
        this->num2 = number2;
    }

    // TwoNumber(int number1, int number2) : num1(number1), num2(number2) {}

    void ShowTwoNumber()
    {
        cout << this->num1 << endl;
        cout << this->num2 << endl;
    }

};

int main(void)
{
    TwoNumber two(2, 4);
    two.ShowTwoNumber();

    return 0;
}