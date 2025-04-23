#include <iostream>
using namespace std;

struct Node{

    int data;
    Node *next;
    Node *prev;

    Node(int data){
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }
};

Node *insertAtBeginning(Node *head , int value){

    Node *newNode = new Node(value);
    if(!head){//head == nullptr is the same things
        newNode->next=newNode;
        newNode->prev=newNode;
        return newNode;
    }
    Node *last = head->prev;
    newNode->next = head;
    newNode->prev = last;
    head->prev = newNode;
    last->next = newNode;
    head =  newNode;

    return head;
}
int lengthOfList(Node *head){

    if(head == nullptr){
        return 0;
    }
    Node *temp = head;
    int counter = 0;
    while(true){
        counter++;
        temp=temp->next;
        if(temp==head){
            break;
        }
    }
    return counter;
}
Node *inserAtEndlist(Node *head , int value){

    Node *newData = new Node(value);
    if(head == nullptr){
        return insertAtBeginning(head , value);
    }
    Node *last = head->prev;
    newData->next = head;
    head->prev = newData;
    last->next= newData;
    newData->prev = last;

    return head;
}

Node *insertAtAfterNode(Node *head , int value , int position){

    Node *newData = new Node(value);
    if(position<0){
        cout << "Position must be 1 or greater!" << endl;
        return head;
    }
    if(position == 1 || head == nullptr){
        return insertAtBeginning(head , value);
    }
    Node *temp = head;
    position-=2;
    while(position>0){
        temp=temp->next;
        position--;
    }
    newData->next = temp->next->next;
    temp->next->prev = newData;
    temp->next = newData;
    newData->prev = temp;

    return head;
//Alternative
//for (int i = 1; i < position - 1 && temp->next != head; i++) {
//        temp = temp->next;
//    }
//    Node* newNode = new Node(value);
//    newNode->next = temp->next;
//    newNode->prev = temp;
//    temp->next->prev = newNode;
//    temp->next = newNode;
//    return head;
}



void displayNodes(Node *head){

    if(head== nullptr){
       cout << "List is empty !!!" << endl;
       return;
    }
    Node *temp = head;
    while (true){
        cout << temp->data << " -> ";
        temp = temp->next;
        if(temp->next == head){
            cout << temp->data << endl;
            break;
        }
    }


}

Node* duplicate(Node* head) {
    Node* temp1 = head;

    while (temp1 != NULL && temp1->next != NULL) {
        if (temp1->data == temp1->next->data) {
            Node* temp2 = temp1->next;
            temp1->next = temp2->next;
            delete temp2;  // doğru şekilde silme
        } else {
            temp1 = temp1->next;
        }
    }

    return head;  // head pointer'ı döndürülmeli
}

int main()
{

    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->prev = head;
    head->next->next = new Node(30);
    head->next->next->prev = head->next;
    head->next->next->next = head;
    head->prev = head->next->next;

    head = insertAtBeginning(head , 20);
    displayNodes(head);

    cout << "Append nodes end of list" << endl;
    head = inserAtEndlist(head , 58);
    head = inserAtEndlist(head , 58);
    head = inserAtEndlist(head , 58);
    head = inserAtEndlist(head , 58);
    displayNodes(head);

    head = insertAtAfterNode(head , 35 , 1);
    displayNodes(head);

    head = duplicate(head);
    displayNodes(head);
    return 0;
}

