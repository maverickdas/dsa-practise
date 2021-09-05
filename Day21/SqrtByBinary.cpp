#include <iostream>

using namespace std;

int binRoot(int n)
{
    int left = 0, right = n, mid = 0;

    while (left < right)
    {
        // cout << left << ", " << right << " for " << n << "\n";
        if (mid == (left + right) / 2)
        {
            mid = right * right == n ? right : mid;
            break;
        }

        mid = (left + right) / 2;

        if (mid * mid == n)
            break;

        if (mid * mid < n)
        {
            left = mid;
        }
        else
        {
            right = mid - 1;
        }
    }

    return mid;
}

int main()
{
    for (int i = 0; i <= 100; ++i)
        cout << "Sqrt(" << (i) << ") = " << binRoot(i) << "\n";
}