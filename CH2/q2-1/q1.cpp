#include <iostream>
using namespace std;

void addfunction(int &i)
{
    i++;
}

void changesign(int &i)
{
    i = -i;
}

int main(void)
{
    int j = 10;
    cout << j << endl;
    addfunction(j);
    cout << j << endl;
    changesign(j);
    cout << j << endl;
    return 0;
}