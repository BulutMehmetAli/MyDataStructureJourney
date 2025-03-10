#include <iostream>
#include <stack>
#include <vector> // Temporary list for storing nodes
using namespace std;

struct Node {
    int data;
    Node *right, *left;

    Node(int data) {
        this->data = data;
        right = nullptr;
        left = nullptr;
    }
};

// FIX: Added return root; in the insertTree function
Node *insertTree(Node *root, int data) {
    if (root == NULL) {
        return new Node(data);
    }
    if (root->data < data) {
        root->right = insertTree(root->right, data);
    } else {
        root->left = insertTree(root->left, data);
    }
    return root;
}

// **Correct Level Order Traversal using a Single Stack**
void levelOrderDoubleStack(Node *root) {
    if (!root) {
        cout << "Tree is empty !!!" << endl;
        return;
    }

    stack<Node*> s1, s2;
    s1.push(root);

    while (!s1.empty()) {
        Node* temp = s1.top();
        s1.pop();
        cout << temp->data << " ";

        if (temp->left) s2.push(temp->left);
        if (temp->right) s2.push(temp->right);

        if (s1.empty()) {
            while (!s2.empty()) {
                s1.push(s2.top());
                s2.pop();
            }
        }
    }
}
int main() {
    Node *root = nullptr;
    root = insertTree(root, 10);
    root = insertTree(root, 20);
    root = insertTree(root, 1);
    root = insertTree(root, 3);
    root = insertTree(root, 12);
    root = insertTree(root, 8);
    root = insertTree(root, 9);

    cout << "Level Order Traversal (Correct Order using a Single Stack): ";
    levelOrderDoubleStack(root);
    cout << endl;

    return 0;
}
