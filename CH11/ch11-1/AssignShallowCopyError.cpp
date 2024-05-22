#include <iostream>
#include <cstring>

using namespace std;

class Person
{
private:
    char * name;
    int age;

public:
    Person(char * myname, int myage)
    {
        int len = strlen(myname) + 1;
        name =new char[len];
        strcpy(name, myname);
        age = myage;

    }

    void ShowPersonInfo() const
    {
        cout << "Name : " << name << ", Age : " << age << endl;
    }

    ~Person()
    {
        delete []name;
        cout << "Called destructor" << endl;
    }

};

int main(void)
{
    Person man1("Jihun Lim", 28);
    Person man2("Js Kim", 61);
    man2 = man1;
    man1.ShowPersonInfo();
    man2.ShowPersonInfo();

    return 0;
}