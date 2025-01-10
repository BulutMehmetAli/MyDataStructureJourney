#include <iostream>

using namespace std;

struct Node{

    int data;
    Node *next ;

};
class LinkedList{
private:
    Node *head;//Pointer to the first node in the list
public:

    LinkedList() : head(NULL){}

    // Function to Insert a new node at the beginning of the list
    void insertAtBeggining(int value){
        Node *newNode = new Node();
        newNode -> data = value;
        newNode -> next = head;
        head = newNode;
    }

    void insertAtPosition(int value, int position) {
        if(position == 1){
            insertAtBeggining(value);
            return;
        }
        if(position < 1){
            cout << "Position shoul be bigger than 0" << endl;
        }
        Node *newNode = new Node();
        newNode->data = value;
        Node *temp = head;
        position = position-2;
        while(position>0){

                temp=temp->next;
                position = position -1;
        }
        if(!temp){
            cout << "Position out of range." << endl;
            delete newNode;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void insertAtEnd(int value){
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        if(!head){
            head = newNode;
            return;
        }

        Node *temp = head;
        while(temp->next){
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void deleteFromBeginning() {
        if(!head){
            cout << "List is empty !!! " << endl;
            return;
        }
        Node *temp = head;
        head=head->next;
        delete temp;

    }

    void deleteFromEnd(){
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
        if(!head->next){
            delete head;
            head = NULL;
            return;
        }
         Node *temp = head;
         while(temp->next->next){
            temp=temp->next;
         }
         delete temp->next;
         temp->next=NULL;
    }

    void deleteFromPosition(int position) {
        if(position <1){
            cout << "Position should be bigger than 0." << endl;
            return;
        }
        if(position == 1){
            deleteFromBeginning();
            return;
        }
        Node *temp = head;
        position = position - 2;
        while(position>0){
            temp=temp->next;
            position--;
        }
        if(!temp || !temp->next){
            cout << "Position out of range." << endl;
            return;
        }
        Node *nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }

    void displayNodes(){
        if(!head){
            cout << "List is empty!" << endl;
            return;
        }
        cout << "List is : " ;
        Node *temp = head;
        while(temp){
            if(temp->next == NULL){
                break;
            }
            cout << temp->data << " -> ";
            temp = temp->next;

        }
         cout << temp->data << endl;
        //cout << "NULL" << endl;
    }
    int lengthOfLinkedList(){
        Node *temp = head;
        int counter = 1;
        while(temp->next!=NULL){
            counter++;
            temp=temp->next;
        }
        return counter;
    }
    /* Alternative length of linkedList
    int lengthOfLinkedList(){
        Node *temp = head;
        int counter = 0;
        while(temp){
            temp=temp->next;
            counter++;
        }
        return counter;
    }*/

    void searchKey(int value){
        int position = 0;
        if(!head){
            cout << "List is empty!!!" << endl;
            return;
        }
        Node *temp = head;
        while (temp){
            position++;
            if(temp->data == value){
                cout << "Value is available. Value:" << value <<  endl;
                cout << "Value position is :" << position << endl;
                return;
            }
            temp=temp->next;
        }
        cout << "Value is not available" << endl;
    }
    void deleteLinkedlist(){
        Node *temp;
        while(head){
            temp = head;
            head = head->next;
            delete temp;
        }
        cout << "Linked list deleted successfully." << endl;
    }

};


int main()
{
    LinkedList l1;

    l1.insertAtBeggining(5);
    l1.insertAtEnd(123);
    l1.insertAtEnd(111);
    l1.insertAtEnd(102);
    l1.insertAtEnd(105);
    l1.insertAtEnd(106);
    l1.insertAtEnd(1226);
    l1.insertAtEnd(1107);
    l1.insertAtEnd(11073);
    l1.deleteFromPosition(3);
    l1.displayNodes();
    cout << l1.lengthOfLinkedList() << endl;
    l1.searchKey(105);
    l1.deleteLinkedlist();
    l1.displayNodes();
    return 0;
}
