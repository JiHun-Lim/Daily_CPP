#include <iostream>

namespace BestComImpl
{
    void SimpleFunc(void)
    {
        std::cout << "Defined by BestCom" << std::endl;
    }
}

namespace ProgComImpl
{
    void SimpleFunc(void)
    {
        std::cout << "Defined by ProgCom" << std::endl;
    }
}

int main(void)
{
    BestComImpl::SimpleFunc();
    ProgComImpl::SimpleFunc();
    return 0;
}