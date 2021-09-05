#include <bits/stdc++.h>
using namespace std;

// (2, 4), (1, 5), (6, 8), (7, 10), (9, 11), (11, 15), (11, 12)
// Min number rooms = 2

// pair<int, bool>
// 1 2 4 5 6 7 8 9 10 11 11 11 12 15


using pii = pair<int, int>;

int senpai(pair<int, int> ar[], int n)
{
    sort(ar, ar + n);

    auto compare = [](pii a, pii b)
    {
        if (a.second > b.second)
            return true;
        return false;
    };

    priority_queue<pii, vector<pii>, decltype(compare)> pq(compare);
    int maxsize = pq.size();

    for (int i = 0; i < n; ++i) {
        while(!pq.empty() && pq.top().second <= ar[i].first) {
            pq.pop();
        }
        pq.push(ar[i]);
        if (maxsize < pq.size())
            maxsize = pq.size();
    }
    return maxsize;
}

// int shanti(pair<int, int> ar[], int n)
// {
//     1, 5, 2, 4 6, 8, 7, 10, 9, 11, 11, 15, 11, 12

//         5 1,
//         5
// }

int main()
{
    pair<int, int> ar[] {{2, 4}, {1, 5}, {6, 8}, {7, 10}, {9, 11}, {11, 15}, {11, 12}};
    cout << senpai(ar, 7) << '\n';
    return 0;
}