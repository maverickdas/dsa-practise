#include <bits/stdc++.h>

using namespace std;

using vvi = vector<vector<int>>;

void fillzero(vvi arr)
{
    int m = arr.size();
    int n = arr[0].size();
    int row[m];
    fill(row, row + m, -1);
    int col[n];
    fill(col, col + n, -1);

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (arr[i][j] == 0)
            {
                row[i] = 0;
                col[j] = 0;
            }

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            if (row[i] == 0 || col[j] == 0)
                arr[i][j] = 0;
        }

    // return arr;
}

int lcs(string s1, string s2)
{
    int m = s1.length();
    int n = s2.length();
    int dp[2][n + 1];

    for (int j = 0; j <= n; j++)
    {
        dp[0][j] = 0;
    }
    dp[1][0] = 0;
    for (int i = 1; i <= m; i++)
    {

        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i % 2][j] = dp[(i - 1) % 2][j - 1] + 1;
            }
            else
            {
                int maxv = max(dp[(i - 1) % 2][j], dp[i % 2][j - 1]);
                dp[i % 2][j] = maxv;
            }
        }
        cout << "curr row " << i << " - ";
        for (int j = 0; j <= n; j++)
            cout << dp[i % 2][j] << " ";
        cout << "\n";
    }
    return dp[m % 2][n];
}

int main()
{
    // vvi inp = {{0,1,2,0},
    // {3,4,5,2},
    // {1,3,1,5}};
    // fillzero(inp);
    // string s1 = "ookla";
    // string s2 = "okay";
    string s1 = "abcdbdahk";
    string s2 = "ahkcdk";
    lcs(s1, s2);
    return 0;
}