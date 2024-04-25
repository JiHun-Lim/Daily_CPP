#include <iostream>
#include <cstring>

using namespace std;

class MyFriendInfo
{
private:
    char * name;
    int age;

public:
    MyFriendInfo(char * myname, int myage) : age(myage)
    {
        name = new char[strlen(myname) +1];
        strcpy(name, myname);
    }

    void ShowMyFriendInfo()
    {
        cout << "Name : " << name << endl;
        cout << "Age : " << age << endl;
    }

    ~MyFriendInfo()
    {
        delete []name;
    }

};

class MyFreindDetailInfo : public MyFriendInfo
{
private:
    char * addr;
    char * phone;

public:

    MyFreindDetailInfo(char * myname, int myage, char * myaddr, char * myphone) : MyFriendInfo(myname, myage)
    {
        addr = new char[strlen(myaddr) + 1];
        strcpy(addr, myaddr);

        phone = new char[strlen(myphone) + 1];
        strcpy(phone, myphone);
    }

    void ShowMyFriendDetailInfo()
    {
        ShowMyFriendInfo();
        cout << "Address : " << addr << endl;
        cout << "Phone : " << phone << endl;
    }

    ~MyFreindDetailInfo()
    {
        delete []addr;
        delete []phone;
    }

};

int main(void)
{
    MyFreindDetailInfo jihun("Jihun Lim", 28, "Seoul, Song-pa Gu, Ogeum Dong", "010-4584-1726");

    jihun.ShowMyFriendDetailInfo();

    return 0;

}