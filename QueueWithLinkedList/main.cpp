#include <iostream>

using namespace std;

struct Node{

    int data;
    Node *next;
};

class Queue{

private:

    Node *head;
    Node *rear;
    int sizeOfQueue;
public:

    Queue(){
        head = nullptr;
        rear = nullptr;
        sizeOfQueue = 0;
    }

    bool isEmpty(){
        if(head == nullptr && rear == nullptr){
            return true;
        }return false;
    }
    void enqueue(int value){
        Node *newNode = new Node();
        newNode->data = value;
        if(isEmpty()){
            head = newNode;
            rear = newNode;
            newNode->next = nullptr;
            sizeOfQueue++;
        }else{
            rear->next = newNode;
            rear = newNode;
            newNode->next = nullptr;
            sizeOfQueue++;
        }
    }
    void dequeue(){

        if(isEmpty()){
            cout << "This queue is empty !!!" << endl;
            return;
        }else{
            Node *temp = head;
            head = head->next;
            delete temp;
            sizeOfQueue--;
        }

    }
    void display(){
        if(isEmpty()){
            cout << "This queue is empty" << endl;
            return;
        }else{
            Node *temp = head;
            while(temp != nullptr){
                    cout <<  temp->data << " -> " ;
                    temp = temp->next;
            }
            cout << "NULL";
        }
    }
    int getPeek(){
        if(isEmpty()){
            cout << "This queue is empty" << endl;
            return -1 ;
        }
        return head->data;
    }
    int getRear(){
        if(isEmpty()){
            cout << "This queue is empty" << endl;
            return -1 ;
        }
        return rear->data;
    }
    int getSize(){
        if(isEmpty()){
            cout << "This queue is empty" << endl;
            return -1 ;
        }
        return sizeOfQueue;
    }
};
int main()
{
Queue myQueue;
    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);
    myQueue.enqueue(4);
    myQueue.enqueue(5);
    myQueue.enqueue(6);
    myQueue.enqueue(7);
    myQueue.enqueue(8);
    myQueue.dequeue();
    myQueue.enqueue(9);
    myQueue.display();
    cout << endl;
    int x = myQueue.getSize();
    cout << x << endl;
    return 0;
}
