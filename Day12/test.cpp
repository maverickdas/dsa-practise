// Kadane's algorithm

#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
using vii = vector<pii>;
using vi = vector<int>;
using vvi = vector<vi>;

// 1, -6,  4, 2, -4, 3, -7, 8, -2, 12


// 1, -5, -1, 1, -3, 0, -7, 1, -1, 11

// 1

int max_sum(vi nums) {
    int N = nums.size();
    int max = INT_MIN;
    int min = INT_MAX;
    vi sums_arr;
    sums_arr[0] = nums[0];
    for (int i=1; i<N; i++) {
        int curr_sum = sums_arr[i-1] + nums[i];
        sums_arr[i] = curr_sum;
        if (curr_sum > max) {
            max = curr_sum;
        }
        else if (curr_sum < min) {
            min = curr_sum;
        }
    }

}