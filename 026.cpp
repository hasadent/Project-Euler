/****
 * Problem 26 - Reciprocal cycles
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int n[1001] = {0};
int remainder_pos[1000];

int main()
{
    n[0] = n[1] = -1;
    for (int i = 2; i <= 1000; i+=2)
        n[i] = -1;
    for (int i = 5; i <= 1000; i+=5)
        n[i] = -1;

    int max_l = 0;
    int max_i = 0;

    for (int i = 3; i <= 1000; i++)
        if (n[i] == 0)
        {
            memset(remainder_pos, 0, sizeof(remainder_pos));

            int pos = 0;
            int v = 1;
            while (remainder_pos[v] == 0 && v != 0)
            {
                remainder_pos[v] = pos ++;
                v = (v * 10) % i;
            }

            if (pos - remainder_pos[v] > max_l)
            {
                max_l = pos - remainder_pos[v];
                max_i = i;
            }
        }

    cout << "Number " << max_i
        << " has the longest recurring cycle with length "
        << max_l << "." << endl;

    return 0;
}
