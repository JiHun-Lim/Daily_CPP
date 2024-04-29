#include <iostream>
using namespace std;

class Base
{
public:
    Base()
    {
        cout << "Base Constructor" << endl;
    }

    void SimpleFunc()
    {
        cout << "Base One" << endl;
    }

};

class MiddleDerivedOne : virtual public Base
{
public:
    MiddleDerivedOne() : Base()
    {
        cout << "MiddleDerived One Constructor" << endl;
    }

    void MiddleFuncOne()
    {
        SimpleFunc();
        cout << "MiddleDerived One" << endl;
    }

};

class MiddleDerivedTwo : virtual public Base
{
public:
    MiddleDerivedTwo() : Base()
    {
        cout << "MiddleDerived Two Constructor" << endl;
    }

    void MiddleFuncTwo()
    {
        SimpleFunc();
        cout << "MiddleDerived Two" << endl;
    }

};

class LastDerived : public MiddleDerivedOne, public MiddleDerivedTwo
{
public:
    LastDerived() : MiddleDerivedOne(), MiddleDerivedTwo()
    {
        cout << "LastDerived Constructor" << endl;
    }

    void ComplexFunc()
    {
        MiddleDerivedOne();
        MiddleDerivedTwo();
        SimpleFunc();
    }

};

int main(void)
{
    LastDerived ldr;
    cout << "---------------------" << endl;
    ldr.ComplexFunc();
    return 0;
}