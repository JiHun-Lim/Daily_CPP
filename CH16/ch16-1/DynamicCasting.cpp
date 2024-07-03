#include <iostream>
using namespace std;

class Car
{
private:
    int fuelGauge;

public:
    Car(int fuel) : fuelGauge(fuel) {}

    void ShowCarState()
    {
        cout << "Fuel Left : " << fuelGauge << endl;
    }  
};

class Truck : public Car
{
private:
    int freightWeight;

public:
    Truck(int fuel, int weight): Car(fuel), freightWeight(weight) {}

    void ShowTruckState()
    {
        ShowCarState();
        cout << "Weight of the Freight : " << freightWeight << endl;
    }
};

int main(void)
{
    // Car * pcar1 = new Truck(80, 200);
    // Truck * ptruck1 = dynamic_cast<Truck *>pcar1;
    // ptruck1->ShowTruckState();

    // Car * pcar2 = new Car(120);
    // Truck * ptruck2 = dynamic_cast<Truck *>pcar2;
    // ptruck2->ShowTruckState();

    Truck * ptruck3 = new Truck(70, 150);
    Car * pcar3 = dynamic_cast<Car *>(ptruck3);
    pcar3->ShowCarState();
    ptruck3->ShowTruckState();

    return 0;
}