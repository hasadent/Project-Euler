/****
 * Problem 51 - Prime digit replacements
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

const int PRIME_MAX = 1000000;
const int PRIME_MAX_SQRT = 1001;
char prime[PRIME_MAX] = {0};

void init_prime()
{
    prime[0] = prime[1] = 1;
    for (int i = 2; i < PRIME_MAX_SQRT; i++)
        if (prime[i] == 0)
            for (int j = i*2; j < PRIME_MAX; j += i)
                prime[j] = 1;
}

struct info_t{
    char fmt[12];
    int  len;
    int  rn;
};

int main()
{
    init_prime();

    info_t x[14] =
    {
        {"%d%d000%d", 5,  01110},
        {"%d0%d00%d", 5,  10110},
        {"%d00%d0%d", 5,  11010},
        {"%d000%d%d", 5,  11100},
        {"%d%d000%d", 6, 001110},
        {"%d0%d00%d", 6, 010110},
        {"%d00%d0%d", 6, 011010},
        {"%d000%d%d", 6, 011100},
        {"0%d%d00%d", 6, 100110},
        {"0%d0%d0%d", 6, 101010},
        {"0%d00%d%d", 6, 101100},
        {"00%d%d0%d", 6, 110010},
        {"00%d0%d%d", 6, 110100},
        {"000%d%d%d", 6, 111000},
    };

    int result = 1000000;

    char num_str[12];
    for (info_t info : x)
    {
        int ub = 1000;
        int z  = 0;

        if (info.len == 5)
        {
            ub = 100;
            z  = 1;
        }

        for (int i = 1; i < ub; i += 2)
            if (i % 5 != 0)
            {
                sprintf(num_str, info.fmt, i / 100, (i / 10) % 10, i % 10);
                int n = atoi(num_str);
                int f = -1; /* the first prime in the family */

                int fsize = 0;
                if (num_str[z] != '0' && prime[n] == 0)
                    fsize ++, f = n;

                for (int i = 1; i <= 9; i++)
                {
                    n += info.rn;

                    if (prime[n] == 0)
                    {
                        fsize ++ ;
                        if (f == -1) f = n;
                    }
                }

                if (fsize == 8)
                {
                    if (f < result)
                        result = f;
                    break;
                }
            }
    }

    cout << "The smallest prime in an eight prime value family is " << result << "." << endl;

    return 0;
}
