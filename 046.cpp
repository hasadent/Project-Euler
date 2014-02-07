/****
 * Problem 46 - Goldbach's other conjecture
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
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

    int i;
    for (i = 9; i < PRIME_MAX; i+=2)
        if (prime[i] != 0)
        {
            bool found = false;

            for (int j = i - 2; j >= 2; j-=2)
                if (prime[j] == 0)
                {
                    int n = i - j;
                    int s = sqrt(n/2);
                    if (n == s * s * 2)
                    {
                        found = true;
                        break;
                    }
                }

            if (!found)
                break;
        }

    cout << "The composite is " << i << "." << endl;

    return 0;
}
