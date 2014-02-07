/****
 * Problem 89 - Roman numerals
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int RomanNum_to_int(char * s)
{
    int n = 0;
    while (*s != 0)
    {
        switch(*s)
        {
        case 'M':
            n += 1000;
            break;

        case 'D':
            n += 500;
            break;

        case 'C':
            if (s[1] == 'M')
                n += 900, s++;
            else if (s[1] == 'D')
                n += 400, s++;
            else
                n+= 100;
            break;

        case 'L':
            n += 50;
            break;

        case 'X':
            if (s[1] == 'C')
                n += 90, s++;
            else if (s[1] == 'L')
                n += 40, s++;
            else
                n+= 10;
            break;

        case 'V':
            n += 5;
            break;

        case 'I':
            if (s[1] == 'X')
                n += 9, s++;
            else if (s[1] == 'V')
                n += 4, s++;
            else
                n+= 1;
            break;
        } /* switch */
        s++;
    }
    return n;
}

const int transform_info[][3] =
{   /* TYPE,  NUM,  LEN */
    {     1, 1000,   -1 },
    {     2,  900,    2 },
    {     2,  500,    1 },
    {     2,  400,    2 },
    {     1,  100,   -1 },
    {     2,   90,    2 },
    {     2,   50,    1 },
    {     2,   40,    2 },
    {     1,   10,   -1 },
    {     2,    9,    2 },
    {     2,    5,    1 },
    {     2,    4,    2 },
};

int int_to_RomanNum_len(int n)
{
    int l = 0;
    for (int i = 0; i < 12; i++)
    {
        if (n >= transform_info[i][1])
        {
            if (transform_info[i][0] == 1)
            {
                l += n / transform_info[i][1];
                n %= transform_info[i][1];
            }
            else
            {
                l += transform_info[i][2];
                n -= transform_info[i][1];
            }
        }
    }

    l += n;
    return l;
}

int main()
{
    freopen("089.in", "r", stdin);

    char in[1000];

    int r = 0;
    while (cin >> in)
    {
        int len = strlen(in);

        int n = RomanNum_to_int(in);
        int l = int_to_RomanNum_len(n);

        cout << "R: " << setiosflags(ios::left) << setw(17) << in
            << " I: " << resetiosflags(ios::left) << setw(5) << n
            << " L: " << setw(3) << l << endl;
        r += len - l;
    }

    cout << "The number of characters saved is " << r << "." << endl;

    return 0;
}
