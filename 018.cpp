/****
 * Problem 18 - Maximum path sum I
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int m[15][15];
int dp[15][15] = {0};
#define MAX2(_a, _b) (_a > _b ? _a : _b)

int main()
{
    freopen("018.in", "r", stdin);

    for (int i = 0; i < 15; i++)
        for (int j = 0; j < i+1; j++)
            cin >> m[i][j];

    dp[0][0] = m[0][0];
    for (int i = 1; i < 15; i++)
    {
        dp[i][0] = dp[i-1][0] + m[i][0];
        dp[i][i] = dp[i-1][i-1] + m[i][i];
    }

    for (int i = 2; i < 15; i++)
        for (int j = 1; j < i; j++)
        {
            dp[i][j] = MAX2(dp[i-1][j], dp[i-1][j-1]) + m[i][j];
        }

    int m = 0;
    for (int i = 0; i < 15; i++)
        if (dp[14][i] > m) m = dp[14][i];
    cout << "The maximum is " << m << endl;
    return 0;
}
