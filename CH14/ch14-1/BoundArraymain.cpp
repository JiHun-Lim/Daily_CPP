#include <iostream>
#include "ArrayTemplate.h"
#include "PointTemplate.h"

using namespace std;

int main(void)
{
    BoundCheckArray<Point<int>> oarr1(3);
    oarr1[0] = Point<int> (3, 4);
    oarr1[1] = Point<int> (4, 5);
    oarr1[2] = Point<int> (8, 2);

    for(int i=0;i<oarr1.GetArrLen(); i++)
    {
        oarr1[i].ShowPosition();
    }

    BoundCheckArray<Point<double>> oarr2(3);
    oarr2[0] = Point<double> (3.14, 1.59);
    oarr2[1] = Point<double> (26.53, 5.89);
    oarr2[2] = Point<double> (7.93, 1.41);

    for(int i=0;i<oarr2.GetArrLen(); i++)
    {
        oarr2[i].ShowPosition();
    }

    typedef Point<int>* POINT_PTR;
    BoundCheckArray<POINT_PTR> oparr(3);
    oparr[0] = new Point <int> (11, 12);
    oparr[1] = new Point <int> (24, 35);
    oparr[2] = new Point <int> (38, 42);

    for(int i=0;i<oparr.GetArrLen(); i++)
    {
        oparr[i]->ShowPosition();
    }


    return 0;
}