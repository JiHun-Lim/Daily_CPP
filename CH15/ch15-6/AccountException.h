#ifndef __ACCOUNT_EXCEPTION_H__
#define __ACCOUNT_EXCEPTION_H__

class MinusException
{
private:
    int exval;

public:
    MinusException(int val) : exval(val) {}

    void ShowExceptionInfo(void) const
    {
        cout << "The money " << exval << " is not acceptable" << endl;
    }

};

class InsuffException
{
private:
    int balance;
    int reqval;

public:
    InsuffException(int val, int req) : reqval(req), balance(val) {}

    void ShowExceptionInfo() const
    {
        cout << "The money " << reqval - balance << " is needed" << endl;
    }

};

#endif