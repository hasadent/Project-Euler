/****
 * Problem 44 - Pentagon numbers
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

inline int next_p(int p, int &n)
{
    n++;
    return p + n * 3 - 2;
}

inline int prev_p(int p, int & n)
{
    p = p - (n * 3 - 2);
    n--;
    return p;
}

inline bool is_pentagon(int n)
{
    double s = (sqrt(n * 24 + 1) + 1) / 6;
    return s == ((int)s);
}

int main()
{
    int k = 1, j;
    int n = 1, m;

    for (bool found; !found; )
    {
        n = next_p(n, k);

        for (j = k - 1, m = j * (j * 3 - 1) / 2;
            j > 1;
            m = prev_p(m, j))
        {
            if (is_pentagon(n + m) && is_pentagon(n - m))
            {
                found = true;
                break;
            }
        }
    }

    cout << "The minimum |D| is " << n - m << ", where k = "
        << k << " and j = " << j << "." << endl;

    return 0;
}
