/****
 * Problem 27 - Quadratic primes
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int PRIME_MAX = 10000;
const int PRIME_MAX_SQRT = 101;
int prime[PRIME_MAX] = {0};

inline int next_prime(int n)
{
    int next = -1;
    for (int i = n+1; i < PRIME_MAX; i++)
        if (prime[i] == 0)
        {
            next = i;
            break;
        }
    return next;
}

int main()
{
    prime[0] = prime[1] = 1;
    for (int i = 2; i < PRIME_MAX_SQRT; i++)
      if (prime[i] == 0)
         for (int j = i*2; j < PRIME_MAX; j += i)
           prime[j] = 1;

    int b = 1;
    int max_a, max_b, max_c = 0;;
    while ((b = next_prime(b)) <= 1000)
    {
        for (int a = -b; a <= 1000; a++)
        {
            if (prime[a + b + 1] == 0)
            {
                int c = 2;
                while (prime[c*c+a*c+b] == 0) c++;
                if (c > max_c)
                {
                    max_a = a;
                    max_b = b;
                    max_c = c;
                }
            }
        }
    }

    cout << "The maximum number of primes"
        " for consecutive values of n is " << max_c << "," << endl;
    cout << " where (a, b) = (" << max_a << ", " << max_b << ")." << endl;
    cout << "The product of a, b is " << max_a * max_b << "." << endl;

    return 0;
}
