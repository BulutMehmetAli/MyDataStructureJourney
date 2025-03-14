#include <iostream>
#include <queue>
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
// Function to print postorder traversal
void printPostorder(Node* root)
{
    if(root == nullptr){
        cout << "Tree is empty !!!" << endl;
        return;
    }
    Node *temp = root;
    if(temp->left) printPostorder(temp->left);
    if(temp->right) printPostorder(temp->right);
    cout << temp->data << " " ;
}
int main() {
    Node *root = nullptr;
    root = insertTree(root, 8);
    root = insertTree(root, 5);
    root = insertTree(root, 6);
    root = insertTree(root, 2);
    root = insertTree(root, 3);
    root = insertTree(root, 1);
    root = insertTree(root, 19);
    root = insertTree(root, 21);
    root = insertTree(root, 10);

    printPostorder(root);

    return 0;
}
