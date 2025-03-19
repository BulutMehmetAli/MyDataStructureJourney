#include <iostream>
#include <queue>
using namespace std;
struct Node{

    int data;
    Node *left;
    Node *right;

    Node(int data){
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};
Node* insertTree(Node *root , int data){
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
void displayNode(Node* root) {
    if (root == nullptr) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node *temp = q.front();
        q.pop();
        cout << temp->data << " " ;
        if(temp->left !=nullptr) q.push(temp->left);
        if(temp->right != nullptr) q.push(temp->right);
    }
    cout << endl;
}
int findMax(Node *root){

    if(root == nullptr){
        return -1;
    }
    queue<Node*> q;
    q.push(root);
    int maxElement = root->data;
    Node *temp;
    while(!q.empty()){
        temp = q.front();
        q.pop();
        maxElement = max(maxElement,temp->data);
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
    return maxElement;
}
int main() {
    Node *root = nullptr;
    root = insertTree(root, 8);
    root = insertTree(root, 5);
    root = insertTree(root, 6);
    root = insertTree(root, 32);
    root = insertTree(root, -3);
    root = insertTree(root, 1);
    root = insertTree(root, 21);
    root = insertTree(root, 100);
    displayNode(root);
    int x = findMax(root);
    cout << x  << endl;
    return 0;
}
