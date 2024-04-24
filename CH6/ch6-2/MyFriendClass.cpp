#include <iostream>
#include <cstring>

using namespace std;

class Girl;

class Boy
{
private:
    int height;
    friend class Girl;

public:
    Boy(int len) : height(len) {}
    void ShowYourFriendInfo(Girl &frn);
};

class Girl
{
private:
    char phNum[20];

public:
    Girl(char * num)
    {
        strcpy(phNum, num);
    }
    void ShowYourFriendInfo(Boy &frn);
    friend class Boy;
};

void Boy::ShowYourFriendInfo(Girl &frn)
{
    cout << "Her phone number is " << frn.phNum << endl;
}

void Girl::ShowYourFriendInfo(Boy &frn)
{
    cout << "His height is " << frn.height << endl;
}

int main(void)
{
    Boy Jihun(175);
    Girl Chu("010-4588-6721");

    Jihun.ShowYourFriendInfo(Chu);
    Chu.ShowYourFriendInfo(Jihun);

    return 0;
}