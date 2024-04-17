#include <iostream>
using namespace std;

int main(void)
{
    const int num = 12;
    const int * num_p = &num;
    // const int ** num_pp = &num_p;
    const int *(& num_pp) = num_p;

    cout << num << endl;
    cout << num_p << " and " << *num_p << endl;
    // cout << num_pp << " and " << *num_pp << " and " << **num_pp << endl;
    cout << &num_pp << " and " << num_pp << " and " << *num_pp << endl;
    return 0;
}