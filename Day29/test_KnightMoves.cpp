#include <vector>
#include <queue>
#include <iostream>

// 0 1 2 3 4 5 6 7
// 8 9 10..
//             ..63
using namespace std;
using pii=pair<int,int>;

int sMinMoves(int src, int dst)
{
    pii src_p = {src/8, src%8};
    pii dst_p = {dst/8, dst%8};
    queue<pii> q;
    q.push(src_p);

    vector<pair<int, int>> moves = {{+2, -1}, {+2, +1}, {-2, -1}, {-2, +1},
                                    {-1, +2}, {+1, +2}, {+1, -2}, {-1, -2}};
    int n_moves = 0;

    while(!q.empty()) {
        q.push({-1, -1});
        while(q.front().first != -1) {
            pii u = q.front();
            q.pop();
            if (u == dst_p)
                return n_moves;

            for (pair<int,int> move: moves) {
                int ni = u.first + move.first;
                int nj = u.second + move.second;
                if (ni < 8 && ni > -1 && nj < 8 && nj > -1)
                    q.push({ni, nj});
            }
        }
        q.pop();
        n_moves++;
    }
    return -1;
}



int main()
{
    cout << sMinMoves(0, 1) << '\n';
    cout << sMinMoves(19, 36) << '\n';
    cout << sMinMoves(31, 31) << '\n';
    cout << sMinMoves(0, 60) << '\n';
    return 0;
}