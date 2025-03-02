#include <iostream>
#include <stack>
using namespace std;

class Queue{
public:
    stack<int> s1,s2;

    bool isEmpty(){
        return  s1.empty();
    }
    void pushdata(int data){
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }s1.push(data);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    void popData(){
        s1.pop();
    }
    void display(){
        stack<int> temp3 = s1;
        while(!temp3.empty()){
            cout << temp3.top() << " " ;
            temp3.pop();
        }
        cout << endl;
    }
};

int main()
{
    Queue myQueue;
    myQueue.pushdata(5);
    myQueue.pushdata(4);
    myQueue.pushdata(3);
    myQueue.pushdata(2);
    myQueue.pushdata(1);
    myQueue.popData();
    myQueue.display();
    cout << "*****" << endl;
    myQueue.display();

    return 0;
}
