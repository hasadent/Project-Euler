/****
 * Problem 42 - Coded triangle numbers
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

char input[16384];
vector<int> v;

int main()
{
    for (int i = 1, s = i; i < 100; i++, s+=i)
        v.push_back(s);

    freopen("042.in", "r", stdin);
    cin.getline(input, sizeof(input));

    int word = 0;
    for (char *s = strtok(input, "\",");
        s != NULL;
        s = strtok(NULL, "\","))
    {
        int sum = 0;
        while (*s != 0) sum += *s++ - 'A' + 1;

        if (find(v.begin(), v.end(), sum) != v.end())
            word++;
    }

    cout << "There are " << word << " triangle words." << endl;

    return 0;
}
