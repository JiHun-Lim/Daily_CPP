#include <iostream>
#include <cstring>

using namespace std;

class Person
{
private:
    char * name;

public:
    Person(char * myname)
    {
        name = new char[strlen(myname) +1];
        strcpy(name, myname);
    }

    void WhatYourName() const
    {
        cout << "My name is " << name << endl;
    }

    ~Person()
    {
        delete []name;
    }

};

class UnivStudent : public Person
{
private:
    char * major;

public:
    UnivStudent(char * myname, char * mymajor) : Person(myname)
    {
        major = new char[strlen(mymajor) +1];
        strcpy(major, mymajor);
    }

    void WhoAreYou() const
    {
        WhatYourName();
        cout << "My major is " << major << endl;
    }

    ~UnivStudent()
    {
        delete []major;
    }

};

int main(void)
{
    UnivStudent ustd1("Lim", "Mathematics");
    ustd1.WhoAreYou();

    UnivStudent ustd2("Kim", "Computer Science");
    ustd2.WhoAreYou();

    return 0;
}