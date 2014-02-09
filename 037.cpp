/****
 * Problem 37 - Truncatable primes
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

const int PRIME_MAX = 1000000;
const int PRIME_MAX_SQRT = 4001;
char prime[PRIME_MAX] = {0};

void init_prime()
{
    prime[0] = prime[1] = 1;
    for (int i = 2; i < PRIME_MAX_SQRT; i++)
        if (prime[i] == 0)
            for (int j = i*2; j < PRIME_MAX; j += i)
                prime[j] = 1;
}

int main()
{
    init_prime();

    int sum = 0;

    for (int i = 11; i < PRIME_MAX; i += 2)
    if (prime[i] == 0)
    {
        // right to left
        int n;
        for (n = i / 10; n != 0 && prime[n] == 0; n /= 10);
        if (n != 0) continue;

        // left to right
        int k = i % 10;
        for (int l = 100; k != i && prime[k] == 0; k = i % l, l *= 10);
        if (k != i) continue;

        cout << i << endl;
        sum += i;
    }

    cout << "The sum is " << sum << "." << endl;

    return 0;
}
