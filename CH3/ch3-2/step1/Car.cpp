#include <iostream>
#include <cstring>
#include "Car.h"

using namespace std;


void Car::InitMembers(char * ID, int fuel)
{
    strcpy(gamerID, ID);
    fuelGauge = fuel;
    curSpeed = 0;
}

void Car::ShowCarState()
{
    cout << "ID : " << gamerID << endl;
    cout << "Fuel : " << fuelGauge << endl;
    cout << "Speed : " << curSpeed << endl;
}

void Car::Accel()
{
    if (fuelGauge <=0)
        return;
    else
        fuelGauge -= CAR_CONST::FUEL_STEP;

    if(curSpeed + CAR_CONST::ACC_STEP >= CAR_CONST::MAX_SPD)
    {
        curSpeed = CAR_CONST::MAX_SPD;
        return;
    }
    else
        curSpeed += CAR_CONST::ACC_STEP;
}

void Car::Break()
{
    if (curSpeed < CAR_CONST::BRK_STEP)
    {
        curSpeed = 0;
        return;
    }
    else
        curSpeed -= CAR_CONST::BRK_STEP;
}
