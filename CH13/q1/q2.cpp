#include <iostream>

using namespace std;

template <typename T>

int SumArray(T arr[], int len)
{
    int sum = 0;
    for(int i=0; i<len; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int main(void)
{
    int arr1[] = {10, 20, 30};

    cout << SumArray(arr1, 3) << endl;

    return 0;
}