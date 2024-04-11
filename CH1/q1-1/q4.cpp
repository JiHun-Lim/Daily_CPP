#include <iostream>

int main(void)
{
    int num = 0;
    while(true)
    {
        std::cout << "Sales in the unit of dollar : ";
        std::cin >> num;
        if (num == -1)
        break;        
        std::cout << "Sales of month : " << 50 + num * 0.12 << std::endl;
    }
    std::cout << "Program exit";

    return 0;
}