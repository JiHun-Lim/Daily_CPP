#include <iostream>
using namespace std;

class Temporary
{
private:
    int num;

public:
    Temporary(int number) : num(number) 
    {
        cout << "Created Object " << num << endl;
    }

    ~Temporary()
    {
        cout << "Destroy Object " << num << endl;
    }

    void ShowTempInfo()
    {
        cout << "Object Num : " << num << endl;
    }
};

int main(void)
{
    Temporary(100);

    Temporary(200).ShowTempInfo();

    const Temporary &ref = Temporary(300);

    cout << &ref << endl;

    return 0;
}