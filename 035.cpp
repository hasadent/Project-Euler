/****
 * Problem 35 - Circular primes
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int PRIME_MAX = 1000001;
const int PRIME_MAX_SQRT = 1001;
int prime[PRIME_MAX] = {0};

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

    vector <int> v;
    int c = 1; // 2
    for (int i = 3; i < PRIME_MAX; i+=2)
        if (prime[i] == 0)
        {
            int scale = 1;
            for (int s = i; s >= 10; s /= 10, scale *= 10);

            bool is_circular = true;
            int  pn = 1; // i
            int  n  = i;
            for (;;)
            {
                n = n / 10 + n % 10 * scale;

                if (n == i) break;

                if (prime[n] != 0)
                    is_circular = false;

                v.push_back(n);
                pn ++;
            }
            ;

            if (is_circular)
            {
                c += pn;
                cout << setw(6) << i << ": " << pn << endl;
            }

            for(int x : v)
                prime[x] = 1;
            v.clear();
        }

    cout << "--------" << endl;
    cout << "There are " << c << " circular primes." << endl;

    return 0;
}
