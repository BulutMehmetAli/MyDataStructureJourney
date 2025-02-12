#include <bits/stdc++.h>
using namespace std;

class twoStack{
private:
    int *arr;
    int sizeOfStack;
    int top1;
    int top2;
public:
    twoStack(int n){
       sizeOfStack = n;
       arr = new int[n];
       top1 = -1;
       top2 = (sizeOfStack/2)-1;
    }
    void push1(int data){
        if(top1<(sizeOfStack/2)-1){
            arr[++top1]=data;
            cout << data << " added into Stack1." << endl;
        }else{
            cout << "Stack is Full !!!" << endl;
        }
    }
    void push2(int data){
        if(top2<sizeOfStack-1){
            arr[++top2] = data;
            cout << data << " added into Stack2." << endl;
        }else{
            cout << "Stack is Full !!!" << endl;
        }
    }
    void pop1(){
        if(top1>=0){
            int data = arr[top1];
            top1--;
            cout << data << " popped from stack1" << endl;
        }else{
            cout << "Stack is empty" << endl;
        }
    }
    void pop2(){
        if(top2>=sizeOfStack/2){
            int data = arr[top2];
            top2--;
            cout << data << " popped from stack2" << endl;
        }else{
            cout << "Stack is empty" << endl;
        }
    }
    void displayStack1() {
        int temp = top1;
        while (temp >= 0) {
            cout << arr[temp] << " ";
            temp--;
        }
        cout << endl;
    }
    void displayStack2() {
        int temp = top2;
        while (temp > (sizeOfStack/2)-1) {
            cout << arr[temp] << " ";
            temp--;
        }
        cout << endl;
    }

};

int main()
{
    twoStack myStack(10);
    myStack.push2(10);
    myStack.push2(20);
    myStack.displayStack2();

	return 0;
}
