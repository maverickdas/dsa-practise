#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
using vii = vector<pii>;
using vvi = vector<vector<int>>;

// (2, 3, 5), (1, 6, 9), (4, 2, 5), (7, 3, 9)

void printAR(vvi ar, vvi boxes) {
    for (int i = 0; i < ar.size(); ++i) {
        cout << "Area: " << ar[i][0];
        cout << " Box: #" << ar[i][1] << " (" << boxes[ar[i][1]][0] << "," << boxes[ar[i][1]][1] << "," << boxes[ar[i][1]][2] << ")";
        cout << " Height: " << boxes[ar[i][1]][ar[i][2]];
        cout << "\n";
    }
}

void printDP(vector<pair<int, set<int>>> dp)
{
    cout << "DP:- \n";
    for (auto &el: dp) {
        cout << el.first << " - Boxes: ";
        for (auto &el2: el.second) {
            cout << el2 << " ";
        }
        cout << "\n";
    }
}

int senpaiStacker(vvi boxes)
{
    vector<vector<int>> ar;
    vector<pair<int, set<int>>> dp;
    int result = 0;

    for (int i = 0; i < boxes.size(); ++i)
    {
        ar.push_back({boxes[i][1] * boxes[i][2], i, 0}); // area value
        ar.push_back({boxes[i][0] * boxes[i][2], i, 1}); // box index in main vec
        ar.push_back({boxes[i][0] * boxes[i][1], i, 2}); // height index in box
    }

    sort(ar.begin(), ar.end(), [](vector<int> &a, vector<int> &b)
         { return a[0] > b[0]; });

    auto isInside = [boxes](vector<int> a, vector<int> b)
    {
        int x1, y1, x2, y2, tmp;
        if (a[2] == 0)
        {
            x1 = boxes[a[1]][1];
            y1 = boxes[a[1]][2];
        }
        else if (a[2] == 1)
        {
            x1 = boxes[a[1]][0];
            y1 = boxes[a[1]][2];
        }
        else
        {
            x1 = boxes[a[1]][1];
            y1 = boxes[a[1]][0];
        }
        if (b[2] == 0)
        {
            x2 = boxes[b[1]][1];
            y2 = boxes[b[1]][2];
        }
        else if (b[2] == 1)
        {
            x2 = boxes[b[1]][0];
            y2 = boxes[b[1]][2];
        }
        else
        {
            x2 = boxes[b[1]][1];
            y2 = boxes[b[1]][0];
        }

        tmp = min(x1, y1);
        y1 = max(x1, y1);
        x1 = tmp;

        tmp = min(x2, y2);
        y2 = max(x2, y2);
        x2 = tmp;

        return x1 <= x2 && y1 <= y2;
    };

    for (int i = 0; i < ar.size(); ++i)
    {
        dp.push_back({0, {}});

        int considering = i;
        for (int j = 0; j < i; ++j)
        {
            if (dp[j].second.count(ar[i][1]) == 0 && dp[i].first <= dp[j].first && isInside(ar[i], ar[j]))
            {
                dp[i].first = dp[j].first;
                considering = j;
            }
        }
        dp[i].second = dp[considering].second;
        dp[i].second.insert(ar[i][1]);
        dp[i].first += boxes[ar[i][1]][ar[i][2]]; // append height for current area
        result = max(result, dp[i].first);
    }
    printAR(ar, boxes);
    printDP(dp);
    return result;
}

int main()
{
    vvi boxes2{{4, 6, 7},
              {1, 2, 3},
              {4, 5, 6},
              {10, 12, 32},
              {3, 6, 8},
              {6, 5, 6}};

    vvi boxes{{4, 6, 7},
               {1, 2, 3},
               {4, 5, 6},
               {10, 12, 32}};

    cout << "sen3.14\n";
    cout << senpaiStacker(boxes2) << '\n';

    return 0;
}