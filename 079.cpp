/****
 * Problem 79 - Passcode derivation
 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> v;

vector <int> l[10];
int r[10] = {0};
int u[10] = {0};
vector <int> result;

void topological_sort()
{
    vector <int> q;
    int n = 0;
    for (int i = 0; i < 10; i++)
        n += u[i];

    for (int i = 0; i < 10; i++)
        if (r[i] == 0 && u[i] == 1)
            q.push_back(i);

    for (int i = 0; i < n; i++)
    {
        if (q.empty()) break;

        int s = q.front();
        q.erase(q.begin());
        r[s] = -1;

        result.push_back(s);

        for (int i : l[s])
        {
            r[i] --;
            if (r[i] == 0)
                q.push_back(i);
        }
    }
}

int main()
{
    freopen("079.in", "r", stdin);

    string s;
    while (cin >> s)
    {
        v.push_back(s.substr(0, 2));
        v.push_back(s.substr(1, 2));
    }

    sort(v.begin(), v.end());
    auto it = unique(v.begin(), v.end());
    v.resize(distance(v.begin(), it));

    //cout << v.size() << endl;

    for (string s: v)
    {
        int f = s[0] - '0', t = s[1] - '0';
        l[f].push_back(t);
        r[t] += 1;
        u[t] = u[f] = 1;
    }

    topological_sort();
    cout << "The passcode may be `";
    for (int i : result)
        cout << i;
    cout << "'." << endl;

    return 0;
}
