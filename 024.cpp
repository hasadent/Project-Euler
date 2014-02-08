/****
 * Problem 24 - Lexicographic permutations
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

const int f[10] = {1,1,2,6,24,120,720,5040,40320,362880};

int main()
{
    vector<int> v = {0,1,2,3,4,5,6,7,8,9};
    vector<int> r;


    int n = 1000000;

    for (int i = 9; i >= 0; i--)
    {
        int j = 0;
        while (n > f[i]) j++, n-=f[i];
        r.push_back(v[j]);
        v.erase(v.begin() + j);
    }

    cout << "The millionth lexicographic permutation is ";
    for (auto i : r)
        cout << i;
    cout << "." << endl;


    return 0;
}
