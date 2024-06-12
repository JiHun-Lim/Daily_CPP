#include <iostream>
using namespace std;

void Divide(int num1, int num2)
{
    try
    {
        if(num2 == 0)
        {
            throw 0;
        }
        cout << "Quotient : " << num1 / num2 << endl;
        cout << "Remainder : " << num1 % num2 << endl;
    }
    catch(int expn)
    {
        cout << "First Catch" << endl;
        throw;
    }   
}

int main(void)
{
    try
    {
        Divide(9, 2);
        Divide(4, 0);
    }
    catch(int expn)
    {
        cout << "Second Catch " << endl;
    }
    
    return 0;
}