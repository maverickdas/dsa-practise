#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


int sumSubTree(TreeNode* node, int sum, int &bestsum) {
    if (!node->left && !node->right) {
        return node->val;
    }

    int tmpL = 0, tmpR = 0;
    if (node->left)
    {
        tmpL = sumSubTree(node->left, sum, bestsum);
        bestsum = (sum - bestsum) > (sum - tmpL) ? tmpL : bestsum;
    }
    if (node->right)
    {
        tmpR = sumSubTree(node->right, sum, bestsum);
        bestsum = (sum - bestsum) > (sum - tmpL) ? tmpR : bestsum;
    }
    return tmpL + tmpR + node->val;
}

int maxProduct(TreeNode *root)
{
    int sum = 0, bestsum = 0;

    sum = sumSubTree(root, sum, bestsum);
    bestsum = 0;
    sumSubTree(root, sum, bestsum);
    return bestsum * (sum - bestsum);
}
