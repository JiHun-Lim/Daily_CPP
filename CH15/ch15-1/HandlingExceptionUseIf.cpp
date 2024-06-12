#include <iostream>
using namespace std;

int main(void)
{
    int num1, num2;
    cout << "Write two numbers : ";
    cin >> num1 >> num2;

    if(num2 == 0)
    {
        cout << "Can't divide by 0" << endl;
        cout << "Restart the Program" << endl;
    }
    else
    {
        cout << "Quotient : " << num1 / num2 << endl;
        cout << "Remainder : " << num1 % num2 << endl;
    }
    return 0;
}