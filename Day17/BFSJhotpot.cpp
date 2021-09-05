#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
using vii = vector<pii>;
using vi = vector<int>;
using vvi = vector<vi>;

// print min dist from src to all points. All weights are one. Undirected graph.
void bfs(vector<int> adj[], int N, int src)
{
    vector<bool> visited(N, false);
    queue<pair<int, int>> q;

    auto visit = [](vector<bool> &visited, int i, int value)
    {
        visited[i] = true;
        cout << "dist(" << i << ") : " << value << ", ";
    };

    q.push({src, 0});
    visit(visited, src, 0);

    while (!q.empty())
    {
        int v = q.front().first;
        int score = q.front().second;
        q.pop();

        for (auto &el : adj[v])
        {
            if (el != v && !visited[el])
            {
                q.push({el, score + 1});
                visit(visited, el, score + 1);
            }
        }
    }

    cout << "\n";
}

// print min dist from src to all points. All weights are one. Undirected graph.
// *Conditions apply.
void sbfs(vi adj[], int N, int src)
{
    queue<pii> q;
    q.push({src, 0});
    vi vis(N, 0);
    vis[src] = 1;
    while (!q.empty())
    {
        int u = q.front().first;
        int cost = q.front().second;
        cout << "cost at " << u << " " << cost << ", ";
        q.pop();

        for (auto &v : adj[u])
        {
            if (u != v && vis[v]!=1)
            {
                q.push({v, cost + 1});
                vis[v] = 1;
            }
        }
    }
    cout << "\n";
}

int main()
{
    const int N = 11;
    vi adj[N]{{1},
              {0, 1, 2, 7},
              {1, 3, 4},
              {2, 4, 6, 7},
              {2, 3, 5},
              {4},
              {3},
              {1, 3, 8, 9, 10},
              {7},
              {7},
              {7}};

    // cout << bfs(adj, N, 1, 10) << '\n';
    bfs(adj, N, 1);
    sbfs(adj, N, 1);
    return 0;
}