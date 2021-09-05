// Kadane's algorithm

#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
using vii = vector<pii>;
using vi = vector<int>;
using vvi = vector<vi>;

// -4, -1, 4, 2, -4, 3, -7, 7

// min = -4
// -1, 3
// 4, 8
// 2, 6
// -4, 0
// 3, 7
// -7, 11, min = -7
// 7, 14

//
// -4, -5, -1, 1, -3, 0, -7, 0
// 0   0  0  3   4  5   6  7   8
// 1   1  1
// -7 -5 -1 -1 0 1 1 1


int maxSum(vector<int> ar) {
    // Comment of shame
    // Temporary cumil sum till it becomes negative
    // donnt carry -ve burden to next sum

    // vector<pair<int, int>> t(ar.size(), {0, 0});

    // t[0] = {ar[0], 0};

    // for (int i = 1; i < ar.size(); ++i)
    // {
    //     t[i] = {ar[i] + t[i - 1].first, i};
    // }

    int result = ar[0], temp = ar[0];
    int left = 0, right = 0;

    for (int i = 1; i < ar.size(); ++i) {
        if (temp < 0)
        {
            temp = 0;
            left = i;
        }
        temp += ar[i];
        if (result < temp)
        {
            result = temp;
            right = i;
        }
    }

    cout << "Pair: (" << left << ", " << right << ")\n";

    return result;
}


int main()
{
    cout << "sen3.14\n";
    cout << maxSum({-4, -1, 4, 2, -4, 3, -7, 7}) << "\n";
    cout << maxSum({1, -6,  4, 2, -4, 3, -7, 8, -2, 12}) << '\n';
    return 0;
}