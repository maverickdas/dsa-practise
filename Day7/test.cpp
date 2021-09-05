#include <bits/stdc++.h>
using namespace std;

// vector<vector<string>> groupAnagrams(vector<string>& strs) {
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    int n = strs.size();
    map <string, vector<string>> str_map;
    for (auto s: strs) {
        string s1 (s);
        sort(s.begin(), s.end());
        str_map[s].push_back(s1);
    }
    vector<vector<string>> res;
    for (auto& a: str_map) {
        cout << a.first << "\n";
        res.push_back(a.second);
    }
    return res;
}


// int main() {
//     vector<string> strs =
// }





