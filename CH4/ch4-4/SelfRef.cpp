#include <iostream>

using namespace std;

class SelfRef
{
private:
    int num;

public:
    SelfRef(int n) : num(n)
    {
        cout << "Obeject Initiated" << endl;
    }

    SelfRef& Adder (int n)
    {
        num += n;
        return *this;
    }

    SelfRef& ShowTwoNumber()
    {
        cout << num << endl;
        return *this;
    }
};

int main(void)
{
    SelfRef obj(3);
    SelfRef &ref = obj.Adder(2);

    obj.ShowTwoNumber();
    ref.ShowTwoNumber();

    ref.Adder(1).ShowTwoNumber().Adder(3).ShowTwoNumber();

    return 0;
}