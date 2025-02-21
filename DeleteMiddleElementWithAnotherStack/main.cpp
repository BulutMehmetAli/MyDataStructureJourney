#include <iostream>
#include <stack>
using namespace std;
void deleteMiddleElement(stack<int> &s){
    int n = s.size()/2;
    stack<int> tempStack;
    while(n>0){
        tempStack.push(s.top());
        s.pop();
        n--;
    }s.pop();
    while(!tempStack.empty()){
        s.push(tempStack.top());
        tempStack.pop();
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
    deleteMiddleElement(inputStack);

    while(!inputStack.empty()){
        cout << inputStack.top() << " ";
        inputStack.pop();
    }

    return 0;
}
