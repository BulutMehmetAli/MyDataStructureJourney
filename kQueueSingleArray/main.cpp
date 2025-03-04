#include <iostream>
#include<climits>

using namespace std;

class kQueue{
public:
    int *arr;
    int *frontQueue;
    int *rearQueue;
    int *next;
    int freeSpot;
    int n,k;
    kQueue(int n , int k){
        this->n = n;
        this->k = k;
        arr = new int[n];
        next = new int[n];
        frontQueue = new int[k];
        rearQueue = new int[k];
        freeSpot = 0;
        for(int i=0;i<n;i++){
            next[i] = i+1;
        }
        next[n-1] = -1;
        for(int i=0;i<k;i++){
            frontQueue[i] = -1;
            rearQueue[i] = -1;
        }
    }

    void enqueue(int data , int qn){
        if (freeSpot == -1) {
            cout << "Queue Overflow!" << endl;
            return;
        }
        int index = freeSpot;
        freeSpot = next[index];

        if(frontQueue[qn] == -1){
            frontQueue[qn] = index;
        }else{
            next[rearQueue[qn]] = index;
        }
        rearQueue[qn]=index;
        next[index]=-1;
        arr[index] = data;
    }

    int dequeue(int qn){
        if(frontQueue[qn]==-1){
            cout << "Queue is empty!!!" << endl;
            return INT_MIN;
        }
        int index = frontQueue[qn];
        int removedData = arr[index];

        frontQueue[qn] = next[index];
        if (frontQueue[qn] == -1) {
            rearQueue[qn] = -1;
        }
        next[index] = freeSpot;
        freeSpot = index;
        return removedData;
    }

    void display(){
        cout << "Arr: ";
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        cout << "Next: ";
        for (int i = 0; i < n; i++) {
            cout << next[i] << " ";
        }
        cout << endl;

        cout << "Front Queue: ";
        for (int i = 0; i < k; i++) {
            cout << frontQueue[i] << " ";
        }
        cout << endl;

        cout << "Rear Queue: ";
        for (int i = 0; i < k; i++) {
            cout << rearQueue[i] << " ";
        }
        cout << endl;

        cout << "Free Spot: " << freeSpot << endl;
        cout << arr[0];
    }

};
int main()
{
    kQueue myQueue(10,3);
    myQueue.enqueue(5,0);
    myQueue.enqueue(3,1);
    myQueue.enqueue(2,0);
    myQueue.enqueue(6,2);
    myQueue.enqueue(8,0);
    myQueue.enqueue(7,1);
    myQueue.enqueue(3,1);
    myQueue.enqueue(9,0);
    myQueue.display();


    return 0;
}
