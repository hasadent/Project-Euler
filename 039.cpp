/****
 * Problem 39 - Integer right triangles
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int max_c = 0, max_p;
    for (int p = 3; p <= 1000; p++)
    {
        int count = 0;
        for (int c = p / 2, u = c / 3; c >= u; c--)
        {
            for (int b = c - 1, a; (a = p - c - b) <= b ; b--)
            {
                if (a*a + b*b == c*c)
                {
                    cout << "p = " << setw(4) << p
                        << " a = " << setw(3) << a
                        << " b = " << setw(3) << b
                        << " c = " << setw(3) << c
                        << endl;
                    count ++;
                }
            }
        }
        if (count > max_c)
        {
            max_c = count;
            max_p = p;
        }
    }

    cout << "\nThe number of solutions is maximised for p = " << max_p << "." << endl;

    return 0;
}
