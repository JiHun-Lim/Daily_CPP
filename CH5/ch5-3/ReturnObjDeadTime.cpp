#include <iostream>

using namespace std;

class SoSimple
{
private:
    int num;

public:
    SoSimple(int number): num(number) 
    {
        cout << "New object : " << this << endl;
    }

    SoSimple(const SoSimple& copy) : num(copy.num)
    {
        cout << "New copy object : " << this << endl;
    }

    ~SoSimple()
    {
        cout << "Destroy Sosimple" << this << endl;
    }

};

SoSimple SimpleFuncObj(SoSimple ob)
{
    cout << "Parm ADR : " << &ob << endl;
    return ob;
}

int main(void)
{
    SoSimple obj(7);

    SimpleFuncObj(obj);

    cout << endl;

    SoSimple temRef = SimpleFuncObj(obj);

    // cout << "Return Obj " << &temRef << endl;

    return 0;
}