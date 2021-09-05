// LC91

#include <bits/stdc++.h>
using namespace std;

// 1 2 3| 4| 5 6 7

int numDecodings(string str)
{
    vector<int> dp(str.length());
    dp[0] = 1;

    auto isAnomaly = [str](int i)
    {
        return i==0 && stoi(str.substr(i-1, 2)) < 27;
    };

    for (int i = 1; i < str.length(); ++i) {
        if (isAnomaly(i)) {
            int tmp = 2, k = i;
            while (isAnomaly(k--))
            {
                tmp++;
            }
            dp[i] = dp[k] + tmp;
        }
        else
        {
            dp[i] = dp[i - 1];
        }
    }

    return dp[str.length() - 1];
}

int numDecSSS(string str)
{
    int n = str.length();
    int dp[n + 1][2];

    auto isAnomaly = [str](int i)
    {
        return i != 0 && stoi(str.substr(i - 1, 2)) <= 26;
    };

    dp[0][0] = 0; // ends with single dig
    dp[0][1] = -1; // ends with double dig

    dp[1][0] = 1;
    dp[1][1] = -1;

    for (int i = 2; i < n; ++i)
    {
        dp[i][0] = max(dp[i - 1][1], dp[i - 1][0]) + 1;
        if (isAnomaly(i - 1))
        {
            dp[i][1] = max(dp[i - 2][0], dp[i - 2][1]) + 2;
        }
        else
        {
            dp[i][1] = -1;
        }
    }
    return max(dp[n][0], dp[n][1]);
}

int main()
{

}