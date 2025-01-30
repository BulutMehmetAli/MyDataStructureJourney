#include <iostream>
#include <vector>

using namespace std;

bool known(int i, int j, vector<vector<int>>& matrix) {
    return matrix[i][j];
}

int findCelebrity(int n, vector<vector<int>>& matrix) {
    vector<int> indegree(n, 0);
    vector<int> outdegree(n, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {  // Hata düzeltilmiþ: i++ yerine j++
            int result = known(i, j, matrix);
            outdegree[i] += result;
            indegree[j] += result;
        }
    }

    for (int i = 0; i < n; i++) {
        if (indegree[i] == n - 1 && outdegree[i] == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n = 4;
    vector<vector<int>> matrix = {
        {0, 0, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 0},
        {0, 0, 1, 0}
    };

    int celebrityId = findCelebrity(n, matrix);
    if (celebrityId == -1) {
        cout << "No celebrity";
    } else {
        cout << "Celebrity ID " << celebrityId;  // Hata düzeltildi: `id` yerine `celebrityId`
    }
    return 0;
}
