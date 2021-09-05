#include <iostream>

using namespace std;

// 0 0 1 0 0 1 1 1 0 1 -> x

// 0 0 0 0 0 0 0 0 0 1 -> 1

// 0 0 0 0 0 0 0 0 1 1 -> 3

// rem0=10                                                         0 0 1 0
// passed1=0

// 0 0 1 1 0 1 0 1 0 0 0 0 1

[
"eat",
"tea",
"tan",
"ate",
"nat",
"bat"
]

    // 0 0
    // 1 1

    int
    minFlips(int ar[], int n)
{
    int dp[2]; //dp[1][2]
    dp[0] = ar[0];
    dp[1] = 1 - ar[0];

    for (int i = 1; i < n; ++i)
    {
        if (ar[i] == 0)
        {
            dp[0] = dp[0];
            dp[1] = dp[1] + 1;
        }
        else
        {
            dp[1] = min(dp[0], dp[1]);
            dp[0] = dp[0] + 1;
        }
    }
    return min(dp[0], dp[1]);
}

// 0 0 0 0 0 i
// 0 0 1 1 1 i

// 0 0 1 1 1 1 1 1 1 1 1 1 1

// int dp[n][2];

// dp[i][0] --> 0
// dp[i][1] --> 1

// min(dp[n - 1][0], dp[n - 1][1])

//     0 0 0 0 0 1 1 1 1 1

//     1 0 0 0 0 0 1 0 0 0

int main()
{
    int ar[]{0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1};
    cout << minFlips(ar, 13) << '\n';
    return 0;
}