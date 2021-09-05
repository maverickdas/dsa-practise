#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// 4 8 5 3 5 8 9 1

// 8 5 ..

// SSS -> 4 5 9 5 = 23
// Shanti -> 8 1 8 3 = 20

// SSS -> 8 1 3 55
// Shanti -> 4 5 9 3 6

bool maxFirstPlayerSkore(int ar[], int n)
{
    vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, {INT_MIN, INT_MIN}));
    for (int l = 1; l <= n; ++l)
    {
        for (int i = 0; i <= n - l; ++i)
        {
            int choice1 = i;
            int choice2 = i + l - 1;

            if (choice1 == choice2)
            {
                dp[choice1][choice2] = {ar[choice1], 0};
            }
            // CHOICE 1                                              // CHOICE 2
            else if (ar[choice1] + dp[choice1 + 1][choice2].second > ar[choice2] + dp[choice1][choice2 - 1].second)
            {
                dp[choice1][choice2].first = ar[choice1] + dp[choice1 + 1][choice2].second;
                dp[choice1][choice2].second = dp[choice1 + 1][choice2].first;
            }
            else
            {
                dp[choice1][choice2].first = ar[choice2] + dp[choice1][choice2 - 1].second;
                dp[choice1][choice2].second = dp[choice1][choice2 - 1].first;
            }
        }
    }

    return dp[0][n - 1].first > dp[0][n - 1].second;
}

pair<int, int> maxKTurns(int ar[], int n, int k)
{
    vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, {INT_MIN, INT_MIN}));

    for (int l = 1; l <= n; ++l)
    {
        for (int i = 0; i <= n - l; ++i)
        {
            int choice1 = i;
            int choice2 = i + l - 1;

            if (choice1 == choice2)
            {
                dp[choice1][choice2] = {ar[choice1], 0};
            }
            else if (l <= n - 2 * (k - 1))
            {
                if (ar[choice1] > ar[choice2])
                {
                    dp[choice1][choice2].first = ar[choice1];
                    dp[choice1][choice2].second = dp[choice1 + 1][choice2].first;
                }
                else
                {
                    dp[choice1][choice2].first = ar[choice2];
                    dp[choice1][choice2].second = dp[choice1][choice2 - 1].first;
                }
            }
            else
            {
                if (ar[choice1] + dp[choice1 + 1][choice2].second > ar[choice2] + dp[choice1][choice2 - 1].second)
                {
                    dp[choice1][choice2].first = ar[choice1] + dp[choice1 + 1][choice2].second;
                    dp[choice1][choice2].second = dp[choice1 + 1][choice2].first;
                }
                else
                {
                    dp[choice1][choice2].first = ar[choice2] + dp[choice1][choice2 - 1].second;
                    dp[choice1][choice2].second = dp[choice1][choice2 - 1].first;
                }
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
    pair<int, int> result = maxKTurns(ar, sizeof(ar) / sizeof(ar[0]), 3);
    cout << result.first << " " << result.second << "\n";
    return 0;
}

// 5 / k=3

// ss -> 4 5 9 = 18
// shanti -> 8 3 18 = 29