#include <iostream>
#include <queue>

using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;

    Node(int val) : val(val), left(nullptr), right(nullptr) {}
};

void rightView(Node *root)
{
    queue<Node *> q;

    q.push(root);
    cout << q.front()->val << " ";
    q.push(nullptr);

    while (q.size() > 1)
    {
        if (!q.front())
        {
            q.pop();
            cout << q.front()->val << " ";
            q.push(nullptr);
        }
        else
        {
            if (q.front()->right)
                q.push(q.front()->right);
            if (q.front()->left)
                q.push(q.front()->left);
            q.pop();
        }
    }
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(7);
    root->left->right = new Node(8);
    root->right->right = new Node(15);
    root->right->left = new Node(12);
    root->right->right->left = new Node(14);

    rightView(root);

    return 0;
}