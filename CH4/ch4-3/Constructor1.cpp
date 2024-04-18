#include <iostream>
using namespace std;

class SimpleClass
{
private:
    int num1;
    int num2;

public:
    SimpleClass()
    {
        num1 = 0;
        num2 = 0;
    }
    SimpleClass(int n)
    {
        num1 = n;
        num2 = 0;
    }
    SimpleClass(int n, int m)
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
    SimpleClass sc1;
    sc1.Showdata();

    SimpleClass sc2(100);
    sc2.Showdata();

    SimpleClass sc3(100, 200);
    sc3.Showdata();

    return 0;
}