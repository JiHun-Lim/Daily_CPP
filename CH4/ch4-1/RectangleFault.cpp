#include <iostream>
using namespace std;

class Point
{
public:
    int x;
    int y;
};

class Rectangle
{
public:
    Point upleft;
    Point lowright;
    void ShowRecInfo()
    {
        cout << "Upper Left : [" << upleft.x << " , " << upleft.y << "]" << endl;
        cout << "Lower Right : [" << lowright.x << " , " << lowright.y << "]" << endl;
    }
};

int main(void)
{
    Point pos1 = {-2,4};
    Point pos2 = {5,9};

    Rectangle rec = {pos2, pos1};
    rec.ShowRecInfo();
    return 0;
}