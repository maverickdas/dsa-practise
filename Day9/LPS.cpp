// longest palindromic subsequence

#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
using vii = vector<pii>;
using vvi = vector<vector<int>>;

// boobamehbooba
// LCS of Reverse string
//     boobaboob

//     // 2 4 3 1 6 8 4 2 5
//     // 1 2 2 3 4 4 5 6 8

//     int

void printDP(vector<vector<int>> &dp, string s1, string s2)
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
        cout << "\n";
    }
}

int lps(string s)
{
    int result = 0;
    vector<int> dp(s.size(), 0);
    for (int i = 0; i < s.size(); ++i)
    {
        int maxValue = 0;
        for (int j = 0; j < s.size(); ++j)
        {
            if (s[i] == s[s.size() - 1 - j])
            {
                dp[j] = max(maxValue + 1, dp[j]);
                result = max(result, maxValue + 1);
            }
            maxValue = max(dp[j], maxValue);
        }
    }
    // printDP(dp, s1, s2);
    return result;
}

int shantipriyoLps(string s1)
{
    int m = s1.length();
    vector<vector<int>> dp(m + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= m; i++)
    {
        dp[i][0] = 0;
        for (int j = 0; j <= m; j++)
            dp[0][j] = 0;
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s1[m - j])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j-1]);
            }
        }
    }
    string s2(s1);
    reverse(s2.begin(), s2.end());
    return dp[m][m];
}

int main()
{
    string s = "boobamehbooba";
    cout << "shantipriyo?\n";
    cout << shantipriyoLps(s) << "\n";
    cout << "sen3.14\n";
    cout << lps(s) << '\n';
    return 0;
}