/****
 * Problem 10 - Summation of primes
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int PRIME_MAX = 2000001;
const int PRIME_MAX_SQRT = 1415;
int prime[PRIME_MAX] = {0};

int main()
{
    prime[0] = prime[1] = 1;
    for (int i = 2; i < PRIME_MAX_SQRT; i++)
      if (prime[i] == 0)
         for (int j = i*2; j < PRIME_MAX; j += i)
           prime[j] = 1;

    unsigned long long sum = 0;
    for (int i = 2; i < PRIME_MAX; i++)
        if (prime[i] == 0)
            sum += i;

    cout << sum << endl;
    return 0;
}
