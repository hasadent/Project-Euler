/****
 * Problem 92 - Square digit chains
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int NUM_SIZE = 10000000;
enum { NONE = 0, ARRIVE_1 = 1, ARRIVE_89 = 2};
unsigned char dp[NUM_SIZE+1] = {0};
const int sq[10] = {0, 1, 4, 9, 16, 25, 36, 49, 64, 81};

int main()
{
    vector<int> v;

    dp[0] = -1;
    dp[1] = ARRIVE_1;
    dp[89] = ARRIVE_89;


    for (int i = NUM_SIZE; i >= 0; i--)
    {
        if (dp[i] != 0)
            continue;

        int n = i;

        for (;;)
        {
            v.push_back(n);

            int s = 0;
            while (n != 0)
            {
                s += sq[n % 10];
                n /= 10;
            }

            if (dp[s] != 0)
            {
                while (!v.empty())
                {
                    int x = v.back();
                    v.pop_back();
                    dp[x] = dp[s];
                }
                break;
            }
            else
            {
                n = s;
                if (s > NUM_SIZE)
                    cout << s << endl;
            }
        }
    }

    int c = 0;
    for (int i = 0; i <= NUM_SIZE; i++)
        if (dp[i] == ARRIVE_89) c++;

    cout << "There are " << c << " numbers that will arrive at 89." << endl;

    return 0;
}
