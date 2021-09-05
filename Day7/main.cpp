#include <bits/stdc++.h>
#include <iostream>
using namespace std;


int minSwaps(int ar[], int n)
{
    int remaining0 = 0, remaining1 = 0, parti = 0, partval = INT_MAX;

    for (int i = 0; i < n; i++)
        if (ar[i] == 0)
            remaining0++;

    for (int i = 0; i < n; i++) {
        if (partval > remaining0 + remaining1)
        {
            partval = remaining0 + remaining1;
            parti = i;
        }

        if (ar[i] == 0)
            remaining0--;
        else
            remaining1++;
    }

    for (int i = 0; i < n; i++)
        cout << (i < parti ? 0 : 1) << ' ';
    cout << '\n';

    return partval;
}

int main() {
    int ar[]{0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1};
    cout << minSwaps(ar, 13) << '\n';
    return 0;
}