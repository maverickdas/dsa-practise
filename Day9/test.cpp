#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
using vii = vector<pii>;
using vvi = vector<vector<int>>;

void printDP(vector<vector<int>> &dp, string &s1, string &s2)
{
    cout << "  ";
    for (char ch : s1)
        cout << ch << ' ';
    cout << '\n';
    int count = 0;
    for (const auto &i : dp)
    {
        cout << s2[count++] << ' ';
        for (const auto &j : i)
            cout << j << ' ';
        cout << '\n';
    }
}

void printDP(vector<int>& vec)
{
    for(auto &i: vec)
        std::cout << i << ' ';
    std::cout << '\n';
}

int senpilcs(string &s1, string &s2)
{
    int result = 0;
    vector<vector<int>> dp(s2.size(), vector<int>(s1.size() + 1, 0)); // 0
    for (int i = 0; i < s1.size(); ++i)
    {
        int max = 0;
        for (int j = 0; j < s2.size(); ++j)
        {
            if (s1[i] == s2[j])
            {
                dp[j][i] = max + 1;
                dp[j][s1.size()] = dp[j][s1.size()] < dp[j][i] ? dp[j][i] : dp[j][s1.size()];
                result = result < dp[j][i] ? dp[j][i] : result;
            }
            if (max < dp[j][s1.size()])
            {
                max = dp[j][s1.size()];
            }
        }
    }
    // printDP(dp, s1, s2);
    return result;
}

int lcs(string &s1, string &s2)
{
    int m = s1.length();
    int n = s2.length();
    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
    {
        dp[i][0] = 0;
        for (int j = 0; j <= n; j++)
            dp[0][j] = 0;
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    // printDP(dp, s1, s2);
    return dp[m][n];
}

int slcs(string s1) {
    int m = s1.length();
    int dp[m+1][m+1];

    for (int i = 0; i <= m; i++)
    {
        dp[i][0] = 0;
        for (int j = 0; j <= m; j++)
            dp[0][j] = 0;
    }

    for (int i=1; i<=m; i++) {
        for (int j=1; j<=m; j++) {
            int ri = m+1-j+1;
            if (s1[i-1] == s1[ri-1]) {
                dp[i][ri] = dp[i-1][ri-1] + 1;
            } else {
                dp[i][ri] = max(dp[i-1][ri], dp[i][ri-1]);
            }

        }
    }
    return dp[m][m];
}


int stackboxes(vvi boxes) {
    int n = boxes.size();
    vector<int> dp (n);
    vector<set<int>> seen (n);

    vvi areas (3*n, vector<int> (3));
    for (int i=0; i<n; i++) {
        areas[3*i] =   {i, boxes[i][0]*boxes[i][1], boxes[i][2], boxes[i][0], boxes[i][1]};
        areas[3*i+1] = {i, boxes[i][1]*boxes[i][2], boxes[i][0], boxes[i][1], boxes[i][2]};
        areas[3*i+2] = {i, boxes[i][2]*boxes[i][0], boxes[i][1], boxes[i][2], boxes[i][0]};
    }

    sort(areas.begin(), areas.end(), [](vector<int>& a, vector<int>& b) {
        return a[1] > b[1];
    });
    cout << "calc areas\n";
    for (int i=0; i<3*n; i++) {
        int max_height = 0;
        set<int> seen_i;
        vector<int> area_i = areas[i];
        int box_i = area_i[0];

        cout << "calc for box i " << box_i << "   ";
        printDP(boxes[box_i]);

        for (int j=0; j<i; j++) {
            vector<int> area_j = areas[j];
            int box_j = area_j[0];

            cout << "calc for box j " << box_j << "   ";
            printDP(boxes[box_j]);

            int new_max_height = dp[j] + area_i[2];
            if (box_i != box_j &&
                max(area_i[3], area_i[4]) < max(area_j[3], area_j[4]) &&
                min(area_i[3], area_i[4]) < min(area_j[3], area_j[4]) &&
                seen_i.count(box_j) == 0 &&
                new_max_height > max_height) {
                    cout << "adding box_j " << box_j << " to box_i " << box_i << "\n";
                    max_height = new_max_height;
                    seen_i = seen[j];
                }
            dp[i] = max_height;
            seen_i.insert(i);
            seen[i] = seen_i;
        }
    }
}

int main()
{
    // string s1 = "boobameahbooba";
    // string s2 = "aboobhaemaboob";
    // cout << lcs(s1, s2) << '\n';
    // cout << senpilcs(s1, s2) << '\n';

    vvi boxes{{4, 6, 7},
              {1, 2, 3},
              {4, 5, 6},
              {10, 12, 32}};

    vvi boxes2{{4, 6, 7},
              {1, 2, 3},
              {4, 5, 6},
              {10, 12, 32},
              {3, 6, 8},
              {6, 5, 6}};

    stackboxes(boxes);
    return 0;
}
