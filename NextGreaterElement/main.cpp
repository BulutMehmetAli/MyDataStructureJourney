#include <iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> nexGreaterElement(vector<int> &arr){
    stack<int> myStack;
    int n = arr.size();
    vector<int> newArr(n,-1);
    for (int i = n-1; i>=0;i--){
        while(!myStack.empty() && myStack.top()<=arr[i]){
            myStack.pop();
        }
        if(!myStack.empty()){
            newArr[i] = myStack.top();
        }
        myStack.push(arr[i]);
    }
    return newArr;
}
int main(){
    vector<int> arr = {6, 8, 0, 4, 3};
    vector<int> res = nexGreaterElement(arr);
    for (int x : res) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
