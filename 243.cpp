/****
 * Problem 243 - Resilience
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

vector<int> p = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

int main()
{
    double y = 15499.0 / 94744.0;
    bool found = false;
    int d = 1, c = 1, result = -1;
    for (int i : p)
    {
        d *= i;
        c *= i-1;

        for (int j = 2; j < i; j++)
        {
            double x = c * j;
            x /= d * j - 1;
            if (x < y)
            {
                result = d * j;
                found = true;
                break;
            }
        }

        if (found) break;
    }

    cout << "The smallest denominator is " << result << "." << endl;

    return 0;
}
