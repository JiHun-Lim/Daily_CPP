#include <iostream>
using namespace std;

typedef struct __Point
{
    int xpos;
    int ypos;
} Point;

Point& PntAdder(const Point &p1, const Point &p2)
{
    Point * temp_p = new Point;
    temp_p -> xpos = p1.xpos + p2.xpos;
    temp_p -> ypos = p1.ypos + p2.ypos;
    return *temp_p;
}

int main(void)
{
    Point *p1_p = new Point;
    p1_p -> xpos = 3;
    p1_p -> ypos = 7;

    Point *p2_p = new Point;
    p2_p -> xpos = 4;
    p2_p -> ypos = 2;

    Point &added = PntAdder(*p1_p, *p2_p);
    cout << added.xpos << added.ypos << endl;

    delete p1_p;
    delete p2_p;
    delete &added;

    return 0;
}