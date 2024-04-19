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

    SoSimple& AddNum(int n)
    {
        num += n;
        return *this;
    }

    void Showdata()
    {
        cout << "num : " << num << endl;
    }

};

SoSimple SimpleFuncObj(SoSimple ob)
{
    cout << "Before Return" << endl;
    return ob;
}

int main(void)
{
    SoSimple obj(7);

    // SimpleFuncObj(obj).Showdata();

    SimpleFuncObj(obj).AddNum(30).Showdata();

    obj.Showdata();

    return 0;
}