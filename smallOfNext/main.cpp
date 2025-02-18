#include <iostream>
#include<vector>
#include<stack>
#include<algorithm>
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
vector<int> x(vector<int> &arr){
    int n = arr.size();
    vector<int> arr1 = nexGreaterElement(arr);
    vector<int> arr2(n,-1);
    vector<int> arr3 = nextSmallestElement(arr);
    vector<int> lastvector(n,-1);
    for(int i = 0;i<n;i++){
        for (int j = 0 ;j<n;j++){
            if(arr1[i]==arr[j]){
                arr2[i]=j;
            }else if(arr1[i]==-1){
                arr2[i]=-1;
            }
        }
    }
    for (int i = 0; i<n;i++){
        if(arr2[i]==-1){
            lastvector[i]=-1;
        }else{
                lastvector[i] = arr3[arr2[i]];
        }

    }
    return lastvector;
}

int main()
{
    vector<int> arr = {5,1,9,2,5,1,7};
    vector<int> res = x(arr);
    for (int x : res) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
