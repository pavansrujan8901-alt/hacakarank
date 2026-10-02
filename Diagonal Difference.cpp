#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int diagonalDifference(vector<vector<int>> arr) {
    int n = arr.size();
    long long primary_sum = 0;
    long long secondary_sum = 0;

    for (int i = 0; i < n; i++) {
        primary_sum += arr[i][i];
        secondary_sum += arr[i][n - 1 - i];
    }

    return abs(primary_sum - secondary_sum);
}

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<vector<int>> arr(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    int result = diagonalDifference(arr);
    cout << result << endl;

    return 0;
}