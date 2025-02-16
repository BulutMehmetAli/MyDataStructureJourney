#include <iostream>
#include <stack>

using namespace std;

void generateFunction(stack<int> &s , int n){
    if(n==1){
        s.pop();
        return;
    }
    int temp = s.top();
    s.pop();
    generateFunction(s,n-1);
    s.push(temp);
}

void deleteMiddleElement(stack<int> &s){
    int n = s.size();
    if(!s.empty()){
        generateFunction(s,n);
    }
}

int main()
{
    stack<int> inputStack;
    inputStack.push(5);
    inputStack.push(3);
    inputStack.push(31);
    inputStack.push(98);
    inputStack.push(92);
    inputStack.push(23);
    inputStack.push(6);
    inputStack.push(3);
    deleteMiddleElement(inputStack);

    while(!inputStack.empty()){
        cout << inputStack.top() << " ";
        inputStack.pop();
    }
    return 0;
}
