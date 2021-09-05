// LC83
#include <vector>
#include <climits>
#include <queue>

using namespace std;

// void bfs(adj, ) {

// }

vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj (n);
        vector<vector<int>> sumsDp(n, vector<int> (n, 0));
        for (int i=0; i<n; i++)
            sumsDp[i][i] = 0;

        for (auto &edge: edges) {
            adj[edge[0]].push_back(edge[1]);
        }

        queue<int> q;
        q.push(0);
        while(!q.empty()) {
            int u = q.front();

        }

    }