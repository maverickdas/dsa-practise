#include <iostream>
// #include <vector>

using namespace std;

void build(int st[], int ar[], int tl, int tr, int v) // 0, n - 1, v = 1
{
    if (tl == tr)
    {
        st[v] = ar[tl];
        return;
    }
    int mid = (tl + tr) / 2;
    build(st, ar, tl, mid, 2 * v);
    build(st, ar, mid + 1, tr, 2 * v + 1);
    st[v] = st[2 * v] + st[2 * v + 1];
}

void update(int st[], int tl, int tr, int v, int ind, int val)
{
    if (tl == tr)
    {
        st[v] = val;
        return;
    }
    int mid = (tl + tr) / 2;
    if (ind <= mid)
    {
        update(st, tl, mid, 2 * v, ind, val);
    }
    else
    {
        update(st, mid + 1, tr, 2 * v + 1, ind, val);
    }
    st[v] = st[2 * v] + st[2 * v + 1];
}

int sum(int st[], int tl, int tr, int v, int l, int r)
{
    if (r < tl || l > tr)
        return 0;

    if (tl == l && tr == r)
        return st[v];

    int mid = (tl + tr) / 2;
    int s =  sum(st, tl, mid, 2 * v, l, min(r, mid))
          + sum(st, mid + 1, tr, 2 * v + 1, max(l, mid + 1), r);
    cout << s << '\n';
    return s;
}

void printSegTree(int st[], int n)
{
    for (int i = 1; i < n; ++i)
    {
        cout << st[i] << ' ';
    }
    cout << '\n';
}

int main()
{
    const int n = 8;
    int ar[] {3, 6, 4, 7, 6, 1, 8, 5};
    int st[4 * n];
    build(st, ar, 0, n - 1, 1);
    printSegTree(st, 4 * n);
    int ind = 3; // 7
    int val = 3;
    // update(st, 0, n - 1, ind, val, 1);
    // printSegTree(st, 4 * n);

    cout << sum(st, 0, n - 1, 1, 0, 4) << '\n';

    return 0;
}