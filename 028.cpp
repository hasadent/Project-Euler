/****
 * Problem 28 - Number spiral diagonals
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main()
{
    unsigned int sum = 1;

    for (int i = 3; i <= 1001; i+= 2)
    {
        sum += i * i * 4 - 6 * i + 6;
    }
    cout << "The sum is " << sum << "." << endl;

    return 0;
}
