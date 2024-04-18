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

class CONTAC600
{
private:
    SinivelCap sin;
    SneezeCap sne;
    Snufflecap snu;

public:
    void Take() const
    {
        sin.Take();
        sne.Take();
        snu.Take();
    }
};

class ColdPatient
{
public:
    void TakeCONTAC600(const CONTAC600 &cap) const 
    {
        cap.Take();
    }
};

int main(void)
{
    CONTAC600 cap;

    ColdPatient sufferer;

    sufferer.TakeCONTAC600(cap);

    return 0;
}