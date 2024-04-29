#include <iostream>

using namespace std;

class BaseOne
{
public:
    void SimpleFuncOne()
    {
        cout << "BaseOne" << endl;
    }
};

class BaseTwo
{
public:
    void SimpleFUncTwo()
    {
        cout << "BaseTwo" << endl;
    }
};

class MultiDerived : public BaseOne, protected BaseTwo
{
public:
    void ComplexFunc()
    {
        SimpleFuncOne();
        SimpleFUncTwo();
    }

};

int main(void)
{
    MultiDerived mee;
    mee.ComplexFunc();
    return 0;
}
