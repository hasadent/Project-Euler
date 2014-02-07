/****
 * Problem 41 - Pandigital prime
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

const int PRIME_MAX = 10001;
const int PRIME_MAX_SQRT = 101;
int prime[PRIME_MAX] = {0};

void init_prime()
{
    prime[0] = prime[1] = 1;
    for (int i = 2; i < PRIME_MAX_SQRT; i++)
        if (prime[i] == 0)
            for (int j = i*2; j < PRIME_MAX; j += i)
                prime[j] = 1;
}

bool is_prime(int n)
{
    if (n <= PRIME_MAX)
        return prime[n] == 0;

    if (n % 2 == 0) return false;

    int s = sqrt(n);
    for (int i = 3; i < s; i+=2)
        if (prime[i] == 0 && n % i == 0)
            return false;

    return true;
}

bool is_pandigital(int a, int n)
{
    int x[10] = {0};
    for (int i = a; i != 0; x[i%10]+=1, i/=10);
    for (int i = 1; i <= n; i++)
        if (x[i] != 1) return false;
    return true;
}

int main()
{
    init_prime();

    const int info[2][3] = {
        {7, 7654321, 1234567},
        {4,    4321,    1234},
    };
    bool found = false;
    int v = -1;

    for (int i = 0; i < 2 && !found; i--)
    {
        int len = info[i][0];
        int ub  = info[i][1];
        int lb  = info[i][2];

        for (int i = ub; i >= lb; i-=2)
            if (is_prime(i) && is_pandigital(i, len))
            {
                found = true;
                v = i;
                break;
            }
    }

    cout << "The largest pandigital prime is " << v << "." << endl;

    return 0;
}
