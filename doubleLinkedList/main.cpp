#include <iostream>

using namespace std;

struct Node{

    int data;
    Node *next;
    Node *prev;

};

class DoublyLinkedList{

private:

    Node *head;

public:
    DoublyLinkedList() : head(nullptr){}

    void insertAtBeginning(int value){
        Node *newNode = new Node();
        newNode->data = value;
        newNode->prev = nullptr;
        newNode->next=head;
        if(head!=nullptr){
            head->prev = newNode;
        }
        head = newNode;
    }
    void insertAtEnd(int value){
        if(head == nullptr){
            insertAtBeginning(value);
            return;
        }
        Node *temp = head;
        while(temp->next != nullptr){
            temp=temp->next;
        }
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next=nullptr;
        newNode->prev = temp;
        temp->next = newNode;
    }
    void displayNodes(){
        Node *temp = head;
        while(temp != nullptr){
            cout << temp->data << " -> ";
            temp=temp->next;
        }
        cout << "nullptr" << endl;
    }
    void insertAtPosition(int value , int position){
        if (position <= 0) {
            cout << "Invalid position!" << endl;
            return;
        }
        if(head == nullptr){
            insertAtBeginning(value);
            return;
        }
        Node *newNode = new Node();
        newNode->data = value;
        Node *temp = head;
        for (int i= 1 ; i < position - 1  ; i++){
            if (temp->next == nullptr) {
                cout << "Position out of bounds!" << endl;
                delete newNode;
                return;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        if (temp->next != nullptr) {
            temp->next->prev = newNode;
        }
        newNode->prev = temp;
        temp->next= newNode;

    }
    void deleteBeginNode(){
        Node *temp = head;
        head = head->next;
        head->prev = nullptr;
        delete temp;
    }
    void deleteposistionNode(int position){
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        if (position <= 0) {
            cout << "Invalid position!" << endl;
            return;
        }
        if(position == 1){
            deleteBeginNode();
        }
        Node *temp = head;
        position -= 2;
        while(position>=0){
            if(temp->next == nullptr){
                cout << "Out of bound";
                return;
            }
            temp = temp->next;
            position--;
        }
        if(temp->next != nullptr){
            temp->next->prev = temp->prev;

        }
        if(temp->prev != nullptr){
            temp->prev->next=temp->next;
        }

        delete temp;
    }
};
int main()
{
    DoublyLinkedList l1;
    l1.insertAtBeginning(4);
    l1.insertAtEnd(5);
    l1.insertAtEnd(6);
    l1.insertAtEnd(57);
    l1.insertAtEnd(58);
    l1.insertAtEnd(59);
    l1.insertAtEnd(53);
    l1.insertAtEnd(52);
    l1.insertAtEnd(51);
    l1.insertAtEnd(50);
    l1.insertAtEnd(54);
    l1.deleteposistionNode(4);
    l1.displayNodes();

    return 0;
}
