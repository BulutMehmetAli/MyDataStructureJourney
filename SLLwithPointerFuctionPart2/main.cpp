#include <iostream>

using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int value){
        data = value;
        next = nullptr;
    }
};

Node* deleteHead(Node* head){

    if(head == nullptr){
        return nullptr;
    }

    Node *temp = head;
    head = head->next;
    delete temp;

    return head;
}

Node* deleteNode(Node* head, int position){

    Node *prev;
    Node *temp = head;
    if (temp == NULL)
        return head;
    if (position == 1) {

        // make next node as head and free old head
        head = temp->next;
        return head;
    }
    while(position>0){
        prev = temp;
        temp =temp->next;
        position--;

    }
    if(temp!=NULL){
        prev->next = temp->next;
        delete temp;
    }else{
        cout << "Data not present\n";
    }

    return head;
}
Node *deleteLastNode(Node *head){

    if(head == nullptr){
        return nullptr;
    }

    if(head->next == nullptr){
        delete head;
        return nullptr;
    }

    Node *temp = head;
    while(temp->next->next != nullptr){
        temp = temp->next;
    }
    delete temp->next;

    temp->next = nullptr;

    return head;

}
//recursive approaches
Node  *deleteList(Node *head){

//    if (head == nullptr) {
//            cout << "List is empty" << endl;
//            return nullptr; // Eðer liste boþsa iþlemi sonlandýr
//        }
    Node *temp = head;
    deleteList(temp->next);
    delete temp;

    return nullptr;
}
//iterative approaches
Node *deleteListiterative(Node* curr) {
    if (curr == nullptr) {
            cout << "List is empty" << endl;
            return nullptr; // Eðer liste boþsa iþlemi sonlandýr
        }

    // Iterate through the list until it becomes empty
    while (curr != nullptr) {

        // Store the next node before deleting current
        Node* temp = curr->next;

        // Delete the current node
        delete curr;

        // Move to the next node
        curr = temp;
    }
    if (curr == nullptr) {
            cout << "List is successfully deleted" << endl;
            return nullptr; // Eðer liste boþsa iþlemi sonlandýr
        }

}
void printList(Node* head){

    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "nullptr" << endl;
}


int main()
{
    // Creating a linked list
    // 1 -> 2 -> 3 -> 4 -> 5 -> nullptr
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next= new Node(7);

    cout << "Original list: ";
    printList(head);
    // Deleting the head node
    head = deleteHead(head);
    cout << "List after deleting the head: ";
    printList(head);

    int position = 2;
    head = deleteNode(head, position);

    cout << "List after deletion : " ;
    printList(head);
    cout << "List after deletion last node" << endl;
    deleteLastNode(head);
    printList(head);

    cout << "Deleted list" << endl;
    head = deleteList(head);
    printList(head);
    //head = deleteListiterative(head);
    //printList(head);



    return 0;
}
