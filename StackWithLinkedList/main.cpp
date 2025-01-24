#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;
    int sizeOfStack;

public:
    Stack() {
        top = nullptr;
        sizeOfStack = 0;
    }

    bool isEmpty() const {
        return top == nullptr;
    }

    int getSize() const {
        return sizeOfStack;
    }

    void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        sizeOfStack++;
        cout << value << " append onto stack." << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty!!!" << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        cout << temp->data << " popped from stack" << endl;
        delete temp;
        sizeOfStack--;
    }

    void peek() const {
        if (isEmpty()) {
            cout << "Stack is empty!!!" << endl;
            return;
        }
        cout << "Upper data:" << top->data << endl;
    }

    bool search(int value) const {
        Node* current = top;
        while (current != nullptr) {
            if (current->data == value) {
                cout << value << " stack has " << endl;
                return true;
            }
            current = current->next;
        }
        cout << value << " there is no in stack" << endl;
        return false;
    }

    void reverse() {
        Node* prev = nullptr;
        Node* current = top;
        Node* nextNode = nullptr;

        while (current != nullptr) {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        top = prev;
        cout << "Stack reversed" << endl;
    }

    int* toArray() const {
        if (isEmpty()) {
            cout << "Stack is empty!!!" << endl;
            return nullptr;
        }

        int* arr = new int[sizeOfStack];
        Node* current = top;
        for (int i = 0; i < sizeOfStack; i++) {
            arr[i] = current->data;
            current = current->next;
        }

        cout << "Stack transferred to array" << endl;
        return arr;
    }

    void display() const {
        if (isEmpty()) {
            cout << "Stack is empty!!!" << endl;
            return;
        }
        Node* current = top;
        cout << "Stack values: ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
        cout << "Stack cleaned from the memory" << endl;
    }
};

int main() {
    Stack myStack;

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.display();

    cout << "Stack boyutu: " << myStack.getSize() << endl;

    myStack.search(20);
    myStack.search(50);

    myStack.reverse();
    myStack.display();

    int* array = myStack.toArray();
    if (array != nullptr) {
        cout << "Dizi elemanlarý: ";
        for (int i = 0; i < myStack.getSize(); i++) {
            cout << array[i] << " ";
        }
        cout << endl;
        delete[] array;
    }

    return 0;
}
