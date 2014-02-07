/****
 * Problem 83 - Path sum: four ways
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
unsigned int m[N][N];
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


    memset(m , -1, sizeof(m));
    m[0][0] = g[0][0];
    for (int i = 1; i < N; i++)
    {
        m[i][0] = m[i-1][0] + g[i][0];
        m[0][i] = m[0][i-1] + g[0][i];
    }

    for (bool updated = true; updated; )
    {
        updated = false;

        // UP
        for (int j = 0; j < N; j++)
            for (int i = 1; i < N; i++)
                if (m[i][j] > m[i-1][j] + g[i][j])
                {
                    m[i][j] = m[i-1][j] + g[i][j];
                    updated = true;
                }

        // LEFT
        for (int j = 1; j < N; j++)
            for (int i = 0; i < N; i++)
                if (m[i][j] > m[i][j-1] + g[i][j])
                {
                    m[i][j] = m[i][j-1] + g[i][j];
                    updated = true;
                }

        // DOWN
        for (int j = 0; j < N; j++)
            for (int i = N-2; i >= 0; i--)
                if (m[i][j] > m[i+1][j] + g[i][j])
                {
                    m[i][j] = m[i+1][j] + g[i][j];
                    updated = true;
                }

        // RIGHT
        for (int j = N-2; j >= 0; j--)
            for (int i = 0; i < N; i++)
                if (m[i][j] > m[i][j+1] + g[i][j])
                {
                    m[i][j] = m[i][j+1] + g[i][j];
                    updated = true;
                }
    }


     cout << "The minimal path sum is " << m[N-1][N-1] << "." << endl;

    return 0;
}
