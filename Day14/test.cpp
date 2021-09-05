#include <iostream>
#include <queue>
#include <deque>
#include <map>

using namespace std;
using vi = vector<int>;

struct Node
{
    int val;
    Node* left;
    Node* right;

    Node (int val) : val(val), left(nullptr), right(nullptr) {}
};

void printvec(vi &vec) {
    for(auto &i: vec)
        std::cout << i << ' ';
    std::cout << '\n';
}

void recurseLeft(Node* root, int level, vi &recview){
    if (root != nullptr) {
        // cout << "rec size " << recview.size() << " val " << root->val << " level " << level << "\n";
        if (recview.size() <= level) {
            recview.push_back(root->val);
        }
        recurseLeft(root->left, level+1, recview);
        recurseLeft(root->right, level+1, recview);
    }
}
void recurseRight(Node* root, int level, vi &recview){
    if (root != nullptr) {
        // cout << "rec size " << recview.size() << " val " << root->val << " level " << level << "\n";
        if (recview.size() <= level) {
            recview.push_back(root->val);
        }
        recurseRight(root->right, level+1, recview);
        recurseRight(root->left, level+1, recview);
    }
}

void shantipriyoLeftView(Node* root) {
    vi recview;
    recurseLeft(root, 0, recview);
    printvec(recview);
}

void shantipriyoRightView(Node* root) {
    vi recview;
    recurseRight(root, 0, recview);
    printvec(recview);
}

void dfsTop(Node *root, map<int,Node*> &idxmap, int idx) {
    if (root == nullptr) {
        return;
    }
    dfsTop(root->left, idxmap, idx-1);
    dfsTop(root->right, idxmap, idx+1);
    idxmap[idx] = root;
}

void shantipriyoTopView(Node *root) {
    map<int, Node*> idxmap;
    dfsTop(root, idxmap, 0);
    for (auto &n: idxmap) {
        cout << n.second->val << " ";
    }
    cout << "\n";
}

void dfsBottom(Node *root, map<int,Node*> &idxmap, int idx) {
    if (root == nullptr) {
        return;
    }
    idxmap[idx] = root;
    dfsBottom(root->left, idxmap, idx-1);
    dfsBottom(root->right, idxmap, idx+1);
}

void shantipriyoBottomView(Node *root) {
    map<int, Node*> idxmap;
    dfsBottom(root, idxmap, 0);
    for (auto &n: idxmap) {
        cout << n.second->val << " ";
    }
    cout << "\n";
}


int main()
{
    Node* root = new Node(10);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(7);
    root->left->right = new Node(8);
    root->right->right = new Node(15);
    root->right->left = new Node(12);
    root->right->right->left = new Node(14);

    // cout << root->left->val << '\n';

    // Node* root = new Node(10);

    // cout << "left ";
    // shantipriyoLeftView(root);
    // cout << "right ";
    // shantipriyoRightView(root);
    cout << "top ";
    shantipriyoTopView(root);
    cout << "bottom ";
    shantipriyoBottomView(root);

    return 0;
}