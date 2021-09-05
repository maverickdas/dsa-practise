#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
using vii = vector<pii>;
using vi = vector<int>;
using vvi = vector<vector<int>>;


// answer = (1, 4), (5, 7), (8, 11), (12, 14)

void printDP(vvi dp)
{
    for (auto &el : dp)
        cout << el[0] << " ";
    cout << "\n";
    for (auto &el : dp)
        cout << el[1] << " ";
    cout << "\n";
}

int weightedMaxMeets(vvi meets)
{
    int n = meets.size();
    vvi dp(n, vector<int>(2));

    dp[0][0] = meets[0][2];
    dp[0][1] = 0;

    // sort(meets.begin(), meets.end(), [](vi &a, vi &b)
    //      { return a[1] != b[1] ? a[1] < b[1] : a[0] > b[0]; });

    auto clashes = [](vi &a, vi &b)
    {
        return (a[1] < b[1] && a[1] > b[0])
            || (a[0] < b[1] && a[0] > b[0])
            || (b[1] < a[1] && b[1] > a[0])
            || (b[0] < a[1] && b[0] > a[0]);
    };

    for (int i = 1; i < meets.size(); ++i)
    {
        dp[i][0] = 0;
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]);
        for (int j = 0; j < i; ++j)
        {
            if (!clashes(meets[i], meets[j]) && dp[i][0] < dp[j][0])
            {
                dp[i][0] = dp[j][0];
            }
        }
        dp[i][0] += meets[i][2];
    }
    printDP(dp);
    return max(dp[meets.size() - 1][0], dp[meets.size() - 1][1]);
}

int main()
{

    vvi meets {{ 0, 6, 60 },
               { 1, 4, 30 },
               { 3, 5, 10 },
               { 5, 7, 30 },
               { 5, 9, 50 },
               { 7, 8, 10 }};
    // vvi meets{{1, 4, 1}, {3, 5, 1}, {0, 6, 1}, {5, 7, 1}, {3, 8, 1}, {5, 9, 1}, {6, 10, 1}, {8, 11, 1}, {8, 12, 1}, {2, 13, 1}, {12, 14, 1}};
    cout << weightedMaxMeets(meets) << '\n';

    return 0;
}