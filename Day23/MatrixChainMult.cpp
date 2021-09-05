#include <iostream>
#include <climits>
#include <vector>
#include <stack>

using namespace std;

void printDP(vector<vector<int>> vec)
{
    for (auto &i : vec)
    {
        for (auto &j : i)
            std::cout << j << ' ';
        std::cout << '\n';
    }
}

void printBestMult(vector<int> curr, int i, vector<vector<vector<int>>> &dp, string &ans)
{
    if (curr[1] == -1) {
        ans += to_string(i);
        return;
    }

    ans += "(";
    printBestMult(dp[curr[1]][curr[2]], curr[1], dp, ans);
    ans += " x ";
    printBestMult(dp[curr[3]][curr[4]], curr[3], dp, ans);
    ans += ")";
}

void printBestMultDim(vector<int> curr, int i, int ar[], vector<vector<vector<int>>> &dp, string &ans)
{
    if (curr[1] == -1)
    {
        ans += "[" + to_string(ar[i]) + "x" + to_string(ar[i+1]) + "]";
        return;
    }

    ans += "(";
    printBestMultDim(dp[curr[1]][curr[2]], curr[1], ar, dp, ans);
    ans += " . ";
    printBestMultDim(dp[curr[3]][curr[4]], curr[3], ar, dp, ans);
    ans += ")";
}

int minOperations(int ar[], int n) /// 7
{
    vector<vector<vector<int>>> dp(n - 1, vector<vector<int>>(n - 1, {INT_MAX, 0, 0, 0, 0}));

    for (int i = 0; i < n - 1; ++i)
    {
        dp[i][i][0] = 0;
        dp[i][i][1] = -1;
        dp[i][i][2] = -1;
        dp[i][i][3] = -1;
        dp[i][i][4] = -1;
    }

    for (int l = 1; l < n; ++l)
    {
        for (int i = 0; i < n - l - 1; i += 1)
        {
            for (int j = i + 1; j <= i + l; ++j)
            {
                int newcost = dp[i][j - 1][0] + dp[j][i + l][0] + ar[i] * ar[j] * ar[i + l + 1];

                if (dp[i][i + l][0] > newcost)
                {
                    dp[i][i + l][0] = newcost;
                    dp[i][i + l][1] = i;
                    dp[i][i + l][2] = j - 1;
                    dp[i][i + l][3] = j;
                    dp[i][i + l][4] = i + l;
                }
            }
        }
    }

    string ans = "";
    // printBestMult(dp[0][n - 2], 0, dp, ans);
    printBestMultDim(dp[0][n - 2], 0, ar, dp, ans);
    cout << "Order: " << ans << "\n";
    // printDP(dp);
    return dp[0][n - 2][0];
}

int main()
{
    int ar[]{10, 30, 5, 10, 12, 45, 2};   //
    int ar2[]{10, 20, 30, 40, 30};
    cout << minOperations(ar, 7) << '\n'; // 2320
    cout << minOperations(ar2, 5) << '\n'; // 30000
    return 0;
}