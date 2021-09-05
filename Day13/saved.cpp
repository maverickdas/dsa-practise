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


int dfs(vvi &mat, int i, int j) {
    if (mat[i][j] == 0)
        return 0;
    mat[i][j] = 0;
    return dfs(mat, i+1, j) + dfs(mat, i, j+1) + dfs(mat, i, j-1) + dfs(mat, i-1, j);
}

int numIslands(vvi& mat)
{
    int m = mat.size();
    int n = mat[0].size();
    // vector<vector<bool>> visited (m, vector<bool> (n, false));
    int count = 0;
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            int curr = mat[i][j];
            int size = 0;
            if (curr == 1) {
                size = dfs(mat, i, j);
                count ++;
            }
        cout << "\n";
        printMat(mat);
        }
    }

    return count;
}

int main()
{
    vvi ocean =  { { 1, 1, 0, 0, 0 },
                   { 0, 1, 0, 0, 1 },
                   { 1, 0, 0, 1, 1 },
                   { 0, 0, 0, 0, 0 },
                   { 1, 0, 1, 0, 1 } };
    cout << numIslands(ocean) << "\n";
    // printMat(ocean);
    return 0;
}