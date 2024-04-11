#include <iostream>
using namespace std;

int val = 100;

int SimpleFunc(void)
{
    int val = 20;
    val += 3;
    cout << "Inside val == " << val << endl;
    ::val += 7;
}

int main(void)
{
    SimpleFunc();
    cout << "Outside val == " << val << endl;
    return 0;
}