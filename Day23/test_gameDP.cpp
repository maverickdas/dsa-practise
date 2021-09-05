#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// int maxFirstPlayerScore(vi ar) {
//     vi dp[]
// }


using pii=pair<int,int>;
using vi=vector<int>;

pii maxPossibleScores(vi ar) {
    int N = ar.size();
    vector<vector<pii>> dp(N, vector<pii>(N));

    for (int i=0; i<N; i++)
        dp[i][i] = {ar[i], 0};

    for (int s=2; s<=N; s++) {
        for (int i=0; i+s<=N; i++) {
            int j = i + s - 1;
            if (ar[i] + dp[i+1][j].second > ar[j] + dp[i][j-1].second) {
                dp[i][j] = {
                    ar[i] + dp[i+1][j].second, dp[i+1][j].first
                };
            }
            else {
                dp[i][j] = {
                    ar[j] + dp[i][j-1].second, dp[i][j-1].first
                };
            }
        }
    }
    cout << dp[0][N-1].first << " " << dp[0][N-1].second << "\n";
    return dp[0][N-1];
}

int main()
{
    vi ar {4, 8, 5, 3, 5, 18, 9};
    pair<int, int> result = maxPossibleScores(ar);
    cout << result.first << ' ' << result.second << '\n';
    return 0;
}

// 3 5

// sss -> 4 5 18 3 = 30
// shanti -> 8 9 5 = 22s