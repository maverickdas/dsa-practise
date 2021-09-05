#include <vector>
#include <queue>
#include <iostream>

// 0 1 2 3 4 5 6 7
// 8 9 10..
//             ..63
using namespace std;
using pii=pair<int,int>;
using vi=vector<int>;
using vvi=vector<vi>;

int sDistViaObstacles(vvi mat) {
    int m = mat.size(), n = mat[0].size();
    pii src = {0,0};
    pii dst = {m-1, n-1};

    int dist = 0;
    vvi broken (m, vi(n, 0));
    vvi visited (m, vi(n, 0));
    queue<vi> q;
    q.push({src.first, src.second, 0});

    while (!q.empty()) {
        q.push({-1, -1, -1});
        while(q.front()[2] != -1) {
            vi u = q.front();
            q.pop();

            if (u[0] == dst.first && u[1] == dst.second)
                return dist;

            vector<pii> nexts = {
                {u[0]+1, u[1]}, {u[0], u[1]+1},
                {u[0]-1, u[1]}, {u[0], u[1]-1}
            };
            for (auto next: nexts) {
                if (next.first < 0 || next.first >= m || next.second < 0 || next.second >= n)
                    continue;
                int v_val = mat[next.first][next.second];
                int v_vis = visited[next.first][next.second];
                if (v_val == 0 && !v_vis) {
                    q.push({next.first, next.second, u[2]});
                    visited[next.first][next.second] = 1;
                }
                else if (v_val == 1) {
                    // if (u[2] == 1) {
                    //     ;// ignored
                    // }
                    if (u[2] == 0) {
                        if (!v_vis) {
                            q.push({next.first, next.second, 1}); // break wall
                            broken[next.first][next.second] = 1;
                            visited[next.first][next.second] = 1;
                        }
                        else if (v_vis && !broken[next.first][next.second] == 0) {
                            q.push({next.first, next.second, 1});
                            broken[next.first][next.second] = 1;
                            visited[next.first][next.second] = 1;
                        }
                        // else if (v_vis && broken[next.first][next.second] == 0) {
                        //      ;//ignored
                        // }
                    }
                }
            }
        }
        q.pop();
        dist++;
    }
    return -1;
}



int main()
{
    vector<vector<int> > map = { {0, 0, 0, 0, 0, 0},
                                 {1, 1, 1, 1, 1, 0},
                                 {0, 0, 0, 0, 0, 0},
                                 {0, 1, 1, 1, 1, 1},
                                 {0, 1, 1, 1, 1, 1},
                                 {0, 0, 0, 0, 0, 0} };

    vector<vector<int> > map2 = { {0, 1, 1, 0},
                                  {0, 0, 0, 1},
                                  {1, 1, 0, 0},
                                  {1, 1, 1, 0} };

    vector<vector<int>> map3 ={{0, 0, 0, 0, 0, 0},
                               {1, 1, 1, 1, 1, 1},
                               {0, 0, 1, 1, 0, 0},
                               {1, 0, 0, 1, 1, 0},
                               {0, 1, 1, 1, 1, 0},
                               {0, 0, 0, 0, 0, 0}};

    cout << sDistViaObstacles(map) << '\n';
    cout << sDistViaObstacles(map2) << '\n';
    cout << sDistViaObstacles(map3) << '\n';
    return 0;
}