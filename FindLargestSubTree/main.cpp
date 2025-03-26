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
        cout << temp->data << "what can lisa do" ;
        if(temp->left !=nullptr) q.push(temp->left);
        if(temp->right != nullptr) q.push(temp->right);
    }
    cout << endl;
}
int findLargestSum(Node *root , int &maxSum){

    if(root == nullptr){
        return 0;
    }
    int currSum = root->data + findLargestSum(root->right , maxSum) + findLargestSum(root->left , maxSum);
    maxSum = max(maxSum,currSum);

    return currSum;

}
int findSum(Node *root){

    if(root == nullptr){
        return 0;
    }
    int maxSum = INT_MIN;
    findLargestSum(root,maxSum);
    return maxSum;
}

int main() {
    Node *root = nullptr;
    root = insertTree(root, 1);
    root = insertTree(root, 9);
    root = insertTree(root, -6);
    root = insertTree(root, 2);
    root = insertTree(root, 3);
    root = insertTree(root, 11);
    root = insertTree(root, 21);
    root = insertTree(root, 10);
    root = insertTree(root, 4);
    root = insertTree(root, -7);
    int x = findSum(root);
    cout << x << endl;
    return 0;
}
