#include <iostream>

using namespace std;

class SoSimple
{
public:
    static int simObjCnt;
    SoSimple()
    {
        simObjCnt++;
    }
};

int SoSimple::simObjCnt = 0;

int main(void)
{
    cout << SoSimple::simObjCnt << endl;

    SoSimple sim1;
    cout << SoSimple::simObjCnt << endl;

    SoSimple sim2;

    cout << SoSimple::simObjCnt << endl;

    SoSimple sim3;

    cout << SoSimple::simObjCnt << endl;

    cout << sim1.simObjCnt << endl;
    cout << sim2.simObjCnt << endl;
    cout << sim3.simObjCnt << endl;
    cout << SoSimple::simObjCnt <<  endl;

    return 0;
}