/****
 * Problem 45 - Triangular, pentagonal, and hexagonal
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

inline int next_t(int t, int &n)
{
    n++;
    return t + n;
}

inline int next_p(int p, int &n)
{
    n++;
    return p + n * 3 - 2;
}

inline int next_h(int h, int &n)
{
    n++;
    return h + n * 4 - 3;
}

int main()
{
    int t = 40755, a = 285;
    int p = 40755, b = 165;
    int h = 40755, c = 143;

    t = next_t(t, a);
    p = next_p(p, b);
    h = next_h(h, c);

    for (; t != p || t != h;)
    {
        h = next_h(h, c);
        while (t < h) t = next_t(t, a);
        while (p < h) p = next_p(p, b);
    }

    cout << "The next number is " << t << ",\n"
        << " where n of (t,p,h) is ("
        << a << "," << b << "," << c << ")." << endl;

    return 0;
}
