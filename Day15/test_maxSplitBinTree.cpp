// LC1339

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

long long totSum = 0, maxProd = 0;


int maxProduct(TreeNode* root) {
    totSum = dfs(root);
    maxProd = 0;
    dfs(root);
    return maxProd % int(1e9+7);
}

int dfs(TreeNode* root) {
    if(root != nullptr) {
        int subSum = root->val + dfs(root->left) + dfs(root->right);
        maxProd = max(maxProd, (totSum - subSum) * subSum);
        return subSum;
    }
    return 0;
}