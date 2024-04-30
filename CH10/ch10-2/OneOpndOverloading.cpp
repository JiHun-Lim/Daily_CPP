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

    Point& operator++()
    {
        xpos +=1;
        ypos +=1;
        return *this;
    }

    friend Point& operator--(Point &ref);
};

Point& operator--(Point &ref)
{
    ref.xpos -= 1;
    ref.ypos -= 1;
    return ref;
}

int main(void)
{
    Point pos1(3, 4);

    pos1.operator++();
    pos1.ShowPosition();

    --pos1;
    pos1.ShowPosition();

    Point pos2 = -pos1;
    Point pos3 = ~pos2;
    pos2.ShowPosition();
    pos3.ShowPosition();

    return 0;

}