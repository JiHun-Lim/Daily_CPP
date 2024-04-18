#include <iostream>

using namespace std;

class AAA
{
private:
    int num;
    AAA(int n) : num(n) {}
public:
    AAA() : num(0) {}

    AAA& CreateInitObj(int n) const
    {
        AAA * ptr = new AAA(n);
        return *ptr;
    }

    void ShowYourName()
    {
        cout << num << endl;
    }

};

int main(void)
{
    AAA base;
    AAA &obj1 = base.CreateInitObj(3);
    AAA &obj2 = base.CreateInitObj(12);

    base.ShowYourName();
    obj1.ShowYourName();
    obj2.ShowYourName();

    delete &obj1;
    delete &obj2;

    return 0;
}