#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

vector<int> matchingStrings(vector<string> stringList, vector<string> queries) {
    unordered_map<string, int> counts;
    
    // Count occurrences of each string in stringList
    for (const string& str : stringList) {
        counts[str]++;
    }
    
    // Build the output result array
    vector<int> result;
    result.reserve(queries.size());
    for (const string& q : queries) {
        result.push_back(counts[q]);
    }
    
    return result;
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    
    vector<string> stringList(n);
    for (int i = 0; i < n; i++) {
        cin >> stringList[i];
    }
    
    int q;
    cin >> q;
    vector<string> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i];
    }
    
    vector<int> res = matchingStrings(stringList, queries);
    for (int count : res) {
        cout << count << "\n";
    }
    
    return 0;
}