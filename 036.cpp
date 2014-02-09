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
    vector<int> v;

    while (n != 0) {v.push_back(n%base); n /= base;}

    for (int i = 0, j = v.size() - 1; i < j; i++, j--)
        if (v[i] != v[j])
            return false;

    return true;
}

bool is_palindrome_base10(int n)
{
    char v[14];
    sprintf(v, "%d", n);
    for (int i = 0, j = strlen(v) - 1; i < j; i++, j--)
        if (v[i] != v[j])
            return false;
    return true;
}

bool is_palindrome_base2(int n)
{
    int x = 31;
    while ((n >> x) == 0) x --;

    for (; x > 0; x -= 2, n >>= 1)
        if (((n >> x) & 1) != (n&1))
            return false;

    return true;
}


int main()
{   
    int sum = 0;
    for (int i = 1; i <= 1000000; i+= 2)
        if (i % 10 != 0 && is_palindrome(i, 10) && is_palindrome_base2(i))
            sum += i;
    cout << "The sum is " << sum << "." << endl;

    return 0;
}
