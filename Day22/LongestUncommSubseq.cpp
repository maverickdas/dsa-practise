#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

// abcdefg
// abcdef, bcdefg


int findLUSlength(string a, string b)
{
    return a == b ? -1 : max(a.length(), b.length());
}

int findLUSlengthArray(vector<string> &strs)
{
    map<string, int> flag;
    auto comp = [](string a, string b)
    {
        return a.length() < b.length();
    };
    priority_queue<string, vector<string>, decltype(comp)> pq(comp);

    for (int i = 0; i < strs.size(); ++i)
    {
        ++flag[strs[i]];
    }

    for (int i = 0; i < strs.size(); ++i)
    {
        if (flag[strs[i]] == 1)
            pq.push(strs[i]);
    }

    auto isSubseq = [](string a, string b)
    {
        int k = 0;
        for (int i = 0; i < a.length(); ++i)
        {
            if (a[i] == b[k])
                ++k;
            if (k == b.length())
                break;
        }
        return k == b.length();
    };

    while(!pq.empty()) {
        if ()
    }

    return -1;
}
