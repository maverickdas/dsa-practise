#include <bits/stdc++.h>
#include <vector>

using namespace std;

struct MinElement {
    int value;
    // vector<int>::iterator next;
    int arIndex;
    int nextIndex;
};

void printSorted(vector<int> ar[], int N)
{
    auto comp = [](MinElement a, MinElement b)
    {
        return a.value > b.value;
    };

    priority_queue<MinElement, vector<MinElement>, decltype(comp)> pq(comp); // top, pop, push

    for (int i = 0; i < N; i++) {
        if (!ar[i].empty())
        pq.push({ar[i][0], i, 1 < ar[i].size() ? 1 : -1});
    }

    while (!pq.empty())
    {
        MinElement tmp = pq.top();
        cout << tmp.value << ' ';
        pq.pop();

        if (tmp.nextIndex != -1) {
            pq.push({ar[tmp.arIndex][tmp.nextIndex],
                     tmp.arIndex,
                     tmp.nextIndex + 1 < ar[tmp.arIndex].size() ? tmp.nextIndex + 1 : -1});
        }
    }
    cout << '\n';
}

void order_across_k_arrays(vector<int> ar[], int k, int n) {
    int tops[k] {0};
    priority_queue<int, vector<int>, greater<int> > pq;
    for (int i=0; i<k; i++) {
            pq.push(ar[i][0]);
        }

    while (!pq.empty())
    {
        int top = pq.top();
        cout << top << ' ';
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
    cout << '\n';
}


int main()
{
    vector<int> ar[] = {
        {3, 8, 11, 14, 17, 18, 20},
        {1, 2, 4, 5, 9, 12, 21},
        {7, 8, 9, 10, 11, 12, 13},
    };
    cout << "sen3.14\n";
    printSorted(ar, 3);
    cout << "Shantipriyo's (secret) ninja technique\n";
    order_across_k_arrays(ar, 3, 7);
    return 0;
}