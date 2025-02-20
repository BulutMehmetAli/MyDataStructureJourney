#include <iostream>
#include <stack>
using namespace std;

void deleteMiddleElement(stack<int> &s , int h){
   if(h==0){
        s.pop();
        return;
    }
    int temp = s.top();
    s.pop();
    deleteMiddleElement(s,h-1);
    s.push(temp);
}
void halt(stack<int> &s){
    int n;
    if(!s.empty()){
        n=s.size()/2;
        if(n%2==0){
            deleteMiddleElement(s,n-1);
        }else{
            deleteMiddleElement(s,n);
        }
    }
}
int main()
{
    stack<int> inputStack;
    inputStack.push(34);
    inputStack.push(3);
    inputStack.push(31);
    inputStack.push(98);
    inputStack.push(92);
    inputStack.push(23);
    inputStack.push(6);
    inputStack.push(3);
    halt(inputStack);

    while(!inputStack.empty()){
        cout << inputStack.top() << " ";
        inputStack.pop();
    }
    return 0;
}

