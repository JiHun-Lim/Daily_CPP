#include <iostream>
using namespace std;

void SwawpByRef2(int &ref1, int &ref2)
{
    int temp = ref1;
    ref1 = ref2;
    ref2 = temp;
}

int main(void)
{
    int val1 = 10;
    int val2 = 20;

    SwawpByRef2(val1, val2);
    // SwawpByRef2(23, 45);
    // cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’

    cout << "val1 : " << val1 << endl;
    cout << "val2 : " << val2 << endl;

    return 0;
}