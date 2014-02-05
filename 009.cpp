/****
 * Problem 9 - Special Pythagorean triplet
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
    //
    // a^2 + b^2 = c^2
    // a + b + c = 1000
    // -----------------------------
    // a*b = (500-c)*1000 ..... eq(1)
    //   c < 500 ............ cond(1)
    //   b < c .............. cond(2)
    //
    int i, j, k;
    bool done = false;
    for (i = 500; i > 0; i--)
    {
        int x = (500 - i) * 1000;
        for (j = i-1; j > 250; j--)
        {
            k = 1000 - j - i;
            if (x == j*k)
            {
                done = true;
                break;
            }
        }

        if (done)
            break;
    }

    cout << i << endl;
    cout << j << endl;
    cout << k << endl;
    cout << i*j*k << endl;

    return 0;
}
