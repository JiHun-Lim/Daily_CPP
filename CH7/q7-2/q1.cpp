#include <iostream>
using namespace std;

class Rectangle
{
private:
    int xlen;
    int ylen;

public:
    Rectangle(int x, int y) : xlen(x), ylen(y) {}

    void ShowAreaInfo()
    {
        cout << "x len : " << xlen << " , y len : " << ylen << endl;
        cout << "Area : " << xlen * ylen << endl;
    }

};

class Square : public Rectangle
{
public:
    Square(int m) : Rectangle(m, m) {}
};



int main(void)
{
    Rectangle rec(4,3);
    rec.ShowAreaInfo();

    Square sqr(7);
    sqr.ShowAreaInfo();
    return 0;
}