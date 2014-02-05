/****
 * Problem 12 - Highly divisible triangular number
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

const int PRIME_MAX = 10000;
const int PRIME_MAX_SQRT = 101;
int prime[PRIME_MAX] = {0};

int main()
{
    prime[0] = prime[1] = 1;
    for (int i = 2; i < PRIME_MAX_SQRT; i++)
      if (prime[i] == 0)
         for (int j = i*2; j < PRIME_MAX; j += i)
           prime[j] = 1;

    int fn = 0, tn, nn;
    for (tn = 28, nn = 8; ; tn += nn, nn++)
    {
        int n = tn; /* num */
        fn = 1;     /* factor num */
        for (int i = 2; i <= n; i++)
        {
            if (prime[i] == 0)
            {
                int pn = 1; /* power of i */
                for (;n % i == 0; n /= i, pn++);
                fn *= pn;
            }
        }

        if (n != 1)
            fn *= 2;
        fn -= 1;

        if (fn > 500) break;
    }

    cout << tn << endl;

    return 0;
}
