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
void levelOrderStack(Node *root) {

    if(root == nullptr){
        cout << "Tree is empty !!!" << endl;
        return;
    }

    stack<Node*> s;
    s.push(root);
    while(!s.empty()){
        vector<Node*> tempList;
        int size = s.size();

        for(int i = 0; i < size; i++){
            Node *temp = s.top();
            s.pop();
            cout << temp->data << " ";

            if(temp->left) tempList.push_back(temp->left);
            if(temp->right) tempList.push_back(temp->right);
        }
        for(int i = tempList.size() - 1; i >= 0; i--){
            s.push(tempList[i]);
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
    levelOrderStack(root);
    cout << endl;

    return 0;
}
