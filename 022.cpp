/****
 * Problem 22 - Names scores
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

char input[65536];

int main()
{
    freopen("022.in", "r", stdin);
    cin.getline(input, 65536);

    vector <char *> name_list;
    for (char * name = strtok(input, "\",");
        name != NULL;
        name = strtok(NULL, "\","))
            name_list.push_back(name);

    sort(name_list.begin(), name_list.end(),
         [](const char * a, const char * b) { return strcmp(a,b) < 0; });

    int order = 1;
    long long int g_sum = 0;
    for (auto name : name_list)
    {
        int sum = 0;
        for (char *p = name; *p != 0; p++)
            sum += *p - 'A' + 1;
        sum *= order++;

        g_sum += sum;
    }

    cout << "The total of all the name scores is " << g_sum << "." << endl;

    return 0;
}
