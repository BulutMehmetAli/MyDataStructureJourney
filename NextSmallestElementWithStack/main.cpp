#include <iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> nextSmallestElement(vector<int> &arr){
    int n = arr.size();
    stack<int> myStack;
    vector<int> newArr(n,-1);
    for(int i=n-1;i>=0;i--){
        while(!myStack.empty() && arr[i]<=myStack.top()){
                myStack.pop();
        }
        if(!myStack.empty()){
            newArr[i]=myStack.top();
        }
        myStack.push(arr[i]);

    }
    return newArr;
}


int main()
{
    vector<int> arr = {3,4,8,5,2,25};
    vector<int> res = nextSmallestElement(arr);
    for (int x : res) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
