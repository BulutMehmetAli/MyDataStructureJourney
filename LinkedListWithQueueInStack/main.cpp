#include <iostream>
using namespace std;

// ✅ 1. Defining the Node Structure (For Linked List Implementation of Queue)
struct Node {
    int data;
    Node* next;

    // Constructor to initialize a node with a value
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// ✅ 2. Queue Implementation Using Linked List
class Queue {
private:
    Node* front; // Pointer to the front of the queue
    Node* rear;  // Pointer to the rear of the queue
    int size;    // Variable to track the size of the queue

public:
    // Constructor initializes an empty queue
    Queue() {
        front = nullptr;
        rear = nullptr;
        size = 0;
    }

    // Enqueue (Insert element at the rear)
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (rear == nullptr) { // If the queue is empty, set both front and rear
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    // Dequeue (Remove element from the front)
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        Node* temp = front;  // Store the front node temporarily
        int value = temp->data;
        front = front->next; // Move front pointer to the next node
        if (front == nullptr) { // If queue becomes empty, reset rear
            rear = nullptr;
        }
        delete temp;  // Free memory of the removed node
        size--;
        return value;
    }

    Node *getfront(){
        return front;
    }

    // Peek (Retrieve the front element without removing it)
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return front->data;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return (front == nullptr);
    }

    // Get the size of the queue
    int getSize() {
        return size;
    }
};

// ✅ 3. Implementing Stack Using Two Queues
class Stack {
private:
    Queue q1, q2; // Two queues for stack operations
    int curr_size; // Variable to track stack size

public:
    // Constructor initializes an empty stack
    Stack() {
        curr_size = 0;
    }

    // Push operation (Insert element)
    void push(int value) {
        q2.enqueue(value); // Insert the new element into q2

        // Move all elements from q1 to q2 to maintain stack order
        while (!q1.isEmpty()) {
            q2.enqueue(q1.dequeue());
        }

        // Swap q1 and q2 to keep the newest element on top
        Queue temp = q1;
        q1 = q2;
        q2 = temp;

        curr_size++; // Increase stack size
    }

    // Pop operation (Remove top element)
    int pop() {
        if (q1.isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        curr_size--; // Decrease stack size
        return q1.dequeue(); // Remove and return the front element (stack top)
    }

    void display(){
        Node *temp = q1.getfront();
        while(temp!=nullptr){
            cout << temp->data << " " ;
            temp=temp->next;
        }
    }

    // Peek (Retrieve top element without removing it)
    int top() {
        if (q1.isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return q1.peek();
    }

    // Check if the stack is empty
    bool isEmpty() {
        return (curr_size == 0);
    }

    // Get the size of the stack
    int size() {
        return curr_size;
    }
};

// ✅ 4. Main Program (Testing the Stack Implementation)
int main() {
    Stack myStack;

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.push(40);

    cout << "Stack Top: " << myStack.top() << endl; // Expected Output: 40
    cout << "Stack Pop: " << myStack.pop() << endl; // Expected Output: 40
    cout << "Stack Top: " << myStack.top() << endl; // Expected Output: 30
    cout << "Stack Pop: " << myStack.pop() << endl; // Expected Output: 30

    cout << "Stack Size: " << myStack.size() << endl; // Expected Output: 2

    myStack.display();
    return 0;
}
