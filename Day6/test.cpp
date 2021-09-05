#include <bits/stdc++.h>
using namespace std;

// 4, 5, 7, 1, 3, 2, 8

// []
// 5, 4, 6, 7, 8, 9
// k=3

// []

// read the max element: O(1)
// insert element: logK
// pop element: logK
// heapify all elements together: O(k)
// insert all elements in pq one by one: O(klogk)
// K --> total number of elements in the priority queue


// 4, 5, 7, 1, 3, 2, 8
// k = 3
// 7, 7, 7, 3, 8

// 3 8 11 14 17 18
// 1 2 4 5 9 12 21
// 7 8 9 10 11 12 13

// 1 2 3 4 5...

void order_across_k_arrays(vector<int> ar[], int k, int n) {
    int tops[k] {0};
    priority_queue<int, vector<int>, greater<int> > pq;
    for (int i=0; i<k; i++) {
            pq.push(ar[i][0]);
        }

    while (!pq.empty())
    {
        int top = pq.top();
        cout << "min is " << top << "\n";
        for (int i=0; i<k; i++) {
            if (top == ar[i][tops[i]]) {
                tops[i]++;
                // cout << "inc top of " << i << " to " << tops[i] << "\n";
                if (tops[i] >= n) break;
                pq.push(ar[i][tops[i]]);
                break;
            }
        }
        // for (int i=0; i<k; i++) {
        //     cout << "top of " << i << " at " << tops[i] << " is " << ar[i][tops[i]] << "\n";
        // }
        pq.pop();
    }
}


int main() {
    vector<int> ar[] = {
        {3, 8, 11, 14, 17, 18, 20},
        {1, 2, 4, 5, 9, 12, 21},
        {7, 8, 9, 10, 11, 12, 13},
    };

    order_across_k_arrays(ar, 3, 7);
    return 0;
}