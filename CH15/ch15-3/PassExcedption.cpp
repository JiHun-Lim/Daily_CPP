#include <iostream>
using namespace std;

void Divide(int num1, int num2)
{
    if(num2 == 0)
    {
        throw num2;
    }
    cout << "Can't divide by 0" << endl;
    cout << "Restart the Program" << endl;
}

int main(void)
{
    int num1, num2;
    cout << "Write two numbers : ";
    cin >> num1 >> num2;
    
    try
    {
        Divide(num1, num2);
        cout << "Finished Division" << endl;
    }
    catch(int expn)
    {
        cout << "Can't divide by " << expn << endl;
        cout << "Restart the Program" << endl;
    }
    


    return 0;
}