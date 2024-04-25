#include <iostream>
#include <cstring>

using namespace std;

class Gun
{
private:
    int bullet;

public:
    Gun (int bnum): bullet(bnum) {}

    void shot()
    {
        cout << "Bang!" << endl;
        bullet -= 1;
    }

};

class Police : public Gun
{
private:
    int handcuffs;

public:
    Police(int bnum, int hcuff) : Gun(bnum), handcuffs(hcuff) {}

    void PutHandcuff()
    {
        cout << "Snap!" << endl;
        handcuffs -= 1;
    }
};

int main(void)
{
    Police officer(5, 3);

    officer.shot();
    officer.PutHandcuff();

    return 0;
}