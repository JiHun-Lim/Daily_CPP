#include <iostream>
#include <cstring>

using namespace std;

namespace COMP_POS
{
    enum {CLERK, SENIOR, ASSIST, MANAGER};

    void ShowPositionINfo(int pos)
    {
        switch(pos)
        {
        case CLERK:
            cout << "CLERK" << endl;
            break;
        case SENIOR:
            cout << "SENIOR" << endl;
            break;
        case ASSIST:
            cout << "ASSIST" << endl;
            break;
        case MANAGER:
            cout << "MANAGER" << endl;
        }
    }
}

class NameCard
{
private:
    char * name;
    char * company;
    char * phone;
    int position;
public:
    NameCard(char * _name, char * _company, char * _phone, int pos) : position(pos)
    {
        name = new char[strlen(_name) + 1];
        company = new char[strlen(_company) + 1];
        phone = new char[strlen(_phone) + 1];

        strcpy(name, _name);
        strcpy(company, _company);
        strcpy(phone, _phone);
    }

    NameCard(const NameCard& copy) : position(copy.position)
    {
        name = new char[strlen(copy.name) + 1];
        strcpy(name, copy.name);
        company = new char[strlen(copy.company) + 1];
        strcpy(company, copy.company);
        phone = new char[strlen(copy.phone) + 1];
        strcpy(phone, copy.phone);
    }

    void ShowNameCardInfo()
    {
        cout << "Name : " << name << endl;
        cout << "Company : " << company << endl;
        cout << "Phone : " << phone << endl;
        cout << "Position : ";
        COMP_POS::ShowPositionINfo(position);
        cout << endl;
    }
    ~NameCard()
    {
        delete []name;
        delete []company;
        delete []phone;
    }

};

int main(void)
{
    NameCard manClerk("Lee", "ABCEng", "010-1111-4587", COMP_POS::CLERK);

    NameCard copy1 = manClerk;

    NameCard manSENIOR("Kim", "KoreUniv", "010-8890-0925", COMP_POS::SENIOR);

    NameCard copy2 = manSENIOR;

    copy1.ShowNameCardInfo();
    copy2.ShowNameCardInfo();

    return 0;
}










