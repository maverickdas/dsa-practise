#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
using vii = vector<pii>;
using vvi = vector<vector<int>>;

void printDP(vector<vector<int>> &dp, string &s1, string &s2)
{
    cout << "  ";
    for (char ch : s1)
        cout << ch << ' ';
    cout << '\n';
    int count = 0;
    for (const auto &i : dp)
    {
        cout << s2[count++] << ' ';
        for (const auto &j : i)
            cout << j << ' ';
        cout << '\n';
    }
}