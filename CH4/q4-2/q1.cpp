#include <iostream>

using namespace std;

class Point
{
private:
    int xpos, ypos;
public:
    void Init(int x, int y)
    {
        xpos = x;
        ypos = y;
    }
    void ShowPointInfo() const
    {
        cout << "center : " << "[" << xpos << ", " << ypos << "]" << endl;
    }
};

class Circle
{
private:
    int rad;
    Point center;
public:
    void Init(int x, int y, int r)
    {
        center.Init(x,y);
        rad = r;
    }
    void ShowCircleInfo() const
    {
        cout << "radius : " << rad << endl;
        center.ShowPointInfo();
    }
};

class Ring
{
private:
    Circle InCircle;
    Circle OutCircle;
public:
    void Init(int inX, int inY, int outX, int outY, int inRad, int outRad)
    {
        InCircle.Init(inX, inY, inRad);
        OutCircle.Init(outX, outY, outRad);
    }

    void ShowRingInfo() const
    {
        cout << "Inner circle info " << endl;
        InCircle.ShowCircleInfo();
        cout << "Outer circle info" << endl;
        OutCircle.ShowCircleInfo();
    }
};


int main(void)
{
    Ring rin;

    rin.Init(0, 0, 2, 2, 4, 9);
    rin.ShowRingInfo();

    return 0;
}