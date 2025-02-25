#include <iostream>

using namespace std;
struct Node{
    int data;
    int priority;
    Node *next;
};

class priorityQueue{
private:
    Node *head;
public:
    priorityQueue(){
        head = nullptr;
    }

    bool isEmpty(){
        if(head == nullptr){
            return true;
        }return false;
    }
    void enqueue(int data , int priority){

        Node *newNode = new Node();
        newNode -> data = data;
        newNode -> priority = priority;
        newNode -> next = nullptr;

        if(head == nullptr || newNode->priority > head->priority){
           newNode->next = head;
           head = newNode;
        }
        else{
            Node *temp = head;
            while(temp->next != nullptr && temp->next->priority>= priority){
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
    void dequeuPriority(){
        Node *temp = head;
        head = head -> next;
        delete temp;
    }
    void display(){
        if(isEmpty()){
            cout << "Queue is empty" << endl;
            return;
        }else{
            Node *temp = head;
            while(temp != nullptr){
                cout << temp->data << " (Priority: " << temp->priority << ") -> " ;
                temp = temp->next;
            }
            cout << "NULL";
        }
    }

};
int main()
{
    priorityQueue pri;
    pri.enqueue(10,2);
    pri.enqueue(11,4);
    pri.enqueue(12,5);
    pri.enqueue(15,5);
    pri.enqueue(14,5);
    pri.display();

    return 0;
}
//Ýmplement array queue
//
//item pr[100000];
//// En son eklenen elemanýn indeksini tutan deðiþken
//int sizeOfQueue = 0;
//void enqueue(int value , int priority){
//
//    sizeOfQueue++;
//    pr[sizeOfQueue].data = value;
//    pr[sizeOfQueue].priortiy = priority;
//}
//int peek(){
//    int highestPriortiy = INT_MIN;
//    int ind = -1;
//    for(int i = 0;i<sizeOfQueue;i++){
//            if(highestPriortiy == pr[i].priortiy && ind>-1 &&
//               pr[ind].data <pr[i].data){
//                    highestPriortiy = pr[i].priortiy;
//                    ind = i;
//               }else if(highestPriortiy < pr[i].priortiy){
//                   highestPriortiy = pr[i].priortiy;
//                   ind = i;
//               }
//    }
//    return ind;
//}
//void dequ(){
//    int ind = peek();
//    for(int i = 0;i< sizeOfQueue; i++){
//        pr[i] = pr[i+1];
//    }
//    sizeOfQueue--;
//}
