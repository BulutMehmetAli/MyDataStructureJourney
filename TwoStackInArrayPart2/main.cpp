#include <iostream>

using namespace std;

class twoStack{

private:
    int *arr;
    int sizeOfStack;
    int top1,top2;
public:
    twoStack(int n){
        sizeOfStack = n;
        arr = new int[sizeOfStack];
        top1 = -1;
        top2 = n-1;
    }

    void push1(int value){
        if(top2-top1>1){
            arr[++top1] = value;
            cout << value << " added into stack1 " << endl;
        }else{
            cout << "Stack is overflow";
        }
    }
    void push2(int value){
        if(top2-top1>1){
            arr[--top2] = value;
            cout << value << " added into stack2 " << endl;
        }else{
            cout << "Stack is overflow";
        }
    }
    void pop1(){
        if(top1>=0 && top1<=sizeOfStack-1){
            int data = arr[top1--];
            cout << data << " popped from stack1" << endl;
       }else{
            cout << "Stack1 is empty !!!" << endl;
        }
    }
    void pop2(){
        if(top2>=0 && top2<=sizeOfStack-1){
            int data = arr[top2++];
            cout << data << " popped from stack1" << endl;
       }else{
            cout << "Stack1 is empty !!!" << endl;
        }

    }
    void displayStack1(){
        int temp = top1;
        while(temp>-1){
            cout << arr[temp] << " ";
            temp--;
        }
        cout << endl;
    }
    void displayStack2(){
        int temp = top2;
        while(temp<sizeOfStack-1){
            cout << arr[temp] << " ";
            temp++;
        }
        cout << endl;
    }
    // Destructor
    ~twoStack() {
        delete[] arr;
    }
};

int main()
{
    twoStack myStack(10);

    myStack.push1(20);
    myStack.push1(30);
    myStack.push1(40);
    myStack.push1(50);
    myStack.displayStack1();

    myStack.push2(90);
    myStack.push2(80);
    myStack.push2(70);
    myStack.displayStack2();

    myStack.pop1();
    myStack.pop2();
    myStack.displayStack1();
    myStack.displayStack2();
    return 0;
}
