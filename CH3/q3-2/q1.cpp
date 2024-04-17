#include <iostream>
using namespace std;

class Calculator
{
private:
    int plus;
    int minus;
    int multiple;
    int devide;
public:

    void Init()
    {
        plus = 0;
        minus = 0;
        multiple = 0;
        devide = 0;
    }

    float Add(float a, float b)
    {
        plus += 1;
        return a + b;
    }

    float Div(float a, float b)
    {
        if (b == 0)
        {
            cout << "Can't devide by zero" << endl;
            return 0;
        }
        else
        {
            devide += 1;
            return a / b;
        }
    }

    float Min(float a, float b)
    {
        minus += 1;
        return a - b;
    }
    void ShowOpCount()
    {
        cout << "Plus : " << plus << " Minus : " << minus << " Multiple : " << multiple << " Devide : " << devide << endl;
    }
};


int main(void)
{
    Calculator cal;
    cal.Init();
    cout << "3.2 + 2.4 = " << cal.Add(3.2, 2.4) << endl;
    cout << "3.5 / 1.7 = " << cal.Div(3.5, 1.7) << endl;
    cout << "2.2 - 1.5 = " << cal.Min(2.2, 1.5) << endl;
    cout << "4.9 / 1.2 = " << cal.Div(4.9, 1.2) << endl;
    cal.ShowOpCount();
    return 0;
}