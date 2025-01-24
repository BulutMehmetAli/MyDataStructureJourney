#include <iostream>

using namespace std;

const int MAX_SIZE = 5;

class Stack{
private:
    int arr[MAX_SIZE];
    int top;
public:
    Stack(){
        top=-1;
    }
    bool isEmpty(){
        return (top == -1);
    }
    bool isFull(){
        return top == MAX_SIZE-1;
    }
    int topData(){
        if(!isEmpty()){
            return arr[top];
        }else{
            cout << "Stack is empty!!! " << endl;
            return -1;
        }
    }
    void push(int value){
        if(!isFull()){
            top++;
            arr[top] = value;
            cout << "Pushed element:" << value << " onto the stack" << endl;
        }else{
            cout << "Stack overflow !!!" << endl;
        }
    }
    void pop(){
        if(!isEmpty()){
            int poppedData = arr[top];
            top--;
            cout << "Popped element: " << poppedData << " from the stack" << endl;
        }else{
            cout << "Stack is empty !!!" << endl;
        }
    }
    int sizeOfStack(){
        return top + 1;
    }

};
int main()
{
    Stack myStack;
    for (int i = 1; i <= 5; ++i) {
        myStack.push(i);
    }
    cout << myStack.isFull() << endl;
    cout << myStack.sizeOfStack() << endl;//*
    cout << myStack.topData() << endl;//

    myStack.pop();
    cout << myStack.sizeOfStack() << endl;//*

    myStack.push(6);
    cout << myStack.topData() << endl;

    cout << myStack.sizeOfStack() << endl;//*

    myStack.push(9);
    myStack.push(99);

    myStack.pop();
    myStack.pop();
    myStack.pop();
    myStack.pop();
    myStack.pop();
    myStack.pop();

    return 0;
}
