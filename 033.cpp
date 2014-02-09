/****
 * Problem 33 - Digit canceling fractions
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;


int gcd(int a, int b)
{
    while (b != 0)
    {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main()
{
    int g_d = 1;
    int g_n = 1;

    for (int i = 9; i > 2; i--)
        for (int d = i-1; d > 1; d--)
            for (int n = i-1; n > 0; n--)
                if (9 * n * (d - i) == i * (n - d))
                {
                    g_n *= n;
                    g_d *= d;
                }

    cout << "                 " << g_n << endl;
    cout << "The product is ----- = " << (g_d / gcd(g_n, g_d))<< endl;
    cout << "                " << g_d << endl;

    return 0;
}
