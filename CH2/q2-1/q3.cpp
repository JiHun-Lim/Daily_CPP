#include <iostream>
using namespace std;

void SwapPointer(int *(&a), int *(&b))
{
    int *temp = a;
    a = b;
    b = temp;
}


int main(void)
{
    int num1 = 5;
    int *ptr1 = &num1;
    int num2 = 10;
    int *ptr2 = &num2;

    cout << *ptr1 << " and " << *ptr2 << endl;

    SwapPointer(ptr1, ptr2);

    cout << *ptr1 << " and " << *ptr2 << endl;

    return 0;
}