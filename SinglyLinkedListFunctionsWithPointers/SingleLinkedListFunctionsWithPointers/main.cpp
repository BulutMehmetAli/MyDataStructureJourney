#include <iostream>

using namespace std;

class Node{

public:
    int data;
    Node *next;

     Node(int value){
        data = value;
        next = nullptr;
     }
};

//Ýterative Approaches
int countNodes(Node *head){

    Node *temp = head;

    int counter = 0;

    while(temp){
        counter++;
        temp=temp->next;
    }
    return counter;

}
//Recursive approaches:
int countNodesWithRecursive(Node * head){

    if(head == NULL){
        return 0;

    }
    return 1 + countNodesWithRecursive(head->next);
}
//Iterative approache
void displayNodesWithIterative(Node *head){

    Node *temp = head;

    while(temp){
        if(temp->next==NULL){
            cout << temp->data ;
            break;
        }
        cout << temp->data << " -> " ;
        temp= temp->next;
    }
}
//Recutsive Approache
void  displayNodesWithRecursive(Node *head){

    if(head->next == NULL){
        cout << head->data  ;
        return;
    }
    cout << head->data << " -> " ;

    displayNodesWithRecursive(head->next);
    /*Alternative:
    Node *temp = head;

    if(temp->next == NULL){
        cout << temp->data  ;
        return;
    }
    cout << head->data << " -> " ;

    displayNodesWithRecursive(head->next);
    */
}
//Iterative approache
Node *insertAtBegginner(Node *head , int newData){

        Node *newNode = new Node(newData);
        newNode->next = head;
        head = newNode;
        return newNode;
//This is only one process therefore we cant use recursive approache.
}
Node *insertAfter(Node *head , int newData , int location){

    Node *newNode = new Node(newData);
    Node *temp = head;


    if(temp==nullptr){
        return  head;
    }


    location = location-2;
    while(location>0){
        location--;
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;

}
Node *insertBefore(Node *head , int newData , int location){

    Node *newNode = new Node(newData);
    Node *temp = head;
    if (head == nullptr) {
        return nullptr;
    }

    location = location - 2;
    while(location>1){
        location --;
        temp=temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}
Node *insertAtEnd(Node *head , int value){

    Node *new_Node = new Node(value);
    if(head == nullptr){
        return new_Node;
    }
    Node *temp = head;
    while(temp->next != nullptr){
        temp=temp->next;
    }
    temp->next = new_Node ;
    new_Node->next = nullptr;

    return head ;
}

//Ýterative approaches
bool searchElemenetInLinkedList(Node *head , int value){
    Node *temp = head;

    if(head == nullptr){
        cout << "List is empty !!! " << endl;
        return false;
    }
    while(temp != NULL){
        if(temp->data == value){
            return true;
        }
        temp=temp->next;

    }
    return false;
}

//Recursive approaches
bool searchElemenetInLinkedListwithRecursive(Node *head , int value){
    Node *temp = head;

    if(head == nullptr){
        cout << "List is empty !!! " << endl;
        return false;
    }
    if(temp->data == value){
        return true;
    }

    return searchElemenetInLinkedList(head->next,value);
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(1);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);
    head->next->next->next->next->next = new Node(11);
    head->next->next->next->next->next->next = new Node(12);
    head->next->next->next->next->next->next->next = new Node(122);
    head->next->next->next->next->next->next->next->next = new Node(1224);
    head->next->next->next->next->next->next->next->next->next = new Node(1252);

    //cout << "Count of nodes is " << countNodes(head);

    //displayNodesWithIterative(head);
    cout << "This Linkedlist is : " ;
    int data  = 4 ;
    head = insertAtBegginner(head,data);
    head = insertAtBegginner(head,10);
    displayNodesWithRecursive(head);
    cout << " " << endl;
    int key = 4 , newData = 58;
    head = insertAfter(head,newData,key);
    displayNodesWithRecursive(head);
    cout << " " << endl;
    cout << "*** " << endl;

    int key2 = 1;
    int newData2 = 308;
    head = insertBefore(head , newData2 , key2);
    displayNodesWithRecursive(head);
    cout << endl;
    int newValue = 6;
    head = insertAtEnd(head, newValue);
    displayNodesWithRecursive(head);
    cout << endl;
    bool x  = searchElemenetInLinkedList(head , 111122);

    string result ;
    if(x == 1){
        result = "True";
    }else{
        result = "False";
    }
    cout << result << endl;

    bool y  = searchElemenetInLinkedList(head , 1);
    string result2 ;
    if(y == 1){
        result2 = "True";
    }else{
        result2 = "False";
    }
    cout << result2 << endl;


    return 0;
}
