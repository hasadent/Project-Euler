/****
 * Problem 7 - 10001st prime
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int PRIME_MAX = 6553600;
const int PRIME_MAX_SQRT = 2560;
int prime[PRIME_MAX] = {0};

int main()
{
    prime[0] = prime[1] = 1;
    for (int i = 2; i < PRIME_MAX_SQRT; i++)
      if (prime[i] == 0)
         for (int j = i*2; j < PRIME_MAX; j += i)
           prime[j] = 1;

    const int T = 10001;
    int x = 0, y = -1;
    for (int i = 2; i < PRIME_MAX; i++)
        if (prime[i] == 0)
        {
            x++;
            if (x == T)
            {
                y = i;
                break;
            }
        }

    cout << y << endl;



    return 0;
}
