// imdb is for nubs, we use rotten tomatoes

#include <bits/stdc++.h>
using namespace std;

using pie = pair<int, int>;
using vii = vector<pie>;
using vi = vector<int>;
using vvi = vector<vi>;

// { 1, 1, 0, 0, 0 },
// { 0, 1, 0, 0, 1 },
// { 1, 0, 0, 1, 1 },
// { 0, 0, 0, 0, 0 },
// { 1, 0, 1, 0, 1 }


void spread(vvi& dp, int distance, int i, int j) {
    if (i < 0 || i >= dp.size() || j < 0 || j >= dp[0].size() || dp[i][j] < distance)
        return;
    dp[i][j] = distance;
    spread(dp, distance + 1, i - 1, j);
    spread(dp, distance + 1, i, j - 1);
    spread(dp, distance + 1, i + 1, j);
    spread(dp, distance + 1, i, j + 1);
}

int noOfDays(vvi& tomatoes) { // n^3
    vvi dp(tomatoes.size(), vector<int>(tomatoes[0].size(), INT_MAX));
    int result = 0;

    for (int i = 0; i < tomatoes.size(); ++i)
    {
        for (int j = 0; j < tomatoes[0].size(); ++j) {
            if (tomatoes[i][j] == 1) {
                dp[i][j] = 0;
                spread(dp, 1, i - 1, j);
                spread(dp, 1, i, j - 1);
                spread(dp, 1, i + 1, j);
                spread(dp, 1, i, j + 1);
            }
        }
    }

    for (int i = 0; i < tomatoes.size(); ++i)
    {
        for (int j = 0; j < tomatoes[0].size(); ++j)
        {
            result = max(result, dp[i][j]);
        }
    }

    return result;
}


int noOfDaysBfs(vvi& tomatoes) { // n^2
    queue<pie> q;

    vector<bool> visited(tomatoes.size() * tomatoes[0].size(), false);

    for (int i = 0; i < tomatoes.size(); ++i)
        for (int j = 0; j < tomatoes[0].size(); ++j)
            if (tomatoes[i][j]) {
                q.push({i, j});
            }

    q.push({INT_MIN, INT_MIN});

    int distance = 0;
    while (!q.empty())
    {
        if (q.size() > 1 && q.front().first == INT_MIN)
        {
            q.push({INT_MIN, INT_MIN});
            distance++;
        }
        else if (q.front().first >= 0
            && q.front().first < tomatoes.size()
            && q.front().second >= 0
            && q.front().second < tomatoes[0].size()
            && !visited[q.front().first * tomatoes[0].size() + q.front().second])
        {
            // do something with q.front
            visited[q.front().first * tomatoes[0].size() + q.front().second] = true;

            q.push({q.front().first + 1, q.front().second});
            q.push({q.front().first - 1, q.front().second});
            q.push({q.front().first, q.front().second + 1});
            q.push({q.front().first, q.front().second - 1});
        }
        // cout << "popping " << q.front().first << ", " << q.front().second << "\n";
        q.pop();
    }

    return distance - 1;
}

struct node {
    int y, x, level;
};


int traverse(vvi tomatoes) {
    queue<node> q;
    int m = tomatoes.size();
    int n = tomatoes[0].size();
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            if (tomatoes[i][j] == 1)
                q.push({i, j, 0});
        }
    }
    int max_level = 0;
    while(!q.empty()) {
        node curr = q.front();
        int x = curr.x;
        int y = curr.y;
        int l = curr.level;
        // cout << "curr spreader " << x << " " << y << " " << l << "\n";
        bool found_fresh = false;

        // smart way - covering y+1,x y-1,x x+1,y and x-1,y via loop
        for (int i = -1; i <= 1; ++i)
        {
            for (int j = -1; j <= 1; ++j)
            {
                if (x + i >= 0
                 && x + i < n
                 && y + j >= 0
                 && y + j < m
                 && tomatoes[y + j][x + i] == 0)
                {
                    tomatoes[y + j][x + i] = 1;
                    q.push({y + j, x + i, l + 1});
                    found_fresh = true;
                }
            }
        }

        // naive way
        // if (x < n-1 && tomatoes[y][x+1] == 0) {
        //     tomatoes[y][x+1] = 1;
        //     q.push({y, x+1, l+1});
        //     found_fresh = true;
        // }
        // if (x > 0 && tomatoes[y][x-1] == 0) {
        //     tomatoes[y][x-1] = 1;
        //     q.push({y, x-1, l+1});
        //     found_fresh = true;
        // }
        // if (y < m-1 && tomatoes[y+1][x] == 0) {
        //     tomatoes[y+1][x] = 1;
        //     q.push({y+1, x, l+1});
        //     found_fresh = true;
        // }
        // if (y > 0 && tomatoes[y-1][x] == 0) {
        //     tomatoes[y-1][x] = 1;
        //     q.push({y-1, x, l+1});
        //     found_fresh = true;
        // }

        if (found_fresh)
            max_level = max(max_level, l+1);
        q.pop();
    }
    return max_level;
}

int main() {
    vvi basket = { { 1, 1, 0, 0, 0 },
                   { 0, 1, 0, 0, 1 },
                   { 1, 0, 0, 1, 1 },
                   { 0, 0, 0, 0, 0 },
                   { 1, 0, 1, 0, 1 } };

    vvi basket2 = {{1, 1, 0, 0, 0},
                  {0, 0, 0, 0, 1},
                  {0, 0, 0, 1, 1},
                  {0, 0, 0, 0, 0},
                  {0, 0, 0, 0, 1}};

    cout << noOfDaysBfs(basket2) << " days needed.\n";
}

//   0  1  2  3  4
// { 0, 0, 0, 0, 0 } 0
// { 0, 1, 0, 1, 0 } 1
// { 0, 0, 1, 0, 1 } 2
// { 1, 0, 0, 1, 0 } 3
// { 0, 1, 1, 0, 0 } 4

// q = (2, 3), (), (), (), ()

