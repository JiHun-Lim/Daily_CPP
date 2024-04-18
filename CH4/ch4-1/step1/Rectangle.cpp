#include <iostream>
#include "Rectangle.h"

using namespace std;

bool Rectangle::InitMembers(const Point &ul, const Point &lr)
{
    if(ul.GETX() > lr.GETX() || ul.GETY() > lr.GETY())
    {
        cout << "Wrong coordinate information" << endl;
        return false;
    }

    upleft = ul;
    lowright = lr;

    return true;
}

void Rectangle::ShowRecInfo() const
{
    cout << "Upper Left : [" << upleft.GETX() << " , " << upleft.GETY() << "]" << endl;
    cout << "Lower Right : [" << lowright.GETX() << " , " << lowright.GETY() << "]" << endl;
}