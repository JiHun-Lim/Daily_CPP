#include <iostream>
#include "Rectangle.h"

using namespace std;

Rectangle::Rectangle(const int &x1, const int &y1, const int &x2, const int &y2): upleft(x1, y1), lowright(x2, y2)
{
    //
}

void Rectangle::ShowRecInfo() const
{
    cout << "Upper Left : [" << upleft.GETX() << " , " << upleft.GETY() << "]" << endl;
    cout << "Lower Right : [" << lowright.GETX() << " , " << lowright.GETY() << "]" << endl;
}