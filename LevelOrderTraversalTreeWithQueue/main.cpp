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

// **Correct Level Order Traversal using a Single Stack**
void levelOrderQueue(Node *root) {

    if(root == nullptr){
        cout << "Tree is empty !!!" << endl;
        return;
    }
    queue<Node*> myQueue;
    myQueue.push(root);
    while(!myQueue.empty()){
        Node *temp = myQueue.front();
        myQueue.pop();
        cout << temp->data << " " ;
        if(temp->left) myQueue.push(temp->left);
        if(temp->right) myQueue.push(temp->right);

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
    levelOrderQueue(root);
    cout << endl;

    return 0;
}
