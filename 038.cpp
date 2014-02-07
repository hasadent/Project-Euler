/****
 * Problem 38 - Pandigital multiples
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

bool is_pandigital(int a, int b, int c)
{
    int x[10] = {0};

    for (int i = a; i != 0; x[i%10]+=1, i/=10);
    for (int i = b; i != 0; x[i%10]+=1, i/=10);
    for (int i = c; i != 0; x[i%10]+=1, i/=10);

    for (int i = 1; i < 10; i++)
        if (x[i] != 1) return false;
    return true;
}

int main()
{
    bool found = false;

    int i;
    for (i = 9999; i >= 1000; i--)
        if (is_pandigital(i, i*2, 0))
        {
            found = true;
            break;
        }

    if (!found)
    {
        for (i = 9999; i >= 1000; i--)
            if (is_pandigital(i, i*2, i*3))
            {
                found = true;
                break;
            }
    }

    cout << "The largest number is " << i << i * 2 << "." << endl;

    return 0;
}
