#include <bits/stdc++.h>
using namespace std;

//  3 6 8 4 12 4 7 8 4 2
void printDP(int ar[], int n)
{
    cout << "DP: ";
    for (int i = 0; i < n; ++i)
    {
        cout << ar[i] << ' ';
    }
    cout << "\n";
}

int lissss(int ar[], int n)
{
    int dp[n], dp2[n];

    for (int i = 0; i < n; i++)
    {
        dp[i] = dp2[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (ar[j] < ar[i] && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
            }
        }
        if (i > 0)
            dp2[i] = dp[i] > dp2[i - 1] ? dp[i] : dp2[i - 1];
        printDP(dp2, n);
        // cout << max << ", " << dp2[i - 1];
    }

    return dp2[n-1];
}

int shantipriyoLIS(int ar[], int n) {
    int dp[n];
    fill(dp, dp + n, 1);

    for (int i=0; i<n; i++) {
        int max=1;
        for (int k=0; k<i; k++){
            int new_max = dp[k] + 1;
            if (ar[k] < ar[i] && new_max > max)
                max = new_max;
        }
        dp[i] = max;
    }

    printDP(dp, n);
    return *max_element(dp, dp + n);
}

int lis(int ar[], int n) {
    int max, dp[n];

    for (int i = 0; i < n; i++) {
        dp[i] = max = 1;
        for (int j = 0; j < i; j++)
        {
            if(ar[j] < ar[i] && max < dp[j] + 1) {
                max = dp[j] + 1;
            }
        }
        dp[i] = max;
    }

    max = 0;
    for (int i = 0; i < n; i++)
    {
        if (max < dp[i]) {
            max = dp[i];
        }
    }

    printDP(dp, n);

    return max;
}

// int shantipriyoLis(int ar[], int n) {
//     int dp[n]{0};
//     fill(dp, dp[n], 0);
//     for (int i=1; i<n; i++) {
//         if (dp[i] > dp[i-1])
//             dp[i] = dp[i-1] + 1;
//     }

// }






int main()
{
    cout << "sen3.14\n";
    int ar[]{3, 6, 8, 4, 12, 4, 7, 8, 4, 2};
    cout << lissss(ar, 10) << '\n';
    return 0;
}