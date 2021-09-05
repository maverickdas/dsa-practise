#include <vector>

using namespace std;

//Node Structure
struct Node
{
	int data;
	Node *left, *right;
};

pair<int, int> recMaxSum(Node* node) {
    if (!node->left && !node->right)
        return {node->data, 0};

    pair<int, int> lsum = {0, 0}, rsum = {0, 0};
    if (node->left)
        lsum = recMaxSum(node->left);
    if (node->right)
        rsum = recMaxSum(node->right);

    return {
        node->data + lsum.second + rsum.second,
        max(lsum.first, lsum.second) + max(rsum.first, rsum.second) // surely correct way
    };
}

int getMaxSum(Node *root)
{
    pair<int, int> ans = recMaxSum(root);
    return max(ans.first, ans.second);
}