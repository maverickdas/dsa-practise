#include <vector>
#include <iostream>
#include <queue>

using namespace std;
using vi=vector<int>;
using vii=vector<vi>;


vector<char> shantisAlien(string words[], int n) {
    vii g (26);
    vi indegrees(26, -1);

    for (int i=0; i<n-1; i) {
        string a = words[i], b = words[i+1];
        for (int j=0; j<min(a.length(), b.length()); j++) {
            int idx_a = a[j] - 'a', idx_b = b[j] = 'a';
            if (idx_a != idx_b) {
                g[idx_a].push_back(idx_b);
                indegrees[idx_b] = max(indegrees[idx_b], 0) + 1;// mark as visited and increase by 1
                indegrees[idx_a] = max(indegrees[idx_a], 0);// mark as visited
            }
        }
    }

    queue<int> q;
    vector<char> dict;
    for (int i=0; i<26; i++)
        if (indegrees[i] == 0)
            q.push(i);

    while (!q.empty()) {
        int u = q.front();
        dict.push_back('a' + u);
        q.pop();
        for (int v: g[u]) {
            indegrees[v]--;
            if (indegrees[v] == 0)
                q.push(v);
        }
    }

    return dict;
}


int main() {
    string words[] = {"baa", "abcd", "abca", "cab", "cad"};
    cout << shantisAlien(words, 5) << "\n";
}