#include <bits/stdc++.h>
using namespace std;

int maxBridges(vector<pair<int, int> >& bridges)
{
    auto isConnected = [bridges](int i, int j)
    {
        for (int k = 0; k < bridges.size(); k++)
            if (bridges[k].first == i && bridges[k].second == j)
                return true;
        return false;
    };

    auto isXnXX = [bridges](pair<int, int> a, pair<int, int> b)
    {
        if (
            (a.first < b.first) && (a.second - a.first > b.second - b.first) ||
            (b.first < a.first) && (b.second - b.first > a.second - a.first)
        )
        {
            return true;
        }
        return false;
    };


}

int main()
{
    vector<pair<int, int> > bridges {{5, 5},
                                     {3, 2},
                                     {1, 3},
                                     {6, 4},
                                     {4, 6},
                                     {2, 4}};
    return 0;
}

