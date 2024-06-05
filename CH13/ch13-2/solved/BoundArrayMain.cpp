#include <iostream>
#include "ArrayTemplate.h"
#include "Point.h"
using namespace std;

int main(void)
{
    BoundCheckArray<int> iarr(5);
    for(int i=0; i<5; i++)
    {
        iarr[i] = 11 * (i+1);
    }
    for(int i=0; i<5; i++)
    {
        cout << iarr[i] << endl;
    }

    BoundCheckArray<Point> oarr(3);
    oarr[0] = Point(1,3);
    oarr[1] = Point(2,4);
    oarr[2] = Point(8,6);
    for(int i=0; i<oarr.GetArrLen(); i++)
    {
        cout << oarr[i];
    }

    typedef Point * POINT_PTR;
    BoundCheckArray<POINT_PTR> parr(3);
    parr[0] = new Point(3,4);
    parr[1] = new Point(5,6);
    parr[2] = new Point(3,7);

    for(int i=0; i<parr.GetArrLen(); i++)
    {
        cout << parr[i] << *(parr[i]) << endl;;
    }

    return 0;
}