#include <iostream>
#include <stack>
using namespace std;

int precedence(char op){
    if(op=='+'|| op=='-'){
        return 1;
    }else if(op=='*' || op=='/'){
        return 2;
    }else if(op=='^'){
        return 3;
    }else{
        return -1;
    }
}
string convertProcess(string s){
    int n = s.size();
    string postFix = "";
    stack<string> myStack;
    for(int i= 0;i<n;i++){
        if(isalnum(s[i])){
            postFix.append(1,s[i]);
        }else if(s[i]=='('){
            myStack.push(string(1,s[i]));
        }else if(s[i]==')'){
            while (!myStack.empty() && myStack.top() != string(1, '(')){
                    postFix.append(myStack.top());
                    myStack.pop();
                  }
                  myStack.pop();
        }else{
            while(!myStack.empty() && precedence(myStack.top()[0])>=precedence(s[i])){
                    postFix.append(myStack.top());
                    myStack.pop();
            }
            myStack.push(string(1,s[i]));
        }
    }
    if(!myStack.empty()){
        while(!myStack.empty()){
                postFix.append(myStack.top());
                myStack.pop();
        }
    }
    return postFix;
}
string convertPrefix(string s) {
    s = string(s.rbegin(), s.rend());

    for (char& c : s) {
        if (c == '(') c = ')';
        else if (c == ')') c = '(';
    }
    s = convertProcess(s);
    s = string(s.rbegin(), s.rend());
    return s;
}
int main()
{
    string expression = "(3+4)*(242-84)+(8+2)/243";
    string newStringExpression = convertPrefix(expression);
    cout << newStringExpression << endl;

    return 0;
}
