#include <iostream>
using namespace std;

class SinivelCap
{
public:
    void Take() const
    {
        cout << "No more sneezing" << endl;
    }
};

class SneezeCap
{
public:
    void Take() const
    {
        cout << "No more cough" << endl;
    }
};

class Snufflecap
{
public:
    void Take() const
    {
        cout << "No more sinusitis" << endl;
    }
};

class ColdPatient
{
public:
    void TakeSinivelCap(const SinivelCap &cap) const
    {
        cap.Take();
    }
    void TakeSneezecap(const SneezeCap &cap) const
    {
        cap.Take();
    }
    void TakeSnuffleCap(const Snufflecap &cap) const
    {
        cap.Take();
    }
};

int main(void)
{
    SinivelCap scap;
    SneezeCap zcap;
    Snufflecap ncap;

    ColdPatient sufferer;

    sufferer.TakeSinivelCap(scap);
    sufferer.TakeSneezecap(zcap);
    sufferer.TakeSnuffleCap(ncap);

    return 0;
}