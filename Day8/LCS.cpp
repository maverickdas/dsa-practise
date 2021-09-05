#include <bits/stdc++.h>
using namespace std;


// abcdbdahk
// ahkcdk

void printDP(vector<vector<int>> dp, string s1, string s2) {
    cout << "  ";
    for (char ch : s1)
        cout << ch << ' ';
    cout << '\n';
    int count = 0;
    for (const auto &i: dp)
    {
        cout << s2[count++] << ' ';
        for (const auto &j: i)
            cout << j << ' ';
        cout << '\n';
    }
}

int lcs(string s1, string s2)
{
    int result = 0;
    if (s1.length() > s2.length())
    {
        string tmp = s1;
        s1 = s2;
        s2 = tmp;
    }
    vector<vector<int>> dp(s2.length(), vector<int>(s1.length() + 1, 0));
    for (int i = 0; i < s1.length(); ++i) {
        int max = 0;
        for (int j = 0; j < s2.length(); ++j)
        {
            if (s1[i] == s2[j]) {
                dp[j][i] = max + 1;
                if (result < dp[j][i])
                    result = dp[j][i];
            }
            if (i > 0 && dp[j][i - 1] > dp[j][s1.length()])
            {
                dp[j][s1.length()] = dp[j][i - 1];
            }
            if (max < dp[j][s1.length()])
                max = dp[j][s1.length()];
        }
    }
    printDP(dp, s1, s2);
    return result;
}

int main()
{
    cout << "sen3.14\n"
         << lcs("abcdbdahk", "ahkcdk") << "\n";
    return 0;
}