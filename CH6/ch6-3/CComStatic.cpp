#include <iostream>

using namespace std;

void Counter()
{
    static int cnt;
    cnt++;
    cout << "Current cnt : " << cnt << endl;
}

int main(void)
{
    for (int i; i<10; i++)    
        Counter();
    return 0;
}