#include <iostream>
#include <vector>

using namespace std;

vector<int> dynamicArray(int n, vector<vector<int>> queries) {
    // Declare a 2D vector with n empty 1D vectors
    vector<vector<int>> arr(n);
    int lastAnswer = 0;
    vector<int> answers;

    for (const auto& query : queries) {
        int type = query[0];
        int x = query[1];
        int y = query[2];

        // Determine which sub-array to target using XOR and modulo
        int idx = (x ^ lastAnswer) % n;

        if (type == 1) {
            // Query 1: Append y to arr[idx]
            arr[idx].push_back(y);
        } else if (type == 2) {
            // Query 2: Get element at index (y % size) from arr[idx]
            int size = arr[idx].size();
            lastAnswer = arr[idx][y % size];
            answers.push_back(lastAnswer);
        }
    }

    return answers;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    if (!(cin >> n >> q)) return 0;

    vector<vector<int>> queries(q, vector<int>(3));
    for (int i = 0; i < q; i++) {
        cin >> queries[i][0] >> queries[i][1] >> queries[i][2];
    }

    vector<int> result = dynamicArray(n, queries);

    for (int ans : result) {
        cout << ans << "\n";
    }

    return 0;
}