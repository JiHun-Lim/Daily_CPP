#include <iostream>

using namespace std;

int simObjCnt = 0;
int cmxObjCnt = 0;

class SoSimple
{
public:
    SoSimple()
    {
        simObjCnt++;
        cout << "Number " << simObjCnt << " Sosimple" <<  endl;
    }
};

class SoComplex
{
public:
    SoComplex()
    {
        cmxObjCnt++;
        cout << "Number " << cmxObjCnt << " Socomplex" << endl;
    }

    SoComplex(SoComplex &copy)
    {
        cmxObjCnt++;
        cout << "Number " << cmxObjCnt << " Socomplex" << endl;
    }
};

int main(void)
{
    SoSimple sim1;
    SoSimple sim2;

    SoComplex com1;
    SoComplex com2 = com1;

    SoComplex();

    return 0;
}