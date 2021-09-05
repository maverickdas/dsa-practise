#include <vector>
#include <queue>
#include <iostream>

using namespace std;

// 0 1 2 3 4 5 6 7
// 8 9 10..
//             ..63

int minMoves(int src, int dst, int size)
{
    vector<bool> visited(size * size, false);

    auto possible = [](int n)
    {
        vector<pair<int, int>> p;

        int i = n / 8;
        int j = n % 8;

        p.push_back({i - 2, j + 1});p.push_back({i - 1, j + 2});
        p.push_back({i - 2, j - 1});p.push_back({i - 1, j - 2});
        p.push_back({i + 2, j + 1});p.push_back({i + 1, j + 2});
        p.push_back({i + 2, j - 1});p.push_back({i + 1, j - 2});

        vector<int> res;
        for (auto el: p)
            if (el.first >= 0 && el.first < 8 && el.second >= 0 && el.second < 8)
                res.push_back(el.first * 8 + el.second);
        return res;
    };

    int dist = 0;
    queue<int> q;
    q.push(src);
    visited[src] = true;

    while(!q.empty())
    {
        q.push(-1);
        while(q.front() != -1)
        {
            int front = q.front();
            q.pop();

            if (front == dst)
                return dist;

            for (auto el: possible(front))
            {
                if (!visited[front])
                {
                    q.push(el);
                    visited[el] = true;
                }
            }
        }
        q.pop();

        ++dist;
    }

    return -1;
}

int main()
{
    cout << minMoves(0, 1, 64) << '\n';
    cout << minMoves(19, 36, 64) << '\n';
    cout << minMoves(31, 31, 64) << '\n';
    cout << minMoves(0, 60, 64) << '\n';
    return 0;
}