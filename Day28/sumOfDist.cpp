// LC834

#include <vector>
#include <climits>
#include <queue>

using namespace std;

vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &adj)
{
    vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

    for (int i = 0; i < n; ++i)
    {
        dp[i][i] = 0;
    }

    auto visited = [dp](int i, int j)
    {
        return dp[i][j] != INT_MAX;
    };

    int dist = 1;

    queue<int> q;
    q.push(0);

    while(!q.empty())
    {
        q.push(-1);

        while(q.front() != -1)
        {
            int front = q.front();
            q.pop();

            for (auto &el: adj[front])
            {
                // 0 - el = dist

                q.push(el);
            }
        }

        ++dist;
    }
}