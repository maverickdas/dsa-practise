#include <vector>
#include <iostream>

using namespace std;

void recDfs(string tillNow, int leftp, int rightp, int maxsize, int i, vector<string> &ans)
{
    if (i == maxsize)
    {
        if (rightp == leftp)
            ans.push_back(tillNow);
    }
    else if (leftp == rightp)
    {
        recDfs(tillNow + "(", leftp + 1, rightp, maxsize, i + 1, ans);
    }
    else if (leftp > rightp)
    {
        recDfs(tillNow + "(", leftp + 1, rightp, maxsize, i + 1, ans);
        recDfs(tillNow + ")", leftp, rightp + 1, maxsize, i + 1, ans);
    }
}

vector<string> AllParenthesis(int n)
{
    vector<string> ans;
    recDfs("", 0, 0, n * 2, 0, ans);

    for (auto &el : ans)
    {
        cout << el << "\n";
    }

    return ans;
}

int main()
{
    AllParenthesis(3);
}