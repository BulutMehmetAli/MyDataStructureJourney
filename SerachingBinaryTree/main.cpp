#include <iostream>
#include <queue>
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
Node* insertTree(Node* root, int data) {
    Node *newNode = new Node(data);
    if (root == nullptr) {
        return newNode;
    }
    queue<Node*> myQueue;
    myQueue.push(root);
    while(!myQueue.empty()){
        Node *temp = myQueue.front();
        myQueue.pop();
        if(temp->left == nullptr){
            temp->left = newNode;
            return root;
        }else{
            myQueue.push(temp->left);
        }
        if(temp->right == nullptr){
            temp->right = newNode;
            return root;
        }else{
            myQueue.push(temp->right);
        }
    }
    return root;
}
void printTree(Node* root) {
    if (root == nullptr) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        cout << temp->data << " ";

        if (temp->left != nullptr) q.push(temp->left);
        if (temp->right != nullptr) q.push(temp->right);
    }
}
bool searchIn(Node *root, int value) {

    if (!root) return false;
    if (root->data == value) return true;
    return searchIn(root->left, value) || searchIn(root->right, value);
}

int main() {
    Node *root = nullptr;
    root = insertTree(root, 8);
    root = insertTree(root, 5);
    root = insertTree(root, 6);
    root = insertTree(root, 2);
    root = insertTree(root, 3);
    root = insertTree(root, 1);
    root = insertTree(root, 21);
    root = insertTree(root, 10);
    root = insertTree(root, 4);
    root = insertTree(root, 6);
    printTree(root);
    cout <<  " ----- " << endl;
    bool result = searchIn(root,1);
    cout << result << endl;

    return 0;
}
