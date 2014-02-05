/****
 * Problem 6 - Sum square difference
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int v = 100;

int main()
{
    int n = (1 + v) * v / 2;
    int ns = v * (v + 1) * (v * 2 + 1) / 6;

    cout << n*n - ns << endl;

    return 0;
}
