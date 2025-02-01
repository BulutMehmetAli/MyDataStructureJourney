#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool knows(int a, int b, const vector<vector<int>>& matrix) {
    return matrix[a][b];
}

int findCelebrity(int n, const vector<vector<int>>& matrix) {
    stack<int> s;

    for (int i = 0; i < n; i++) {
        s.push(i);
    }

    while (s.size() > 1) {
        int A = s.top(); s.pop();
        int B = s.top(); s.pop();

        if (knows(A, B, matrix)) {
            s.push(B);
        }
        else {
            s.push(A);
        }
    }

    int candidate = s.top();
    s.pop();

    for (int i = 0; i < n; i++) {
        if (i != candidate) {
            if (knows(candidate, i, matrix) || !knows(i, candidate, matrix)) {
                return -1;
            }
        }
    }

    return candidate;
}

int main() {
    vector<vector<int>> matrix = {
        { 0, 0, 1, 0 },
        { 0, 0, 1, 0 },
        { 0, 0, 1, 0 },
        { 0, 0, 1, 0 }
    };

    int celebrityID = findCelebrity(matrix.size(), matrix);

    if (celebrityID == -1) {
        cout << "No celebrity found." << endl;
    } else {
        cout << "Celebrity ID: " << celebrityID << endl;
    }

    return 0;
}
