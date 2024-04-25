#include <iostream>
#include <cstring>

using namespace std;

class Computer
{
private:
    char owner[50];

public:
    Computer(char * name)
    {
        strcpy(owner, name);
    }

    void Calculate()
    {
        cout << "Calculating..." << endl;
    }

};

class NoteBookComp : public Computer
{
private:
    int Battery;

public:
    NoteBookComp(char * name, int initChag) : Computer(name), Battery(initChag) {}

    void Charging()
    {
        Battery += 5;
    }

    void UseBattery()
    {
        Battery -= 1;
    }

    int GetBatteryInfo()
    {
        return Battery;
    }

    void MovingCal()
    {
        if(GetBatteryInfo() < 1)
        {
            cout << "Need Charging" << endl;
            return;
        }
        cout << "Moving.." << endl;
        Calculate();
        UseBattery();
    }
};

class TabletNoteBook : public NoteBookComp
{
private:
    char regstPenModel[50];

public:
    TabletNoteBook(char * name, int initChag, char * pen) : NoteBookComp(name, initChag)
    {
        strcpy(regstPenModel, pen);
    }

    void Write(char * penInfo)
    {
        if(GetBatteryInfo() < 1)
        {
            cout << "Need Charge" << endl;
            return;
        }

        if(strcmp(regstPenModel, penInfo) != 0)
        {
            cout << "Not registered pen" << endl;
            return;
        }

        cout << "Processing written objects" << endl;
        UseBattery();
    }

};

int main(void)
{
    NoteBookComp nc("Jihun", 5);
    TabletNoteBook tn("Jihun Lim", 5, "ISE-241-242");

    nc.MovingCal();
    tn.Write("ISE-241-242");
    tn.Write("ISE-200-284");

    return 0;

}