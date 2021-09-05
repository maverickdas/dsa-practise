#include <iostream>
#include <deque>
#include <map>

using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;

    Node(int val) : val(val), left(nullptr), right(nullptr) {}
};

void topView(Node *root)
{
    deque<Node *> q;
    map<Node *, int> maxes;
    map<int, int> result;

    q.push_back(root);
    maxes[root] = 0;
    cout << q.front()->val << " ";
    q.push_back(nullptr);

    while (q.size() > 1)
    {
        if (!q.front())
        {
            q.pop_front();
            // print stuff here
            q.push_back(nullptr);
        }
        else
        {
            if (q.front()->left)
            {
                q.push_back(q.front()->left);
                maxes[q.front()->left] = maxes[q.front()] - 1;
                result[maxes[q.front()->left]] = q.front()->left->val;
            }
            if (q.front()->right)
            {
                q.push_back(q.front()->right);
                maxes[q.front()->right] = maxes[q.front()] + 1;
                result[maxes[q.front()->right]] = q.front()->right->val;
            }
            q.pop_front();
        }
    }

    for (auto &el : result)
    {
        cout << el.second << " ";
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

    topView(root);

    return 0;
}