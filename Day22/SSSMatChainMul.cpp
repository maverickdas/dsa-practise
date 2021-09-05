#include <iostream>
#include <climits>
using namespace std;

int minOperations(int ar[], int n)
{
    int dp[n - 1][n - 1];
    int parts[n];

    for (int s = 1; s < n; ++s)
    {
        for (int l = 0; l + s < n; ++l)
        {
            int r = l + s - 1;
            if (s == 1)
            {
                dp[l][r] = 0;
                continue;
            }
            // else if (s == 2)
            // {
            //     dp[l][r] = ar[l] * ar[l + 1] * ar[r + 1]; // r = l + 2
            //     continue;
            // }
            dp[l][r] = INT_MAX;
            for (int i = l; i < r; ++i)
            {
                int ops = dp[l][i] + dp[i + 1][r] + ar[l] * ar[i + 1] * ar[r + 1];
                if (ops < dp[l][r])
                {
                    dp[l][r] = ops;
                    parts[l] = i + 1;
                    parts[i + 1] = r + 1;
                }
            }
        }
    }


    cout << '(';

    int ind = 0;
    int count = 1;
    while (ind < n - 1 && count++ < 100)
    {
        for (int i = ind; i < parts[ind]; ++i)
            cout << i;
        cout << ")(";
        ind = parts[ind];
    }

    cout << ")\n";


    return dp[0][n - 2];
}

//  0 1 2 3 4 5
// ( )

int main()
{
    int ar[] {10, 30, 5, 10, 12, 45, 2};
    int ar2[] {10, 20, 30, 40, 30};
    cout << minOperations(ar, 7) << '\n';
    cout << minOperations(ar2, 5) << '\n';
    return 0;
}