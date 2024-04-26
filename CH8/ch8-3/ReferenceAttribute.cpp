#include <iostream>
using namespace std;

class First
{
public:
    void FirstFunc()
    {
        cout << "First" << endl;
    }

    virtual void SimpleFunc()
    {
        cout << "First SimpleFunc" << endl;
    }
};

class Second : public First
{
public:
    void SecondFunc()
    {
        cout << "Second" << endl;
    }

    virtual void SimpleFunc()
    {
        cout << "Second SimpleFunc" << endl;
    }

};

class Third : public Second
{
public:
    void ThirdFunc()
    {
        cout << "Third" << endl;
    }

    virtual void SimpleFunc()
    {
        cout << "Third SimpleFunc" << endl;
    }
};

int main(void)
{
    Third obj;

    obj.FirstFunc();
    obj.SecondFunc();
    obj.ThirdFunc();
    obj.SimpleFunc();

    cout << "-----------------" << endl;
    Second & sref = obj;

    sref.FirstFunc();
    sref.SecondFunc();
    sref.SimpleFunc();

    cout << "-----------------" << endl;
    First & fref = obj;

    fref.FirstFunc();
    fref.SimpleFunc();

    return 0;
}