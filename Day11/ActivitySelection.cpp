#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
using vii = vector<pii>;
using vi = vector<int>;
using vvi = vector<vector<int>>;

// (4, 6, 30), (1, 3, 10), (2, 8, 20), (7, 8, 40), (4, 7, 20), (5, 10, 50)

struct Meeting
{
    int start, end, profit;
};
inline void printPair(Meeting pairv){
    cout << "(" << pairv.start << ", " << pairv.end << ", " << pairv.profit << ") ";
}
void printPairVector(vector<Meeting> pairvc) {
    for (auto &i: pairvc) {
        printPair(i);
    }
    cout << '\n';
}



int meetingsMaxInADay(vector<Meeting> meets) {
    // N^2 approach
    sort(meets.begin(), meets.end(), [](Meeting first, Meeting second) {
        return first.start < second.start;
    });
    cout << "sorted ";
    printPairVector(meets);
    cout << "\n";

    vi dp(meets.size(), 0);
    vi dp_profit(meets.size(), 0);
    for (int i=0; i<meets.size(); i++) {
        int maxv = 1;
        int max_profits = 0;
        int max_end_time = 0;

        cout << "looking for meetings upto ";
        printPair(meets[i]);
        cout << "\n";

        for (int j=0; j<i; j++) {
            int new_max = 1 + dp[j];
            int new_max_profits = dp_profit[j] + meets[i].profit;
            int new_max_end_time = max(max_end_time, meets[j].end);
            if (
                new_max > maxv &&
                new_max_profits > max_profits &&
                meets[i].end > meets[j].end &&
                meets[i].start >= new_max_end_time
                ) {
                    maxv = new_max;
                    max_end_time = new_max_end_time;
                    max_profits = new_max_profits;
                    cout << "accounting meeting ";
                    printPair(meets[j]);
                    cout << " curr max profits " << max_profits << "\n";
            }
        }
        dp[i] = maxv;
        dp_profit[i] = max_profits;
    }
    return *max_element(dp_profit.begin(), dp_profit.end());
}

int maxActivity(vii meets) {
    sort(meets.begin(), meets.end(), [](pii &a, pii &b)
         { return a.second != b.second ? a.second < b.second : a.first > b.first; });

    auto clashes = [](pii a, pii b)
    {
        return b.first < a.second;
    };

    int result = 1;
    pii index = meets[0];
    cout << "(" << index.first << ", " << index.second << ")\n";
    for (int i = 1; i < meets.size(); ++i)
    {
        if (meets[i].first >= index.second)
        {
            ++result;
            index = meets[i];
            cout << "(" << index.first << ", " << index.second << ")\n";
        }
    }

    return result;
}



int main()
{
    vector<Meeting> meetings {{ 0, 6, 60 },
                     { 1, 4, 30 },
                     { 3, 5, 10 },
                     { 5, 7, 30 },
                     { 5, 9, 50 },
                     { 7, 8, 10 }};



    // vii meets{{1, 4}, {3, 5}, {0, 6}, {5, 7}, {3, 8}, {5, 9}, {6, 10}, {8, 11}, {8, 12}, {2, 13}, {12, 14}};
    // cout << maxActivity(meets) << '\n';
    cout << meetingsMaxInADay(meetings) << "\n";
    return 0;
}