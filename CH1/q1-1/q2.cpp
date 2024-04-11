#include <iostream>

int main(void)
{
    char name[100];
    char phone_num[100];

    std::cout << "What is your name?: ";
    std::cin >> name;

    std::cout << "What is your phone number?: ";
    std::cin >> phone_num;

    std::cout << "My name is " << name << " and my phone number is " << phone_num << ".";
    return 0;
}