#include <iostream>
using namespace std;

class Person
{
public:
    void Sleep() 
    {
        cout << "Sleep" << endl;
    }

};

class Student : public Person
{
public:
    void Study()
    {
        cout << "Study" << endl;
    }

};

class ParttimeStudent : public Student
{
public:
    void Work() 
    {
        cout << "Work" << endl;
    }

};

int main(void)
{
    Person * ptr1 = new Student();
    Person * ptr2 = new ParttimeStudent();
    Student * ptr3 = new ParttimeStudent();

    ptr1->Sleep();
    ptr2->Sleep();
    ptr3->Study();
    ptr3->Sleep();

    delete ptr1, ptr2, ptr3;

    return 0;
}