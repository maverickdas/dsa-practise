#include <vector>
#include <iostream>
#include <climits>
#include <string>

using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;

void printDP(vvi vec)
{
    for(auto &i: vec)
    {
        for(auto &j: i)
            std::cout << j << ' ';
        std::cout << '\n';
    }
}

string recursedpk(vvi dpk, vi ar, int i, int j) {
    int k = dpk[i][j];
    // cout << "i " << i << " j " << j << " k " << k << "\n";
    // cout << "partn after " << ar[k] << "," << ar[k+1] << "\n";
    if (j - i == 1) {
        return "(" + to_string(ar[i]) + "," + to_string(ar[i+1]) + " x " + to_string(ar[i+1]) + "," + to_string(ar[i+2]) + ")";
    }
    if (j == i)
        return "(" + to_string(ar[i]) + "," + to_string(ar[i+1]) + ")";
    string out = "(";
    if (k >= i)
        out += recursedpk(dpk, ar, i, k) + " x ";

    if (k+1 <= j)
        out += recursedpk(dpk, ar, k+1, j);
    out += ")";
    return out;
}

int sMCM(vector<int> ar) {
    int N = ar.size();
    vvi dp(N-1, vi(N-1, INT_MAX)); // dp for N-1 matrices
    vvi dpk(N-1, vi(N-1, -1)); // dp of partitions for N-1 matrices

    for (int i=0; i< N-1; i++) {
        dp[i][i] = 0; // no cost for single matrix
    }
    for (int s=2; s<N; s++) { // sliding
        for (int i=0; i+s<N; i++) { // windows limits i and j
            int j = i + s - 1;
            // j will move between idx 1 (ie, 0 + 2 - 1) and N-3 (ie, N - 2 - 1) (inclusive limits)

            // if (s == 2) {
            //     dp[i][j] = ar[i] * ar[i+1] * ar[j+1];
            //     continue;
            // }
            for (int k=i; k<j; k++) { // partition point k between i and j
                int cost = dp[i][k] + dp[k+1][j] + ar[i]*ar[k+1]*ar[j+1];
                if (cost < dp[i][j]) {
                    dp[i][j] = min(dp[i][j], cost);
                    dpk[i][j] = k;
                }
            }
        }
    }
    // printDP(dp);
    // printDP(dpk);
    cout << "groups " << recursedpk(dpk, ar, 0, N-2) << "\n";
    return dp[0][N-2];
}

int main()
{
    vi ar {10, 30, 5, 10, 12, 45, 2};
    vi ar2 {10, 20, 30, 40, 30};
    cout << sMCM(ar2) << '\n';
    return 0;
}