#include <iostream>
using namespace std;

int main(void)
{
    int num1, num2;
    cout << "Write two numbers : ";
    cin >> num1 >> num2;

    try
    {
        if(num2 == 0)
        {
            throw num2;
        }
        cout << "Quotient : " << num1 / num2 << endl;
        cout << "Remainder : " << num1 % num2 << endl;
    }
    catch(int expn)
    {
        cout << "Can't divide by " << expn << endl;
        cout << "Restart the Program" << endl;
    }

    cout << "End of Main" << endl;

    return 0;
    
}