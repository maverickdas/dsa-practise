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

pair<int, int> maxFirstPlayerSkore(int ar[], int n)
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



    return dp[0][n - 1];
}

int main()
{
    int ar[] {4, 8, 5, 3, 5, 18, 9};
    pair<int, int> result = maxFirstPlayerSkore(ar, 7);
    cout << result.first << " " << result.second << '\n';
    return 0;
}