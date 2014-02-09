/****
 * Problem 36 - Double-base palindromes
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

bool is_palindrome(int n, int base)
{
    int v[32];
    int s = 0;

    while (n != 0) {v[s++] = n % base; n /= base;}

    for (int i = 0, j = s - 1; i < j; i++, j--)
        if (v[i] != v[j])
            return false;

    return true;
}

int main()
{
    int sum = 0;
    for (int i = 1; i <= 1000000; i+= 2)
        if (i % 10 != 0 && is_palindrome(i, 10) && is_palindrome(i,2 ))
            sum += i;
    cout << "The sum is " << sum << "." << endl;

    return 0;
}
