#include <iostream>
using namespace std;

int binSearchExact(int ar[], int n, int key)
{
    int left = 0, right = n - 1, mid;

    while(left <= right) {
        mid = (left + right) / 2;

        if (ar[mid] == key)
            return mid;
        if (ar[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int sbinSearchExact(int ar[], int n, int k) {
    int l = 0, r = n - 1, m = 0;
    while(l <= r) {
        m = r - (r - l) / 2; // in case r, l -> INT_MAX, (r + l)/2 -> INT_MAX
        if (ar[m] == k)
            return m;
        else if (ar[m] > k)
            r = m - 1;
        else
            l = m + 1;
    }
    return -1;
}
// 1 2 3 4 5

// 1 2 3

// 3

// 1, 2, 5, 6, 8, 10, 11

int sbinSearchBounds(int ar[], int n, int k) {
    int l = 0, r = n - 1, m = 0;
    while(l <= r) {
        m = r - (r - l) / 2; // in case r, l -> INT_MAX, (r + l)/2 -> INT_MAX
        if (ar[m] == k)
            return m;
        else if (ar[m] > k)
            r = m - 1;
        else
            l = m + 1;
    }
    // cout << "l " << l << " r " << r << "\n";
    return -1;
}

int sssLowerBound(int ar[], int n, int key)
{
    int l = 0, r = n - 1;
    int ind = -1;
    while (l <= r)
    {
        int mid = r - (r - l) / 2;
        if (ar[mid] <= key)
        {
            l = mid + 1;
            ind = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    return ind;
}



int binSearchLowerBound(int ar[], int n, int key)
{
    int left = 0, right = n - 1, mid;

    while(left <= right) {
        mid = left - (left - right) / 2;

        if (ar[mid] == key)
            return mid;
        if (ar[mid] < key)
            left = mid + 1;
        else {

        }
    }
}

int binSearchUpperBound(int ar[], int n, int key)
{

}

int main()
{
    int ar[] {0, 1, 2, 5, 6, 8, 10, 11};
    cout << sbinSearchBounds(ar, sizeof(ar) / sizeof(ar[0]), 13) << '\n';
}