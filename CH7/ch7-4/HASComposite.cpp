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

class Police
{
private:
    int handcuffs;
    Gun * pistol;

public:
    Police(int bnum, int hcuff) : handcuffs(hcuff) 
    {
        if(bnum > 0)
        {
            pistol = new Gun(bnum);
        }
        else
        {
            pistol = NULL;
        }
    }

    void PutHandcuff()
    {
        cout << "Snap!" << endl;
        handcuffs -= 1;
    }

    void Shot()
    {
        if (pistol == NULL)
            cout << "Missed!" << endl;
        else
            pistol->shot();
    }

};

int main(void)
{
    Police officer(5, 3);

    officer.Shot();
    officer.PutHandcuff();

    Police other_officer(0,4);

    other_officer.Shot();
    other_officer.PutHandcuff();

    return 0;
}