#include <iostream>

using namespace std;

const int MAX_SIZE = 8;
class Queue{
private:
    int arr[MAX_SIZE];
    int head;
    int sizeOfQueue;
    int rear;
public:
    Queue(){
        head = -1;
        rear = -1;
        int sizeOfQueue=0;
    }
    bool isEmpty(){
        if (head == -1 && rear == -1){
            return true;
        }return false;
    }
    bool isFull(){
        if(rear == MAX_SIZE-1){
            return true;
        }return false;
    }
    void enqueue(int value){
        if(isFull()){
            cout << "Queue overflow !!!" << endl;
            return;
        }
        if(isEmpty()){
                head=0;
                rear++;
                arr[head]=value;
                sizeOfQueue++;
        }else{
                rear++;
                arr[rear] = value;
                sizeOfQueue++;

        }
            cout << value << " added into queue" << endl;

    }
    void dequeue(){
        if(isEmpty()){
            cout << "Queue underflow !!!";
            return;
        }else{
            int value = arr[head];
            head++;
            sizeOfQueue--;
            cout << value << " removed onto queue" << endl;
        }
    }
    void display(){
        if(isEmpty()){
            cout << "Queue is empty !!!" ;
            return;
        }
        cout << "Queue elements is : " ;
        for (int i = head;i<=rear;i++){
            cout << arr[i] << " ";
        }
    }
    int getPeek(){
        if(isEmpty()){
            cout << "Queue is empty !!!" ;
            return -1;
        }
        return arr[head];
    }
    int getSize(){
        if(isEmpty()){
            cout << "Queue is empty !!!" ;
            return -1;
        }
        return sizeOfQueue;
    }
    int getRear(){
        if(isEmpty()){
            cout << "Queue is empty !!!" ;
            return -1;
        }
        return arr[rear];
    }
    int getCapacity(){
        return MAX_SIZE;
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

    myQueue.enqueue(9);
    myQueue.dequeue();
    myQueue.display();
    cout << endl;
    int peek = myQueue.getSize();
    cout << peek << endl;



    return 0;
}
