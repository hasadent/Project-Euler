/****
 * Problem 14 - Longest Collatz sequence
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int dp[100000] = {0};

int main()
{
    int max_c = 0;
    int max_i = 0;

    for (int i = 2; i <= 1000000; i++)
    {
        unsigned int j = i;

        int c = 1;

        while (j != 1)
        {
            if (j < 100000 && dp[j] != 0)
            {
                c += dp[j];
                break;
            }

            if ((j&1) == 0)
                j /= 2;
            else
                j = j*3+1;
            c++;
        }

        if (i < 100000)
            dp[i] = c;

        if (c > max_c)
        {
            max_c = c;
            max_i = i;
        }
    }
    cout << "Number " << max_i << " produces the longest chain." << endl;

    return 0;
}
