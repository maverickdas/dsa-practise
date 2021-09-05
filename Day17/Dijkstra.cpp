#include <bits/stdc++.h>
#include <queue>

using namespace std;

using pii = pair<int, int>;
using vii = vector<pii>;
using vi = vector<int>;
using vvi = vector<vi>;

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

/*  NOTES
    1. Dijkstra (bfs + pqueue) > bellman ford ?
        bc, for bellman ford, multiple passes + updates is needed.
        BFS + pqueue (to order children v or u) needs just one greedy pass
    2. Dijkstra is BFS + ordered traversal of children
*/

void dj_wale_babu(vii adj[], int N, int src)
{
    priority_queue<pii, vii, greater<pii> > pq;

    pq.push({0, src});

    bool vis[N] {false};

    while (!pq.empty())
    {
        int u = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        // handling parallel edges
        if (vis[u])
            continue;
        vis[u] = true;

        cout << u << ": " << cost << '\n';

        for (auto& el : adj[u])
        {
            int v = el.first;
            int wt = el.second;

            if (!vis[v])
                pq.push({cost + wt, v});
        }
    }
}

int main()
{
    const int N = 11;
    //biased grapsh
    vii adj[N] { { {1, 1} },
                 { {0, 1}, {1, 0}, {2, 3}, {7, 9} },
                 { {1, 3}, {3, 1}, {4, 2} },
                 { {2, 1}, {4, 2}, {6, 3}, {7, 4} },
                 { {2, 2}, {3, 2}, {5, 1} },
                 { {4, 1} },
                 { {3, 3} },
                 { {1, 9}, {3, 4}, {8, 4}, {9, 5}, {10, 4} },
                 { {7, 4} },
                 { {7, 5} },
                 { {7, 4} }
    };

    vii adj2[N]{ { {1, 1} },
                 { {0, 1}, {1, 0}, {2, 3}, {7, 5} },
                 { {1, 3}, {3, 3}, {4, 2} },
                 { {2, 3}, {4, 2}, {6, 3}, {7, -2} },
                 { {2, 2}, {3, 2}, {5, 1} },
                 { {4, 1} },
                 { {3, 3} },
                 { {1, 5}, {3, -2}, {8, 4}, {9, 5}, {10, 4} },
                 { {7, 4} },
                 { {7, 5} },
                 { {7, 4} }
    };

    // cout << bfs(adj, N, 1, 10) << '\n';
    dj_wale_babu(adj, N, 1);
    cout << "\nRoll # 21:\n\n";
    dj_wale_babu(adj2, N, 1);
    // cout << sbfs(adj, N, 1, 10) << '\n';
    // cout << sbfs(adj2, N, 1, 10) << '\n';
    return 0;
}