/****
 * Problem 31 - Coin sums
 */
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

int dp[201] = {0};
int coin[8] = {1, 2, 5, 10, 20, 50, 100, 200};

int main()
{
    dp[0] = 1;
    for (int i = 0; i < 8; i++)
        for (int j = coin[i]; j <= 200; j++ )
            dp[j] += dp[j-coin[i]];

    cout << "EUR 2 can be made by " << dp[200] << " ways."<< endl;
    return 0;
}
