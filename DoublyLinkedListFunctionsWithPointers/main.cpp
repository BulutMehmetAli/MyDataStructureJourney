#include <iostream>

using namespace std;

struct Node{

    int data;
    Node *next;
    Node *prev;

    Node(int value){
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

Node *insertAtBeginning(Node *head , int newData){
        Node *newNode =  new Node(newData);

        newNode->prev = nullptr;


        if(head == nullptr){
            head = newNode;
        }
        newNode->next = head;
        if(head!=nullptr){
            head->prev = newNode;
        }

        return newNode;
    }

Node *insertAfter(Node *head , int value , int position){
    if (position <= 0) {
        cout << "Invalid position!" << endl;
        return head;
    }
    Node *newNode = new Node(value);
    Node *temp = head;

    if(head ==  nullptr){
        newNode ->next = nullptr;
        newNode ->prev = nullptr;
        head = newNode;
        return head;
    }
    int i = 2;
    while (i < position) {
        if (temp->next == nullptr) { // Pozisyon listenin sonunu aþýyor
            cout << "Position out of bounds!" << endl;
            delete newNode;
            return head;
        }
        temp = temp->next;
        i++;
    }
    newNode->next = temp->next;
    if(temp->next != nullptr){
        temp->next->prev = newNode;
    }
    newNode->prev = temp;
    temp ->next = newNode;

    return head;

}
Node *insertAtEnd(Node *head , int data){
    Node *newNode = new Node(data);
    Node *temp = head;
    if(head == nullptr){
        insertAtBeginning(head , data);
    }
    while(temp->next != nullptr){
        temp = temp->next;
    }
    newNode->next = nullptr;
    temp->next = newNode;
    newNode->prev = temp;

    return head;


}

Node *deleteAtBeginning(Node *head){
    if(head == nullptr){
        return nullptr;
    }
    Node *temp = head;
    head = head->next;
    head->prev = nullptr;
    delete temp;
    return head;
}
Node *deleteAtPosition(Node *head , int position){

    if(head == nullptr){
        cout << "List is empty!" << endl;
        return nullptr;
    }
    if (position <= 0) {
        cout << "Invalid position!" << endl;
        return head;
    }
    Node *temp = head;
    if(position == 1){
        head = head->next;
        head->prev = nullptr;
        delete temp;
        return head;
    }
    int currentPosition = 1;
    while(currentPosition< position && temp!= nullptr){
        temp=temp->next;
        currentPosition++;
    }
    if(temp == nullptr){
        cout << "Position is out of bound !!! " << endl;
        return head;
    }
    if(temp->next != nullptr){
        temp->next->prev = temp->prev;
    }
    if(temp->prev != nullptr){
        temp->prev->next = temp->next;
    }

    delete temp;
    return head;
}
Node *deleteBeforeNode(Node *head , int position){

    if(head ==  nullptr){
        cout << "List is empty!" << endl;
        return nullptr;
    }
    if (position <= 0) {
        cout << "Invalid position!" << endl;
        return head;
    }
    if(position == 1){
        cout << "There is no node before position 1" << endl;
        return head;
    }
    Node *temp = head;
    Node *deleteNode;
    int currentPosition = 1;
    while(currentPosition<position - 1 && temp!= nullptr){
        temp = temp->next;
        currentPosition++;
    }
    if(temp == nullptr || temp->prev == nullptr){
        cout << "Invalid position!" << endl;
        return head;
    }
    deleteNode = temp->prev;
    if(deleteNode->prev != nullptr){
        deleteNode->prev->next = temp;
    }else{

        head = temp;
    }
    temp->prev = deleteNode->prev;

    delete deleteNode;
    return head;

}

Node *deleteLastNode(Node *head){

    if(head == nullptr){
        cout <<   "List is empty" << endl;
        return nullptr;
    }
    if(head->next == nullptr){
            delete head;
            return  head;
    }
    Node *temp = head;
    while(temp->next->next!=nullptr){
        temp=temp->next;
    }

    delete temp->next;
    temp->next = nullptr;

    return head;
}

void displayList(Node *head){

        if(head == nullptr){
            cout <<   "List is empty" << endl;
        }
        Node *temp = head;
        while(temp->next != nullptr){
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << temp->data << " -> " << nullptr << endl;
    }

int main()
{
    Node *head = new Node(2);
    head->next = new Node(3);
    head->next->prev = head;
    head->next->next = new Node(4);
    head->next->next->prev = head->next;
    displayList(head);
    int data = 1;
    head = insertAtBeginning(head , data);
    displayList(head);
    cout << "*********" << endl;
    head = insertAfter(head,10 , 6);
    displayList(head);
    cout << "*********" << endl;
    head = insertAtEnd(head , 58);
    displayList(head);
    cout << "Deleted at beginning node" << endl;
    head = deleteAtBeginning(head);
    displayList(head);

    int deletePosition = 2;
    cout << "Deleted at position node : " << deletePosition << endl;
    head = deleteAtPosition(head ,deletePosition);
    displayList(head);


    int deletePositionbefore = 2;
    cout << "Deleted at position node before  : " << deletePositionbefore << endl;
    head = deleteBeforeNode(head ,deletePositionbefore);
    displayList(head);

    cout << "Deleted last node " << endl;
    head = deleteLastNode(head);
    displayList(head);

    return 0;
}
