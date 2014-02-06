/****
 * Problem 21 - Amicable numbers
 */
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

int d[10001] = {0};

int main()
{
    for (int i = 2; i <= 10000; i++)
    {
        int sum = 1;
        int ub = i;

        for (int j = 2; j < ub; j++)
        {
            if (i % j == 0)
            {
                int d = i / j;

                if (d != j)
                {
                    sum += d + j;
                }
                else
                {
                    sum += j;
                }

                ub = d;
            }
        }

        d[i] = sum;
    }


    int sum = 0;
    for (int i = 2; i <= 10000; i++)
        if (d[d[i]] == i && i != d[i])
        {
            sum += i;
            cout << "d(" << i << ") = " << d[i] << endl;
        }
        
    cout << "The sum of all the amicable numbers under 10000 is " << sum << "." << endl;

    return 0;
}
