#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;
string addBinary(string a, string b) {
    string result = "";
    int carry = 0, i = a.size() - 1, j = b.size() - 1;
    
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        result = char(sum % 2 + '0') + result;
        carry = sum / 2;
    }   
    return result;
}
string kthDistinct(vector<string>& arr, int k) {
    unordered_map<string, int> freq;
    for (const string& str : arr) {
        freq[str]++;
    }
    int count = 0;
    for (const string& str : arr) {
        if (freq[str] == 1) {
            count++;
            if (count == k) return str;
        }
    }
    return "";
}
int main() {
    string bin1, bin2;
    cout << "Enter first binary number: ";
    cin >> bin1;
    cout << "Enter second binary number: ";
    cin >> bin2;
    cout << "Sum of binary numbers: " << addBinary(bin1, bin2) << endl;
    int n, k;
    cout << "\nEnter the number of strings in the array: ";
    cin >> n;
    vector<string> arr(n);
    cout << "Enter the strings:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout << "Enter the value of k: ";
    cin >> k;
    string result = kthDistinct(arr, k);
    if (result.empty()) {
        cout << "There are fewer than " << k << " distinct strings in the array." << endl;
    } else {
        cout << "The " << k << "th distinct string is: " << result << endl;
    }
    return 0;
}