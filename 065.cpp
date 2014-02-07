/****
 * Problem 65 - Convergents of e
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

class big_num
{
    static const int BIG_NUM_SIZE = (1000000/4+1);
    int num[BIG_NUM_SIZE];
public:
    big_num();

    void operator= (const char *);

    void      operator=  (const int);
    big_num   operator*  (const int);
    big_num & operator+= (const int);

    big_num & operator=  (const big_num &);
    big_num   operator+  (const big_num &);
    big_num & operator+= (const big_num &);

    friend ostream& operator<<(ostream& os, const big_num& dt);
    int sum_digit();
};

big_num::big_num()
{}

int big_num::sum_digit()
{
    int sum = 0;
    for (int i = 0; i < BIG_NUM_SIZE; i++)
    {
        int n = num[i];

        while (n != 0)
        {
            sum += n % 10;
            n /= 10;
        }
    }

    return sum;
}

void big_num::operator=(const int n)
{
    memset(num, 0, sizeof(num));
    int j = n;

    num[BIG_NUM_SIZE-1] = j % 10000;
    j /= 10000;
    num[BIG_NUM_SIZE-2] = j % 10000;
    num[BIG_NUM_SIZE-3] = j / 10000;
}

big_num big_num::operator*(const int n)
{
    big_num r;

    for (int i = 0; i < BIG_NUM_SIZE; i++)
    {
        r.num[i] = num[i] * n;
    }

    for (int i = BIG_NUM_SIZE - 1; i > 0; i--)
    {
        r.num[i-1] += r.num[i] / 10000;
        r.num[i]   = r.num[i] % 10000;
    }

    return r;
}

big_num & big_num::operator=(big_num const &rhs)
{
    for (int i = 0; i < BIG_NUM_SIZE; i++)
        num[i] = rhs.num[i];

    return *this;
}

big_num & big_num::operator+= (big_num const &rhs)
{
    for (int i = 0; i < BIG_NUM_SIZE; i++)
        num[i] += rhs.num[i];

    for (int i = BIG_NUM_SIZE - 1; i > 0; i--)
    {
        num[i-1] += num[i] / 10000;
        num[i]   =  num[i] % 10000;
    }

    return *this;
}

ostream& operator<<(ostream& os, const big_num& bn)
{
    int i = 0;
    while (i < big_num::BIG_NUM_SIZE && bn.num[i] == 0) i++;

    if (i == big_num::BIG_NUM_SIZE)
    {
        os << "0";
    }
    else
    {
        os << bn.num[i];
        i++;
    }

    if (i < big_num::BIG_NUM_SIZE)
    {
        for (; i < big_num::BIG_NUM_SIZE; i++)
            os << setfill('0') << setw(4) << bn.num[i];
    }

    return os;
}

int cx[101];
big_num c, d, t;

int main()
{
    cx[1] = 2;
    for (int i = 2, j = 2; i < 100; i+=3, j+=2)
        cx[i] = cx[i+2] = 1, cx[i+1] = j;

    const int start = 100;

    c = 1;
    d = cx[start];

    for (int i = start-1; i >= 1; i--)
    {
        t = d * cx[i];
        c += t;

        // swap
        t = d, d = c, c = t;
    }


    cout << "The sum is " << d.sum_digit() << "." << endl;

    return 0;
}
