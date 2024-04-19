#include <iostream>

using namespace std;

class SoSimple
{
private:
    int num;

public:
    SoSimple(int number): num(number) {}

    SoSimple(const SoSimple& copy) : num(copy.num)
    {
        cout << "Called SoSimple (const SoSimple& copy)" << endl;
    }

    void Showdata()
    {
        cout << "num : " << num << endl;
    }

};

void SimpleFuncObj(SoSimple ob)
{
    ob.Showdata();
}

int main(void)
{
    SoSimple obj(7);

    SimpleFuncObj(obj);

    return 0;
}