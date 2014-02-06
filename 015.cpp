/****
 * Problem 15 - Lattice paths
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

long long int dp[21][21];

int main()
{
    for (int i = 0; i <= 20; i++)
        dp[i][0] = dp[0][i] = 1;

    for (int i = 1; i <= 20; i++)
        for (int j = 1; j <= 20; j++)
            dp[i][j] = dp[i-1][j] + dp[i][j-1];

    cout << "There are " << dp[20][20] << " route through a 20×20 grid." << endl;

    return 0;
}
