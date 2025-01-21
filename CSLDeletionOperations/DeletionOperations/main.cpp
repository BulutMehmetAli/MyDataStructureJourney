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

Node *deleteFirstNodeInList(Node *last){

    if(last == nullptr){
        return nullptr;
    }

    if(last->next == last){
        delete last;
        return nullptr;
    }

    Node *temp = last->next;
    last->next = last->next->next;
    delete temp;
    return last;


}
int lengthOfTheList(Node *last){

    if(last == nullptr){
        cout << "List is empty(size is 0) !!!" ;
        return 0;
    }
    int counter = 1;
    Node *temp = last;
    while(temp->next!=last){
        temp = temp->next;
        counter++;
    }
    return counter;
}

Node *deleteSpesicifLocation(Node *last , int position){

    if(last ==  nullptr){
        cout << "List is empty. Cannot insert at position " << position << endl;
        return last;
    }
    if (position < 1) {
        cout << "Position must be greater than or equal to 1!" << endl;
        return last;
    }
    if(position==1){
        return deleteFirstNodeInList(last);
    }
    int length = lengthOfTheList(last);
    if(position > length){
        cout << "Out of bound !!!" << endl;
        return last;
    }
    Node *temp = last->next;
    Node *prev = nullptr;
    int counter = 1;

    while(counter < position){
        prev = temp;
        temp = temp->next;
        counter++;
    }

    if(temp == last){
        last = prev;
    }
    prev->next = temp->next;
    delete temp;

    return last;

}

Node *deleteLastNode(Node *last){

    if(last == nullptr){
        cout << "List is empty !!! " << endl;
        return nullptr;
    }
    Node *temp = last->next;
    if(temp ==  last){
        delete temp;
        last = nullptr;
        return last;
    }
    while(temp->next != last){
        temp = temp->next;
    }
    temp->next = last->next;
    delete last;
    last = temp;

    return last;
}

bool searchingNode(Node *last , int value){
    if(last == nullptr){
        cout << "List is empty !!! " << endl;
        return 0;
    }
    Node *temp = last->next;
    if(temp == last){
        if(value == last->data){
            return 1;
        }
    }
    while(temp->next != last)
    {
        if(value == temp->data){
            return 1;
        }
        temp=temp->next;
    }

    return 0;

}

void displayList(Node *last){

    if(last == nullptr){
        cout << "List is empty !!!" << endl;
        return;
    }
    Node *temp = last->next;
    while(last){
        cout << temp->data << " -> " ;
        temp = temp->next;
        if(temp == last->next) break;
    }
    cout << endl;

}

int main()
{
    Node* first = new Node(2);
    first->next = new Node(3);
    first->next->next = new Node(4);
    first->next->next->next = new Node(5);
    first->next->next->next->next = new Node(6);
    first->next->next->next->next->next = new Node(7);
    first->next->next->next->next->next->next = new Node(8);
    first->next->next->next->next->next->next->next = new Node(9);

    Node* last = first->next->next->next->next->next->next->next;
    last->next = first;


//    last = deleteFirstNodeInList(last);
//
    displayList(last);
//
//    cout << "*******" << endl;
//
//    last = deleteSpesicifLocation(last , 3);
//    displayList(last);


//    last = deleteLastNode(last);
//    last = deleteLastNode(last);
//    last = deleteLastNode(last);
//    displayList(last);

    bool result = searchingNode(last , 33 );
    cout << result << endl;

    return 0;
}
