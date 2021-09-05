#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
using vii = vector<pii>;
using vi = vector<int>;
using vvi = vector<vi>;


// 1 for land
// 0 for water

void printMat(vvi& mat)
{
    for(auto& row: mat)
    {
        for(auto& el: row)
            std::cout << el << ' ';
        std::cout << '\n';
    }
}

// 0 1 2 3 4 5
// 0 1 0 0 0 1
// 0 0 0 0 0 0

// 0,0 1,1 0,2 0,4 1,5

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


int main()
{
    vvi basket = { { 1, 1, 0, 0, 0 },
                   { 0, 0, 0, 0, 1 },
                   { 0, 0, 0, 1, 1 },
                   { 0, 0, 0, 0, 0 },
                   { 0, 0, 0, 0, 1 } };
    cout << traverse(basket) << "\n";
    // printMat(ocean);
    return 0;
}