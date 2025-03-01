#include <iostream>
#include <queue>
using namespace std;

class Stack{
private:
    queue<int> q;
public:

    void push(int data){
        int sizeOfStack = q.size();
        q.push(data);
        for(int i = 0;i<sizeOfStack;i++){
            q.push(q.front());
            q.pop();
        }
    }
    void pop(){
        if(q.empty()){
            cout << "Stack is empty" << endl;
        }else{
            q.pop();
        }
    }
    int top(){
        if(q.empty()){
            cout << "Stack is empty" << endl;
            return -1;
        }
        return q.front();
    }
    int isEmpty(){
        if(q.empty()){
            return 1;
        }return -1;
    }
    void display(){
        if(q.empty()){
            cout << "Queue is empty " << endl;
            return;
        }
        for(int i = 0;i<q.size();i++){
            q.push(q.front());
            cout << q.front() << " " ;
            q.pop();
        }cout << endl;
    }

};
int main()
{
    Stack myStack;
    myStack.push(5);
    myStack.push(6);
    myStack.push(1);
    myStack.push(9);
    myStack.push(8);
    myStack.push(4);
    myStack.pop();
    myStack.display();

    myStack.display();

    return 0;
}
