#include <iostream>
using namespace std;

int binSearchExact(int ar[], int n, int key)
{
    int l = 0, u = n - 1;
    while (l <= u)
    {
        int mid = u - (u - l) / 2;
        if (ar[mid] < key)
            l = mid + 1;
        else if (ar[mid] > key)
            u = mid - 1;
        else
            return mid;
    }
    return -1;
}

int binSearchLowerBound(int ar[], int n, int key)
{
    int l = 0, u = n - 1;
    int ind = -1;
    while (l <= u)
    {
        int mid = u - (u - l) / 2;
        if (ar[mid] <= key)
            l = mid + 1, ind = mid;
        else
            u = mid + 1;
    }
    return ind;
}

int binSearchUpperBound(int ar[], int n, int key)
{
    int l = 0, u = n - 1;
    int ind = -1;
    while (l <= u)
    {
        int mid = u - (u - l) / 2;
        if (ar[mid] < key)
            l = mid + 1;
        else
            u = mid + 1, ind = mid;
    }
    return ind;
}