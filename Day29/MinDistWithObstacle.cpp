// int[][] map = { {0, 0, 0, 0, 0, 0},
//                 {1, 1, 1, 1, 1, 0},
//                 {0, 0, 0, 0, 0, 0},
//                 {0, 1, 1, 1, 1, 1},
//                 {0, 1, 1, 1, 1, 1},
//                 {0, 0, 0, 0, 0, 0} };

// int[][] map2 = { {0, 1, 1, 0},
//                  {0, 0, 0, 1},
//                  {1, 1, 0, 0},
//                  {1, 1, 1, 0} };

#include <vector>
#include <iostream>
#include <queue>

using namespace std;


int solution(vector<vector<int>>& map)
{
    vector<vector<pair<bool, bool>>> visited (map.size(), vector<pair<bool, bool>>(map[0].size(), {false, false}));

    int dist = 0;

    queue<vector<int>> q;
    if (map[0][0] == 0)
    {
        q.push({0, 0, 0});
        visited[0][0] = {true, false};
    }
    else
    {
        q.push({0, 0, 1});
        visited[0][0] = {false, true};
    }


    while(!q.empty())
    {
        // cout << dist << "\n";
        q.push({-1, -1, -1});
        while (q.front()[0] != -1)
        {
            vector<int> front = q.front();
            q.pop();

            if (front[0] == map.size() - 1 && front[1] == map[0].size() - 1)
                return dist;

            vector<pair<int, int>> possible;
            possible.push_back({front[0] - 1, front[1]});
            possible.push_back({front[0] + 1, front[1]});
            possible.push_back({front[0], front[1] - 1});
            possible.push_back({front[0], front[1] + 1});

            for (auto el: possible)
            {
                if (el.first >= 0 && el.first < map.size() && el.second >= 0 && el.second < map[0].size())
                {
                    if (!map[el.first][el.second])
                    {
                        if (!visited[el.first][el.second].first)
                        {
                            // cout << "Normal " << el.first << "," << el.second << "\n";
                            q.push({el.first, el.second, 0});
                            if (front[2])
                                visited[el.first][el.second].first = true;
                            else
                                visited[el.first][el.second].second = true;
                        }
                    }
                    else if (!front[2])
                    {
                        if (!visited[el.first][el.second].second && !visited[el.first][el.second].first)
                        {
                            // cout << "Swapping " << el.first << "," << el.second << "\n";
                            q.push({el.first, el.second, 1});
                            visited[el.first][el.second] = {true, true};
                        }
                    }
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

    cout << solution(map) << '\n';
    cout << solution(map2) << '\n';
    return 0;
}