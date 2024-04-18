#include <iostream>
using namespace std;

class SimpleClass
{
private:
    int num1;
    int num2;

public:
    SimpleClass(int n=0, int m=0)
    {
        num1 = n;
        num2 = m;
    }

    void Showdata() const
    {
        cout << "num1 is " << num1 << ", num2 is " << num2 << endl;
    }
};

int main(void)
{
    SimpleClass sc1();
    SimpleClass mysc = sc1();
    mysc.Showdata();

    return 0;
}

SimpleClass sc1()
{
    SimpleClass sc(20, 30);
    return sc;
}