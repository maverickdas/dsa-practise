#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<int> adj[], int u, int csum[], int children[])
{
    children[u] = 0;
    csum[u] = 0;
    for (int v : adj[u])
    {
        if (v == u)
            continue;
        dfs(adj, v, csum, children);
        csum[u] += csum[v];
        children[u] += children[v] + 1;
    }
}

int dfs2(vector<int> adj[], int u, int csum[], int sum[])
{

}