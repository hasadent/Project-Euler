/****
 * Problem 82 - Path sum: three ways
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 80;
int g[N][N];
int m[N][N] = {0};
enum DIRECTION { LEFT = 1, RIGHT = 2, UP = 3, DOWN = 4};
#define MIN2(_a, _b)  (_a > _b ? _b : _a)

int main()
{
    freopen("081.in", "r", stdin);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            cin >> g[i][j];
            cin.ignore();
        }

    for (int i = 0; i < N; i++)
    {
        m[i][0] = g[i][0];
    }

    for (int j = 1; j < N; j++)
    {
        for (int i = 0; i < N; i++)
            m[i][j] = g[i][j] + m[i][j-1];

        for (int i = 1; i < N; i++)
            if (g[i][j] + m[i-1][j] < m[i][j])
                m[i][j] = g[i][j] + m[i-1][j];

        for (int i = N-2; i >= 0; i--)
            if (g[i][j] + m[i+1][j] < m[i][j])
                m[i][j] = g[i][j] + m[i+1][j];
    }

    int min_i = 0, min_m = m[0][N-1];
    for (int i = 1; i < N; i++)
        if (m[i][N-1] < min_m)
        {
            min_m = m[i][N-1];
            min_i = i;
        }

     cout << "The minimal path sum is " << min_m << "." << endl;

    return 0;
}
