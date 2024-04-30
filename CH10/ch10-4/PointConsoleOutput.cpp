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

    friend ostream& operator<<(ostream&, const Point&);

};

ostream& operator<<(ostream&os, const Point&pos)
{
    os << "Point X : " << pos.xpos << ",  Point Y : " << pos.ypos << endl;

    return os;
}

int main(void)
{
    Point pos1(1,3);
    cout << pos1;
    pos1.ShowPosition();
    Point pos2(101,303);
    cout << pos2;
    pos2.ShowPosition();


    return 0;

}