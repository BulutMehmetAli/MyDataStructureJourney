#include <iostream>
using namespace std;
#include <clocale>


class Stack {
private:
    int* data;
    const int size;
    int top;
public:
    explicit Stack(int stackSize) : size(stackSize), top(-1) {
        data = new int[size];
    }

    ~Stack() {
        delete[] data;
        cout << "Stack cleaned from memory." << endl;
    }

    bool isFull() const {
        return top == size - 1;
    }

    bool isEmpty() const {
        return top == -1;
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack is empty" << endl;
            return;
        }
        data[++top] = value;
        cout << value << " append in stack." << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout <<  data[top--] << " popped stack." << endl;
    }

    void peek() const {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Top value: " << data[top] << endl;
    }

    void clear() {
        top = -1;
        cout << "Stack cleaned" << endl;
    }

    void display() const {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        for (int i = 0; i <= top; ++i) {
            cout << data[i] << " -> ";
        }
        cout << endl;
    }
};

int main() {
    Stack myStack(5);

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.display();

    myStack.pop();
    myStack.display();

    myStack.peek();

    myStack.clear();
    myStack.display();
    myStack.~Stack();

    return 0;
}
