#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

string kthDistinctString(vector<string>& arr, int k) {
    // Count occurrences of each string in the array
    unordered_map<string, int> count;
    for (const string& s : arr) {
        count[s]++;
    }
    
    // Traverse the array to find the k-th distinct string
    int distinctCount = 0;
    for (const string& s : arr) {
        if (count[s] == 1) { // Only consider strings that appear once
            distinctCount++;
            if (distinctCount == k) { // If we reach the k-th distinct string
                return s;
            }
        }
    }
    
    // If there are fewer than k distinct strings
    return "";
}

int main() {
    vector<string> arr = {"a", "b", "e", "c", "f", "d"};
    int k = 2;
    cout << kthDistinctString(arr, k) << endl; // Output: "d"
    return 0;
}
