#include <iostream>
#include <cstring>

using namespace std;

class Car
{
private:
    int gasolineGauge;

public:

    Car(int gas) : gasolineGauge(gas) {}

    int GetGasGauge()
    {
        return gasolineGauge;
    }

};

class HybridCar : public Car
{
private:
    int electricGauge;

public:
    HybridCar(int gas, int electric) : Car(gas), electricGauge(electric) {}

    int GetElecGauge()
    {
        return electricGauge;
    }

};

class HybridWaterCar : public HybridCar
{
private:
    int waterGauge;

public:
    HybridWaterCar(int gas, int electric, int water) : HybridCar(gas, electric), waterGauge(water) {}

    void ShowCurrentGauge()
    {
        cout << "Gasoline left : " << GetGasGauge() << endl;
        cout << "Battery left : " << GetElecGauge() << endl;
        cout << "Water left : " << waterGauge << endl;
    }
};

int main(void)
{
    HybridWaterCar Teslar(10,20,30);

    Teslar.ShowCurrentGauge();

    return 0;
}