#include <stack>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

// for string delimiter
vector<string> split(string s, string delimiter)
{
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != string::npos)
    {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back(token);
    }

    res.push_back(s.substr(pos_start));
    return res;
}

bool isValidSerialization(string preorder)
{
    stack<string> s;
    vector<string> preorders = split(preorder, ",");

    for (int i = 0; i < preorders.size(); ++i)
    {
        string c = preorders[i];

        if (c == "#")
        {
            if (s.empty())
                return false;

            while (!s.empty() && s.top() == "#")
            {
                // cout << "Popped " << s.top() << "\n";
                s.pop();

                if (s.empty() || s.top() == "#")
                    return false;

                // cout << "Popped " << s.top() << "\n";
                s.pop();
            }
        }

        // cout << "Pushed " << c << "\n";
        s.push(c);
    }

    return s.size() == 1 && s.top() == "#";
}

int main()
{
    cout << isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#") << "\n";
    cout << isValidSerialization("9,#,#,1") << "\n";
}