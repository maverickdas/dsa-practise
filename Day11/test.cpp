#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
using vii = vector<pii>;
using vi = vector<int>;
using vvi = vector<vi>;


/*
 {1, 4}, {3, 5}, {0, 6}, {5, 7},
 {3, 8}, {5, 9}, {6, 10}, {8, 11},
 {8, 12}, {2, 13}, {12, 14}
*/


// answer = (1, 4), (5, 7), (8, 11), (12, 14)

inline void printPair(pii pairv){
    cout << "(" << pairv.first << ", " << pairv.second << ") ";
}
void printPairVector(vii pairvc) {
    for (auto &i: pairvc) {
        printPair(i);
    }
    cout << '\n';
}

int meetingsMaxInADay(vii meets) {
    sort(meets.begin(), meets.end(), [](pii first, pii second) {
        return first.first < second.first;
    });
    cout << "sorted ";
    printPairVector(meets);
    cout << "\n";

    vi dp(meets.size(), 0);
    for (int i=0; i<meets.size(); i++) {
        int maxv = 1;
        int max_end_time = 0;

        cout << "looking for meetings upto ";
        printPair(meets[i]);
        cout << "\n";

        for (int j=0; j<i; j++) {
            int new_max = 1 + dp[j];
            int new_max_end_time = max(max_end_time, meets[j].second);
            if (new_max > maxv &&
                meets[i].second > meets[j].second &&
                meets[i].first >= new_max_end_time) {
                    maxv = new_max;
                    max_end_time = new_max_end_time;
                    cout << "accounting meeting ";
                    printPair(meets[j]);
                    cout << " curr max " << maxv << " curr maxend " << max_end_time << "\n";
            }
        }
        dp[i] = maxv;
    }
    return *max_element(dp.begin(), dp.end());
}

int main()
{
    vii meets {{1, 4}, {3, 5}, {0, 6}, {5, 7},
               {3, 8}, {5, 9}, {6, 10}, {8, 11},
               {8, 12}, {2, 13}, {12, 14}};
    cout << meetingsMaxInADay(meets) << '\n';
    return 0;
}


