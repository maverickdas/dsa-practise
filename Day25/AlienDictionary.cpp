#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <queue>

using namespace std;

// I am an ellien. When leaving earth, I have spoken few word.
// Because, why waste time tell much word when few word do trick.
// less word much wow
// My words were:

// ["jsvh", "tbkv", "tljfd", "adf"] // rupe llube tish

// Dear earthlings, can you find the order of the alphabets that I follow?

// Example 1:
// Input:  words[] = {"baa", "baa", "abcd", "abca", "cab", "cad"}
// Output: Order of characters is 'b', 'd', 'a', 'c'

// Example 8:
// Input:  words[] = {"caa", "aaa", "aab"}
// Output: Order of characters is 'c', 'a', 'b'

// Example 3:
// Input:  words[] = {"caa", "aak", "aab", "kaa"}
// Output: Order of characters is 'c', 'a', 'k', 'b'

void printGraph(map<char, pair<set<char>, int>> adj)
{
    for (auto &el : adj)
    {
        cout << el.first << ": " << el.second.second << " -> ";
        for (auto &el2 : el.second.first)
        {
            cout << el2 << ", ";
        }
        cout << "\n";
    }
}

// int longestPath(map<char, set<char>> adj)
// {
//     int maxvalue = 0;
//     for (auto &v : adj)
//     {
//         char c = v.first;
//         int currmax = 0;
//         queue<char> q;
//         q.push(c);

//         while (!q.empty())
//         {
//             q.push('.');
//             while (q.front() != '.')
//             {
//                 for (auto &el : adj[q.front()])
//                     q.push(el);
//                 q.pop();
//             }
//             q.pop();
//             ++currmax;
//         }

//         maxvalue = max(currmax, maxvalue);
//     }

//     return maxvalue;
//
// }
//

// vector<char> findDict(string words[], int n)
// {
//     vector<char> result;
//     map<char, set<char>> adj;

//     adj[words[0][0]] = {};

//     for (int i = 0; i < n - 1; ++i)
//     {
//         int k = 0;

//         while (k < words[i].length() && k < words[i + 1].length() && words[i][k] == words[i + 1][k])
//         {
//             ++k;
//         }

//         if (k < words[i].length() && k < words[i + 1].length())
//             adj[words[i][k]].insert(words[i + 1][k]);
//     }

//     printGraph(adj);
//     cout << longestPath(adj) << "\n";

//     return result;
// }

string findDict(string words[], int n)
{
    string result;
    map<char, pair<set<char>, int>> adj;

    auto createObj = [&adj](char c)
    {
        if (!adj.count(c))
            adj[c] = {{}, 0};
    };

    createObj(words[0][0]);

    for (int i = 0; i < n - 1; ++i)
    {
        int k = 0;

        while (k < words[i].length() && k < words[i + 1].length() && words[i][k] == words[i + 1][k])
        {
            ++k;
        }

        if (k < words[i].length() && k < words[i + 1].length())
        {
            createObj(words[i][k]);
            createObj(words[i + 1][k]);

            adj[words[i][k]].first.insert(words[i + 1][k]);
            adj[words[i + 1][k]].second += 1;
        }
    }

    // printGraph(adj);

    bool found = false;
    do
    {
        found = false;
        for (auto &el : adj)
        {
            if (el.second.second == 0)
            {
                result += el.first;
                found = true;
                for (auto inner : el.second.first)
                {
                    adj[inner].second -= 1;
                }
                el.second.second = -1;
                break;
            }
        }
    } while (found);

    return result;
}

int main()
{
    string words[] = {"baa", "abcd", "abca", "cab", "cad"};
    cout << findDict(words, 5) << "\n";
}