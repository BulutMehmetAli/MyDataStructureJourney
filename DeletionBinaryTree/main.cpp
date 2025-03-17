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
bool isAvailable(Node *root , int data){

    if(root == nullptr){
        return false;
    }
    if(root->data == data){
        cout << data << " is available " ;
        return true;
    }
    return isAvailable(root->left , data) || isAvailable(root->right , data);
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
void deletDeepest(Node* root, Node* dNode) {

   queue<Node*> q;
   q.push(root);
   Node *curr;
   while(!q.empty()){

        curr = q.front();
        q.pop();

        if(curr == dNode){
            curr = nullptr;
            delete (dNode);
            return;
        }
        if(curr->right){
            if(curr->right == dNode){
                curr -> right = nullptr;
                delete (dNode);
                return;
            }q.push(curr->right);
        }
        if(curr->left){
            if(curr->left == dNode){
                curr -> left= nullptr;
                delete (dNode);
                return;
            }q.push(curr->left);
        }
   }
}
Node* deletion(Node *root , int key){
   if(root == nullptr){
        return nullptr;
   }
   if(root->left == nullptr && root->right == nullptr){
        if(root->data == key){
            return nullptr;
        }else{
            return root;
        }
   }
   queue<Node*> q;
   q.push(root);
   Node *curr;
   Node *keyNode = nullptr;
   while(!q.empty()){
        curr = q.front();
        q.pop();

        if(curr->data == key){
            keyNode = curr;
        }
        if(curr->left){
            q.push(curr->left);
        }
        if(curr->right){
            q.push(curr->right);
        }
   }
   if(keyNode != nullptr){
        int x = curr->data;
        keyNode->data = x;
        deletDeepest(root,curr);
   }
   return root;
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
    displayNode(root);
    cout << endl;
    deletion(root,3);
    displayNode(root);
    return 0;
}
