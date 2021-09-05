#include <iostream>
using namespace std;

void printSegTree(int st[], int n)
{
    for (int i = 1; i < n; ++i)
    {
        cout << st[i] << ' ';
    }
    cout << '\n';
}

void build(int st[], int tl, int tr, int ar[], int v)
{
    if (tl == tr)
    {
        st[v] = ar[tl];
        return;
    }

    int mid = (tl + tr) / 2;

    build(st, tl, mid, ar, 2 * v);
    build(st, mid + 1, tr, ar, 2 * v + 1);
    st[v] = st[2 * v] + st[2 * v + 1];
}

void update(int st[], int tl, int tr, int ind, int val, int v)
{
    if (tl == tr)
    {
        st[v] = val;
        return;
    }

    int mid = (tl + tr) / 2;

    if (ind <= mid)
    {
        update(st, tl, mid, ind, val, 2 * v);
    }
    else
    {
        update(st, mid + 1, tr, ind, val, 2 * v + 1);
    }
    st[v] = st[2 * v] + st[2 * v + 1];
}

int query(int st[], int tl, int tr, int il, int ir, int v)
{
    if (tl == il && tr == ir)
        return st[v];

    int mid = (tl + tr) / 2;

    if (ir <= mid)
        return query(st, tl, mid, il, ir, 2 * v);
    else if (il > mid)
        return query(st, mid + 1, tr, il, ir, 2 * v + 1);
    else
        return query(st, tl, mid, il, mid, 2 * v)
        + query(st, mid + 1, tr, mid + 1, ir, 2 * v + 1);

    // SHAME
    // int mid = (tl + tr) / 2;
    // if (mid == il || mid == ir)
    // {
    //     return sum;
    //     // do something
    // }
    // else if (il <= mid && ir <= mid)
    // {
    //     return query(st, tl, mid, il, ir, 2 * v, st[2 * v]);
    // }
    // else if (il <= mid && ir <= mid)
    // {
    //     return query(st, mid + 1, tr, il, ir, 2 * v + 1, st[2 * v + 1]);
    // }
    // else // il <= mid < ir
    // {
    //     int leftvalue = (il <= (tl + mid) / 2) ? query(st, tl, mid, il, ir, v, sum) : query(st, mid+1, tr, il, ir, v, st[2 * v +1]);
    //     int rightvalue = (ir > (tl + mid) / 2) ? query(st, mid+1, tr, il, ir, v, sum) : query(st, mid + 1, tl, il, ir, v, st[2 * v + 1]);

    //     if
    //     {
    //     }
    //     else
    //     {
    //     }

    // }
}

int main()
{
    const int n = 8;
    int ar[] {3, 6, 4, 7, 6, 1, 8, 5};
    int st[4 * n + 1];
    build(st, 0, n - 1, ar, 1);
    printSegTree(st, 4 * n + 1);
    int ind = 3; // 7
    int val = 3;
    // update(st, 0, n - 1, ind, val, 1);
    // printSegTree(st, 4 * n);

    cout << query(st, 0, n - 1, 0, 4, 1) << '\n';

    return 0;
}