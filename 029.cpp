/****
 * Problem 29 - Distinct powers
 */
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

inline int power_of(int x, int y)
{
    int p = 0;
    for (; x % y == 0; x /= y, p++);

    return x == 1 ? p : -1;

}

const int MAX_NUM = 100;
const int MAX_POWER = 100;

int p[601];
int main()
{
    int sq = sqrt(MAX_NUM);
    int term = (MAX_NUM-1) * (MAX_POWER - 1);
    for (int a = sqrt(MAX_NUM); a >=2 ; a--)
    {
        bool power_of_other_num = false;
        for (int i = 2;  i <= sq; i++)
        {
            if (power_of(a, i) > 1)
            {
                power_of_other_num = true;
                break;
            }
        }

        if (power_of_other_num)
            continue;

        memset(p, 0, sizeof(p));
        for (int x = a, y = 1; x <= MAX_NUM; x *= a, y++)
            for (int i = 2; i <= MAX_POWER; i++ )
                p[i*y] += 1;

        int sum = 0;
        for (int i = 0; i < 601; i++)
        {
            if (p[i] > 1) sum += p[i] - 1;
        }
        term -= sum;
        cout << "terms removed by " << a << " and its power is " << sum << endl;
    }

    cout << term << endl;
    return 0;
}
