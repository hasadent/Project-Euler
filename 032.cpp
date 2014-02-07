/****
 * Problem 32 - Pandigital products
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

bool is_pandigital(int a, int b, int c)
{
    int x[10] = {0};
    for (int i = a; i != 0; x[i%10]+=1, i/=10);
    for (int i = b; i != 0; x[i%10]+=1, i/=10);
    for (int i = c; i != 0; x[i%10]+=1, i/=10);
    for (int i = 1; i < 10; i++)
        if (x[i] != 1) return false;
    return true;
}

int main()
{
    int sum = 0;
    for (int i = 1234; i <= 9876; i++)
        for (int j = 1; j <= 98; j++)
            if (i % j == 0 && is_pandigital(i, j, i/j))
            {
                sum += i;
                break;
            }
    cout << "The sum of products is " << sum << "." << endl;

    return 0;
}
