#include <vector>
#include <iostream>

using namespace std;

vector<string> recurse(int n) {
    if (n==1) {
        return {"()"};
    }
    vector<string> subans = recurse(n-1);
    vector<string> res;
    for (int i=0; i<subans.size(); i++) {
        res.push_back("(" + subans[i] + ")");
        string tmp1 = "()" + subans[i];
        string tmp2 = subans[i] + "()";
        res.push_back(tmp1);
        if (tmp2 != tmp1)
            res.push_back(tmp2);
    }
    return res;
}

void genParams() {
    vector<string> res = recurse(4);
    for (int i=0; i<res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << "\n";
}


int main() {
    genParams();
    return 0;
}