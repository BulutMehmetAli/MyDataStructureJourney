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
bool isAvailable(Node *root , int data){

    if(root == nullptr){
        return false;
    }
    int sum = root->data;
    if(root->right){
        sum += root->right->data;
    }
    if(root->left){
        sum += root->left->data;
    }
    if(sum == data){
        return true;
    }
    bool leftNode = isAvailable(root->left , data);
    bool rightNode = isAvailable(root->right , data);

    return leftNode || rightNode;

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
    displayNode(root);
    bool x = isAvailable(root,11);
    cout << x << endl;
    return 0;
}
