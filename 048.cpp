/****
 * Problem 48 - Self powers
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const long long int m = 10000000000;
int main()
{
    long long int r = 0;
    for (int i = 1; i < 1000; i++)
    {
        long long int p = i;
        for (int j = 1; j < i; j++)
        {
            p *= i;
            if (p > m) p %= m;
        }

        r += p;
        if (r > m) r %= m;
    }

    cout << "The last ten digits is " << r << "." << endl;

    return 0;
}
