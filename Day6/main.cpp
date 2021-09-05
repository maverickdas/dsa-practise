#include <bits/stdc++.h>
using namespace std;

// 4, 5, 7, 1, 3, 2, 8
// k = 3
// 7, 7, 7, 3, 8

void slider(int ar[], int N, int k) {
    // priority_queue<int> pq;

    auto get_maxi = [ar, k](int i)
    {
        int maxi = i;

        for (int j = i + 1; j < i + k; j++) {
            if (ar[j] > ar[maxi]) {
                maxi = j;
            }
        }

        return maxi;
    };

    for (int i = 0; i <= N - k; i++) {
        int maxi = get_maxi(i);
        cout << ar[maxi] << ' ';
        i++;
        // cout << "\nI=" << i << "\n";
        while (i < maxi)
        {
            if (ar[maxi] < ar[i])
                break;
            cout << ar[maxi] << ' ';
            i++;
        }
    }
}

int main()
{
    int ar[] {4, 5, 7, 1, 3, 2, 8};
    slider(ar, 7, 3);
    return 0;
}