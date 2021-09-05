#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
using vii = vector<pii>;
using vi = vector<int>;
using vvi = vector<vi>;

// 1 for land
// 0 for water

int recIslandArea(vvi &mat, int i, int j)
{
    if (i < 0 || i >= mat.size()
     || j < 0 || j >= mat[0].size()
     || mat[i][j] == 0) {
        return 0;
    }

    mat[i][j] = 0;

    return 1 + recIslandArea(mat, i, j + 1) + recIslandArea(mat, i + 1, j) + recIslandArea(mat, i - 1, j) + recIslandArea(mat, i, j - 1);
}
void dfs(vvi &mat, int i, int j) {
    if (i < 0 || i >= mat.size() || j < 0 || j >= mat[0].size())
        return;
    if (mat[i][j] == 0)
        return;
    mat[i][j] = 0;

    dfs(mat, i+1, j);
    dfs(mat, i, j+1);
    dfs(mat, i, j-1);
    dfs(mat, i-1, j);
}
int numIslands_2(vvi& mat)
{
    int m = mat.size();
    int n = mat[0].size();
    int count = 0;
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) {
            int curr = mat[i][j];
            if (curr == 1) {
                dfs(mat, i, j);
                count ++;
            }
        }
    }

    return count;
}

int numIslands(vvi &mat)
{
    int result = 0;
    for (int i = 0; i < mat.size(); ++i)
    {
        for (int j = 0; j < mat[0].size(); ++j) {
            if (mat[i][j] == 1) {
                cout << (result+1) << ") Island of area: " << recIslandArea(mat, i, j) << " containing (" << i << "," << j << ")\n";
                result++;
            }
        }
    }

    return result;
}

int main() {
    vvi ocean =  { { 1, 1, 0, 0, 0 },
                   { 0, 1, 0, 0, 1 },
                   { 1, 0, 0, 1, 1 },
                   { 0, 0, 0, 0, 0 },
                   { 1, 0, 1, 0, 1 } };

    cout << numIslands(ocean) << " islands found.\n";
}