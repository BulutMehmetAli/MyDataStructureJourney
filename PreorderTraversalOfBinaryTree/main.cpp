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


// Function to print preorder traversal
void printPreorder(Node* root)
{
    if(root == nullptr){
        cout << "Tree is empty !!!" << endl;
        return;
    }
    Node *temp = root;
    cout << temp->data << " ";
    if(temp->left) printPreorder(temp->left);
    if(temp->right) printPreorder(temp->right);


}
int main() {
    Node *root = nullptr;
    root = insertTree(root, 100);
    root = insertTree(root,50);
    root = insertTree(root, 200);
    root = insertTree(root, 30);
    root = insertTree(root, 32);
    root = insertTree(root, 40);
    root = insertTree(root, 250);
    root = insertTree(root, 240);
    root = insertTree(root, 255);


    printPreorder(root);

    return 0;
}
