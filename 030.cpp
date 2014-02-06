/****
 * Problem 30 - Digit fifth powers
 */
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

inline int pow(int x, int y)
{
    int p = x; y--;
    while (y-- > 0) p *= x;
    return p;
}

int main()
{
    int sum = 0;

    for (int i = 2; i <= 355000; i++)
    {
        int n = i;
        int s = 0;
        while (n != 0)
        {
            int x = n % 10;
            n /= 10;
            s += pow(x, 5);
        }

        if (s == i)
        {
            cout << setw(6) << i << endl;
            sum += s;
        }
    }


    cout << "sum is " << sum << endl;
    return 0;
}
