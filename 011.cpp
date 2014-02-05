/****
 * Problem 11 - Summation of primes
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int g[20][20];

int main()
{
    freopen("011.in", "r", stdin);

    for (int i = 0; i < 20; i++)
        for (int j = 0; j < 20; j++)
            cin >> g[i][j];

    int max_p = 0, p;
    for (int i = 0; i < 20; i++)
        for (int j = 0; j < 20; j++)
        {
            // case /
            if (i >= 3 && j < 17)
            {
                p = g[i][j] * g[i-1][j+1] * g[i-2][j+2] * g[i-3][j+3];
                if (p > max_p) max_p = p;
            }

            // case -
            if (j < 17)
            {
                p = g[i][j] * g[i][j+1] * g[i][j+2] * g[i][j+3];
                if (p > max_p) max_p = p;
            }

            // case \
            if (i < 17 && j < 17)
            {
                p = g[i][j] * g[i+1][j+1] * g[i+2][j+2] * g[i+3][j+3];
                if (p > max_p) max_p = p;
            }
            // case |
            if (i < 17)
            {
                p = g[i][j] * g[i+1][j] * g[i+2][j] * g[i+3][j];
                if (p > max_p) max_p = p;
            }
        }

    cout << max_p << endl;
    return 0;
}
