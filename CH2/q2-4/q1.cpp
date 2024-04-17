#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
    char str[] = "Hello World!";
    char str2[100];
    cout << strlen(str) << endl;
    cout << strcat(str, str) << endl;
    cout << strcpy(str2, str) << endl;
    cout << strcmp(str, str2) << endl;
    return 0;
}