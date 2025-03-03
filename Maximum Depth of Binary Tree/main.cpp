#include <iostream>

using namespace std;
struct Node{

    int data;
    Node *right,*left;

    Node(int data){
        this->data = data;
        right = nullptr;
        left = nullptr;
    }
};
Node *insertTree(Node *root,int data){
    if(root == NULL){
        root = new Node(data);
    }else{
        if(root->data < data){
            root->right = insertTree(root->right,data);
        }else{
            root->left = insertTree(root->left,data);
        }
    }

    return root;

}
int findDepth(Node *root){

    if(root == NULL){
        return -1;
    }
    int leftNode = findDepth(root->left);
    int rightNode = findDepth(root->right);

    return max(leftNode,rightNode)+1;

}
int main()
{
    Node *root = nullptr;
    root = insertTree(root , 10);
    root = insertTree(root , 20);
    root = insertTree(root , 1);
    root = insertTree(root , 3);
    root = insertTree(root , 12);
    root = insertTree(root , 8);
    root = insertTree(root , 9);
    int x = findDepth(root);
    cout << x << endl;
    return 0;
}
