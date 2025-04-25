#include <iostream>
#include <queue>
#include <vector> // Temporary list for storing nodes
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : data(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

bool isSameTree(TreeNode* p, TreeNode* q) {

    if (p == nullptr && q == nullptr) return true;

    if (p == nullptr || q == nullptr) return false;

    if (p->data != q->data) return false;

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main() {

    TreeNode* node4 = new TreeNode(4);
    TreeNode* node3 = new TreeNode(3, nullptr, node4);
    TreeNode* node10 = new TreeNode(10);
    TreeNode* node9 = new TreeNode(9, nullptr, node10);
    TreeNode* node8 = new TreeNode(8, nullptr, node9);
    TreeNode* root1 = new TreeNode(5, node3, node8);

    TreeNode* node2_4 = new TreeNode(4);
    TreeNode* node2_3 = new TreeNode(3, nullptr, node2_4);
    TreeNode* node2_10 = new TreeNode(10);
    TreeNode* root2 = new TreeNode(5, node2_3, nullptr);

    bool result = isSameTree(root1, root2);
    cout << result << endl;
    return 0;
}
