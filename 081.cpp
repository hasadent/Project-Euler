/****
 * Problem 81 - Path sum: two ways
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
int m[N][N];
#define MIN2(_a, _b)  (_a > _b ? _b : _a)

int main()
{
    freopen("081.in", "r", stdin);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            cin >> m[i][j];
            cin.ignore();
        }

    for (int i = 1; i < N; i++)
    {
        m[i][0] += m[i-1][0];
        m[0][i] += m[0][i-1];
    }

    for (int i = 1; i < N; i++)
        for (int j = 1; j < N; j++)
            m[i][j] += MIN2(m[i-1][j], m[i][j-1]);

    cout << "The minimal path sum is " << m[N-1][N-1] << "." << endl;

    return 0;
}
