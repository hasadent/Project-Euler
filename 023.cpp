/****
 * Problem 23 - Non-abundant sums
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

enum num_t { perfect = 0, deficient = 1, abundant = 2 };

int t[28124];

int test(int n)
{
    int sum = 0;
    for (int i = n / 2; i > 0; i--)
        if (n % i == 0)
            sum += i;

    return sum == n ? perfect : (sum > n ? abundant : deficient);
}


int main()
{
    for (int i = 1; i < 28124; i++)
        t[i] = test(i);

    int sum = 0;
    for (int i = 28124 - 1; i >= 1; i--)
    {
        int can_written = false;
        for (int j = i/2; j >= 12; j--)
            if (t[j] == abundant && t[i - j] == abundant)
            {
                can_written = true;
                break;
            }

        if (!can_written)
            sum += i;
    }

    cout << "The sum is " << sum << "." << endl;

    return 0;
}
