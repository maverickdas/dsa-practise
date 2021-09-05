#include <bits/stdc++.h>
using namespace std;


vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    vector<bool> flag(strs.size(), false);

    vector<vector<string>> result;

    auto compare = [](map<char, int> freq1, map<char, int> freq2)
    {
        for (const pair<char, int> &fpair : freq1)
        {
            if (freq2[fpair.first] != fpair.second)
                return false;
        }
        for (const pair<char, int> &fpair : freq2)
        {
            if (freq1[fpair.first] != fpair.second)
                return false;
        }
        return true;
    };

    auto getMap = [](string s)
    {
        map<char, int> freq;

        for (int i = 0; i < s.length(); ++i)
        {
            freq[s[i]]++;
        }

        return freq;
    };

    result.push_back({strs[0]});
    flag[0] = true;

    for (int i = 0; i < strs.size(); ++i) {
        if (!flag[i]) {
            map<char, int> tmp;
            tmp = getMap(strs[i]);

            for (int j = 0; j < result.size(); ++j)
            {
                if (compare(tmp, getMap(result[j][0]))) {
                    flag[i] = true;
                    result[j].push_back(strs[i]);
                }
            }

            if (!flag[i]) {
                result.push_back({strs[i]});
                flag[i] = true;
            }
        }
    }

    return result;
}


int main () {
    vector<string> s = {"eat", "tea", "tan", "ate", "nat", "bat"};
    groupAnagrams(s);
}