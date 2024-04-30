#include <iostream>

using namespace std;

class Point
{
private:
    int xpos, ypos;

public:
    Point(int x=0, int y=0) : xpos(x), ypos(y) {}

    void ShowPosition() const
    {
        cout << "xpos : " << xpos << ", ypos : " << ypos << endl;
    }

    Point operator*(int times)
    {
        Point pos(xpos * times, ypos * times);
        return pos;
    }

    friend Point operator*(int times, Point& ref);

};

Point operator*(int times, Point& ref)
{
    return ref*times;
}

int main(void)
{
    Point pos1(3, 4);
    Point pos2;
    pos2 = 2 * pos1 * 3;


    pos2.ShowPosition();


    return 0;

}