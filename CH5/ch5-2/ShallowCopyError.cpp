#include <iostream>
#include <cstring>

using namespace std;

class Person
{
private:
    int age;
    char * name;

public:
    Person(char * myname, int myage)
    {
        int len = strlen(myname) + 1;
        name = new char[len];
        strcpy(name, myname);
        age = myage;
    }

    // Person(const Person& copy) : age(copy.age)
    // {
    //     name = new char[strlen(copy.name) + 1];
    //     strcpy(name, copy.name);
    // }

    void ShowPersonInfo() const
    {
        cout << "Name : " << name << endl;
        cout << "Age : " << age << endl;
    }

    ~Person()
    {
        // delete []name;
        cout << "Called destructor!" << endl;
    }

};


int main(void)
{
    Person man1("Jihun Lim", 28);

    Person man2(man1);

    man1.ShowPersonInfo();

    man2.ShowPersonInfo();

    return 0;
}