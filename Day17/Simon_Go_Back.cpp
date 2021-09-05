#include <bits/stdc++.h>
// #include <
using namespace std;

using pii = pair<int, int>;
using vii = vector<pii>;
using vi = vector<int>;
using vvi = vector<vi>;

void printDP(vector<int>& ar)
{
    int n = ar.size();
    cout << "DP: ";
    for (int i = 0; i < n; ++i)
    {
        cout << ar[i] << ' ';
    }
    cout << "\n";
}

int slis(vector<int> arr){
    int N = arr.size();
    vector<int> dp(N, 1);

    for (int i=0; i< N; i++) {
        int max = 1;
        for(int j=0; j<i; j++) {
            int new_max = dp[j] + 1;
            if (arr[j] < arr[i] && new_max > max) {
                max = new_max;
            }
        }
        dp[i] = max;
    }
    printDP(dp);
    return *max_element(dp.begin(), dp.end());
}

int slcs(string a, string b) {
    int m = a.size();
    int n = b.size();
    vvi dp(m+1, vi(n+1, 0));
    for(int i=1; i<=m; i++) {
        for (int j=1; j<=n; j++) {
            if (a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}


int senpiLIS(vector<int> seq) {
    vector<int> dp(seq.size(), 1);
    int maxval = 1;

    for (int i = 0; i < seq.size(); ++i) {
        for (int j = i - 1; j >= 0; --j) {
            if (seq[j] < seq[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }

        maxval = max(maxval, dp[i]);
    }
    printDP(dp);
    return maxval;
}

int senpaiLCS(string s1, string s2) {
    vector<int> maxTillNow(s2.length(), 0);

    for (int i = 0; i < s1.length(); ++i)
    {
        int maxForNow = 0, tmp;
        for (int j = 0; j < s2.length(); ++j)
        {
            tmp = maxTillNow[j];
            if (s1[i] == s2[j])
            {
                maxTillNow[j] = max(maxTillNow[j], maxForNow + 1);
            }

            maxForNow = max(maxForNow, tmp);
        }
        printDP(maxTillNow);
    }

    return *max_element(maxTillNow.begin(), maxTillNow.end());
}

// int main()
// {
    // cout << "sen3.14\n";
    // vector<int> ar {3, 6, 8, 4, 12, 4, 7, 8, 4, 2};
    // cout << senpiLIS(ar) << '\n';
    // cout << "shantipriya\n";
    // cout << slis(ar) << '\n';

int maxSumSubarray(int ar[], int N)
{
    vector<int> dp(N, 0);
    dp[0] = ar[0] < 0 ? 0 : ar[0];

    for (int i = 1; i < N; ++i) {
        dp[i] = dp[i - 1] + ar[i] < 0 ? 0 : dp[i - 1] + ar[i];
    }

    return *max_element(dp.begin(), dp.end());
}

// Eg 1: -4, -1, 4, 2, -4, 3, -7, 7

// Eg 2: 1, -6,  4, 2, -4, 3, -7, 8, -2, 12
        //  1   -5  4  6   2  5   0  8   6  18

        //  1          2      3      8      12


int shantiMaxSumSubarray(int ar[], int n)
{
    vector<int> sumAr(n, 0);
    sumAr[0] = ar[0];
    for (int i=0; i<n-1; i++)
        sumAr[i+1] = sumAr[i] + ar[i+1];

    // vector<int> sums;
    int max_sum = INT_MIN;
    int curr_sum = ar[0];
    int prev = sumAr[0];
    for (int i=1; i<n; i++) {
        if (prev < sumAr[i]) {
            curr_sum += ar[i];
        }
        else if (prev > sumAr[i]) {
            // sums.push_back(curr_sum);
            if (curr_sum > max_sum)
                max_sum = curr_sum;
            curr_sum = 0;
        }
        prev = sumAr[i];
    }
    return max_sum;
}

int main()
{
    // cout << "sen3.14\n"
    //      << senpaiLCS("abcdbdahk", "ahkcdk") << "\n";
    // cout << "shantipriya\n"
    //      << slcs("abcdbdahk", "ahkcdk") << "\n";

    cout << "sen3.14\n";
    cout << maxSumSubarray(new int[8] {-4, -1, 4, 2, -4, 3, -7, 7}, 8) << "\n";
    cout << maxSumSubarray(new int[10] {1, -6,  4, 2, -4, 3, -7, 8, -2, 12}, 10) << '\n';

    cout << "shantipriya\n";
    cout << shantiMaxSumSubarray(new int[8] {-4, -1, 4, 2, -4, 3, -7, 7}, 8) << "\n";
    cout << shantiMaxSumSubarray(new int[10] {1, -6,  4, 2, -4, 3, -7, 8, -2, 12}, 10) << '\n';


    return 0;
}