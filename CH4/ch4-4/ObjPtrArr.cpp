#include <iostream>
#include <cstring>

using namespace std;

class Person
{
private:
    char * name;
    int age;

public:
    Person (char * myname, int myage)
    {
        int len = strlen(myname) + 1;
        name = new char[len];
        strcpy(name, myname);
        age = myage;
    }

    // Person()
    // {
    //     name = NULL;
    //     age = 0;
    //     cout << "called Person()" << endl;
    // }

    void SetPersonInfo(char * myname, int myage)
    {
        name = myname;
        age = myage;
    }

    void ShowPersonInfo()
    {
        cout << "Name : " << name << " , Age : " << age << endl;
    }

    // ~Person()
    // {
    //     delete []name;
    //     cout << "Called destructor!" << endl;
    // }

};

int main(void)
{
    Person * parr[3];
    char namestr[100];
    
    int age;

    for (int i=0; i<3; i++)
    {
        cout << "Name : ";
        cin >> namestr;
        cout << "Age : ";
        cin >> age;

        parr[i] = new Person(namestr, age);
    }
    for (int i = 0; i<3; i++)
    {
        parr[i] -> ShowPersonInfo();
    }
    
    return 0;

}