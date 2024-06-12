#include <iostream>
using namespace std;

int main(void)
{
    int num1, num2;
    cout << "Write two numbers : ";
    cin >> num1 >> num2;

    cout << "Quotient : " << num1 / num2 << endl;
    cout << "Remainder : " << num1 % num2 << endl;

    return 0;
}