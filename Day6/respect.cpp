#include <bits/stdc++.h>
#include <vector>

// 3 8 11 14 17 18
// 1 2 4 5 9 12 21
// 7 8 9 10 11 12 13

// 1 2 3 4 5...

using namespace std;

struct MinElement
{
    int value;
    int *next;
    // int arIndex;
    // int nextIndex;
};

void printSorted(vector<int> ar[], int N)
{
    auto comp = [](MinElement a, MinElement b)
    {
        return a.value > b.value;
    };

    priority_queue<MinElement, vector<MinElement>, decltype(comp)> pq(comp); // top, pop, push

    for (int i = 0; i < N; i++)
    {
        if (!ar[i].empty())
            pq.push({ar[i][0], 1 < ar[i].size() ? &(*(ar[i].begin() + 1)) : nullptr}); // shit just got real
    }

    while (!pq.empty())
    {
        MinElement tmp = pq.top();
        cout << tmp.value << ' ';
        pq.pop();

        if (tmp.next)
        {
            pq.push({*(tmp.next), // shit just got real
                     new vector<int>::iterator(tmp.next) + 1 != v : nullptr});
        }
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

    printSorted(ar, 3);
    return 0;
}