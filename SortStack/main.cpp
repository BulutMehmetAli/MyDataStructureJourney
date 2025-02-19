#include <iostream>
#include <stack>
using namespace std;

stack<int> sortedStack(stack<int> &s){
    stack<int> tmpstack;
    int temp;
    while(!s.empty()){
            temp = s.top();
            s.pop();
            while(!tmpstack.empty() && temp<tmpstack.top()){
                s.push(tmpstack.top());
                tmpstack.pop();
            }
            tmpstack.push(temp);
    }
    while(!tmpstack.empty()){
        s.push(tmpstack.top());
        tmpstack.pop();
    }
    return s;
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
    stack<int> tmpStack = sortedStack(inputStack);
    while (!tmpStack.empty())
    {
        cout << tmpStack.top()<< " ";
        tmpStack.pop();
    }
    return 0;
}
