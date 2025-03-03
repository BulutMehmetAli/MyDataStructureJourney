#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node *right;
    Node *left;

    Node(int data){
        right=nullptr;
        left=nullptr;
        this->data = data;
    }
};

Node *insertTree(Node *root , int data){

    if(root == NULL){
        root = new Node(data);
    }else{
        root->right = insertTree(root->right,data);
    }
    return root;
}

void display(Node *root){

    if(root != nullptr){
        cout << root->data << " ";
        display(root->right);
    }
}

int main()
{
    Node* root = NULL;
    root = insertTree(root,1);
    insertTree(root,2);
    insertTree(root,3);
    insertTree(root,4);
    insertTree(root,5);
    insertTree(root,6);
    display(root);
    return 0;
}
