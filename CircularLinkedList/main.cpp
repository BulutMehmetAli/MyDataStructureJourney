#include <iostream>

using namespace std;


struct Node{

    int data;
    Node *next;

    Node(int value){
        data = value;
        next = nullptr;
    }
};

Node *insertInEmptyList(Node *last , int data){

    if (last != nullptr){
        return last;
    }
    Node *newNode = new Node(data);
    newNode->next = newNode;
    last = newNode;
    return last;
}

Node *insertAtBeginning(Node *last , int data){

    Node *newNode = new Node(data);
    if(last ==  nullptr){
        newNode->next = newNode;
        last = newNode;
        return last;
    }
    newNode->next = last->next;
    last->next =  newNode;
    return last;
}


Node *insertAtEnd(Node *last , int data){

    Node *newNode = new Node(data);
    if(last ==  nullptr){
        newNode->next = newNode;
        last = newNode;
        return last;
    }

    newNode->next = last->next;
    last->next = newNode;
    last = newNode;

    return last;
}
int lengthOfTheList(Node *last){
    if(last == nullptr) return 0;
    Node *temp = last->next;
    int counter = 1;
    while(temp!=last){
        counter++;
        temp = temp->next;

    }

    return counter;
}
Node *insertAtSpesificPosition(Node *last , int data , int position){

    if(last ==  nullptr){
        cout << "List is empty. Cannot insert at position " << position << endl;
        return last;
    }
    if (position < 1) {
        cout << "Position must be greater than or equal to 1!" << endl;
        return last;
    }
    if(position==1){
        return insertAtBeginning(last , data);
    }
    int length = lengthOfTheList(last);
    if(position > length + 1){
        cout << "Out of bound !!!" << endl;
        return last;
    }

    Node *newNode = new Node(data);
    position-=2;
    Node *temp = last->next;
    while(position>0){
        temp= temp->next;
        position--;
    }
    newNode->next = temp->next;
    temp->next = newNode;

    if(temp == last){
        last = newNode;
    }
    return last;


}



void displayNodes(Node *last){

    if(last == nullptr){
        cout << "List is empty." << endl;
        return;
    }
    Node *temp = last->next;
    while(true){

        cout << temp->data << " -> ";
        temp = temp->next;
        if(temp == last->next) break;

    }
    cout << endl;
}

int main()
{
    Node *last = nullptr;
    last = insertInEmptyList(last , 5);
    displayNodes(last);

    last = insertAtEnd(last , 10);
    last = insertAtEnd(last , 11);
    last = insertAtEnd(last , 12);
    last = insertAtEnd(last , 13);
    last = insertAtEnd(last , 14);
    last = insertAtEnd(last , 15);
    displayNodes(last);

    last = insertAtBeginning(last , 0);
    displayNodes(last);

    cout << "****" << endl;
    last = insertAtSpesificPosition(last , 58 , 5);
    displayNodes(last);

    return 0;
}

