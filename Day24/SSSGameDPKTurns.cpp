#include <iostream>
#include <vector>
#include <climits>

using namespace std;

pair<int, int> maxScore(int ar[], int n, int k)
{
    pair<int, int> dp[n][n];
    int rem = n - 2 * k;
    for (int s = rem; s <= n; ++s)
    {
        for (int l = 0; l + s - 1 < n; ++l)
        {
            int r = l + s - 1;
            if (s == rem)
            {
                dp[l][r] = {0, 0};
                continue;
            }

            if (s == rem + 1)
            {
                dp[l][r] = {max(ar[l], ar[r]), 0};
                continue;
            }

            if (ar[l] + dp[l + 1][r].second > ar[r] + dp[l][r - 1].second)
            {
                dp[l][r] = {ar[l] + dp[l + 1][r].second, dp[l + 1][r].first};
            }
            else
            {
                dp[l][r] = {ar[r] + dp[l][r - 1].second, dp[l][r - 1].first};
            }
        }
    }
    return dp[0][n - 1];
}

int main()
{
    // 3, 4, 5, 8, 9, 18, 500 // k = 3, n=100, 99,98 - 97,96 -
    int ar[]{4, 8, 5, 3, 5, 18, 9}; // n - 2x(k-1)
    // cout << "Player 1: Shanti\nPlayer 2: SSS\n\n";
    // cout << "Did Shanti win? " << (maxFirstPlayerSkore(ar, sizeof(ar) / sizeof(ar[0])) ? "Yes" : "No") << '\n';
    pair<int, int> result = maxScore(ar, sizeof(ar) / sizeof(ar[0]), 3);
    cout << result.first << " " << result.second << "\n";
    return 0;
}