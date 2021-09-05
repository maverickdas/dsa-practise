#include <iostream>
#include <vector>
#include <stack>


using namespace std;
using pii = pair<int, int>

void printDP(vector<int> &ar)
{
    int n = ar.size();
    cout << "DP: ";
    for (int i = 0; i < n; ++i)
    {
        cout << ar[i] << ' ';
    }
    cout << "\n";
}


int strap(vector<int> &ar) {

    int n = ar.size();
    int maxm = 0;
    for (int i=0; i<n; i++) {
        if (ar[maxm] < ar[i])
            maxm = i;
    }
    int area = 0;
    int max_pass = 0;
    for (int i=0; i<maxm; i++) {
        if (max_pass < ar[i]) {
            max_pass = ar[i];
        }
        area += max_pass - ar[i];
    }
    max_pass = 0;
    for (int i=n-1; i>maxm; i++) {
        if (max_pass < ar[i]) {
            max_pass = ar[i];
        }
        area += max_pass - ar[i];
    }
    return area;
}



int main()
{
    // cout << strap({0,1,0,2,1,0,1,3,2,1,2,1}) << '\n';
    cout << strap({0,1,0,2,1,0,1,3,2,1,2,1}) << '\n';
    // cout << strap({3, 2, 1, 2, 3, 4}) << '\n';
    return 0;
}