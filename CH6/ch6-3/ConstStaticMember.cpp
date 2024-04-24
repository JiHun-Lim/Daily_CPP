#include <iostream>

using namespace std;

class CountryArea
{
public:
    const static int Russia = 17707540;
    const static int Canada = 998467;
    const static int China = 957290;
    const static int South_Korea = 9922;
};

int main(void)
{
    cout << "Korea : " << CountryArea::South_Korea << endl;
    cout << "Russia : " << CountryArea::Russia << endl;
    cout << "Canada : " << CountryArea::Canada << endl;
    cout << "China : " << CountryArea::China << endl;
    return 0;
}