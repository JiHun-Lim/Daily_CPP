#include <iostream>
#include <new>
using namespace std;

int main(void)
{
    int num = 0;

    try
    {
        while(1)
        {
            num++;
            cout << num << "Number confirmed" << endl;
            new int[100][100];
        }
    }
    catch(bad_alloc &bad)
    {
        cout << bad.what() << endl;
        cout << "No more Exceptable" << endl;
    }
    return 0;
}