#include <queue>
#include <climits>
#include <iostream>

using namespace std;

using pii = pair<int, int>;
using vii = vector<pii>;
using vi = vector<int>;
using vvi = vector<vi>;


void printDP(int dp[], int N, string user) {
    cout << user << "\n";
    for (int i = 0; i < N; ++i)
    {
        cout << i << "->" << (dp[i] == INT_MAX ? -1 : dp[i]) << ", ";
    }
}


int bfs2(vi adj[], int N, int source, int dest)
{
    queue<pii> q;
    q.push({source, 0});

    bool vis[N] {false};
    vis[source] = true;

    while (!q.empty())
    {
        int u = q.front().first;
        int cost = q.front().second;

        if (u == dest)
            return cost;

        q.pop();
        for (int& v : adj[u])
        {
            if (vis[v])
                continue;
            vis[v] = true;
            q.push({v, 1 + cost});
        }
    }
    return -1;
}

int bfs(vii adj[], int N, int source, int dest)
{
    int dp[N];
    fill(dp, dp + N, INT_MAX);
    dp[source] = 0;

    queue<int> q;
    q.push(source);

    while (!q.empty())
    {
        int u = q.front();

        q.pop();

        for (auto &el: adj[u]) {
            int v = el.first;
            int wt = el.second;

            if (u != v && wt + dp[u] < dp[v])
            {
                dp[v] = wt + dp[u];
                cout << v << "\n";
                q.push(v);
            }
        }
    }
    printDP(dp, N, "sen3.14");
    return dp[dest];
}

int sbfs(vii adj[], int N, int source, int dest)
{
    int dp[N];
    fill(dp, dp + N, INT_MAX);
    dp[source] = 0;

    queue<int> q;
    q.push(source);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto &n: adj[u]) {
            int v = n.first;
            int costv = n.second;
            // only consider neighbors if projected weight to v is less than recorded v
            if (u!=v && dp[u] + costv < dp[v]) {
                dp[v] = dp[u]+costv;
                q.push(v);
            }
        }
    }
    printDP(dp, N, "shantipriyo");
    return dp[dest];
}



int main()
{
    const int N = 11;
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
    cout << bfs(adj2, N, 1, 10) << '\n';
    cout << sbfs(adj, N, 1, 10) << '\n';
    cout << sbfs(adj2, N, 1, 10) << '\n';
    return 0;
}