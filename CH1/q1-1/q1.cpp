#include <iostream>

int main(void)
{
    int var1, var2, var3, var4, var5;
    std::cout << "First number input : ";
    std::cin >> var1;
    std::cout << "Second number input : ";
    std::cin >> var2;
    std::cout << "Third number input : ";
    std::cin >> var3;
    std::cout << "Forth number input : ";
    std::cin >> var4;
    std::cout << "Fifth number input : ";
    std::cin >> var5;

    int sums = var1 + var2 + var3 + var4 + var5;

    std::cout << "Sum result is : " << sums << std::endl;

    return 0;
}