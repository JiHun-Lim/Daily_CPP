#include <iostream>

using namespace std;

class Point
{
private:
    int xpos, ypos;

public:
    Point(int x=0, int y=0) : xpos(x), ypos(y) { }

    void ShowPosition() const
    {
        cout << '[' << xpos << ", " << ypos << ']' << endl;
    }

};


template <typename T>

void SwapData(T& num1, T& num2)
{
    T temp;
    temp = num1;
    num1 = num2;
    num2 = temp;
}


int main(void)
{
    Point p1(2,3);
    Point p2(4,5);

    SwapData(p1, p2) ;

    p1.ShowPosition();
    p2.ShowPosition();
    return 0;
}