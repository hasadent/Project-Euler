/****
 * Problem 34 - Digit factorials
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

const int f[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

int main()
{
    int g_sum = 0;
    /* upper bound: https://en.wikipedia.org/wiki/Factorion */
    for (int i = 10; i < 1854721; i++)
    {
        int n = i;
        int sum = 0;
        while (n != 0) { sum += f[n % 10]; n /= 10; }

        if (sum == i)
        {
            cout << i << endl;
            g_sum += sum;
        }
    }

    cout << "The sum is " << g_sum << "." << endl;
    return 0;
}
