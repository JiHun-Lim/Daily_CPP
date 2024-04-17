#include <iostream>
#include <ctime>
#include <cstdlib>
#include <random>

using namespace std;

// int main(void)
// {
//     srand(time(NULL));
//     for(int i = 0; i < 5; i++)
//         printf("Random number #%d: %d \n", i, rand() % 100);
//     return 0;
// }

int main(void) 
{
  random_device rd;

  mt19937 gen(rd());
//   minstd_rand gen(rd());
  
  uniform_int_distribution<int> dis(0, 99);

  for (int i = 0; i < 5; i++) {
    cout << "Random number : " << dis(gen) << endl;
  }
}