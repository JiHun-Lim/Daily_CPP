#include <iostream>
using namespace std;

class Printer
{
private:
    const char * message;
public:
    void SetString(const char * Input)
    {
        message = Input;
    }

    void ShowString()
    {
        cout << message << endl;
    }

};

int main(void)
{
    Printer pnt;
    pnt.SetString("Hello world!");
    pnt.ShowString();

    pnt.SetString("I love C++");
    pnt.ShowString();
    
    return 0;
}