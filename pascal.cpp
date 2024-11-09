#include <iostream>
#include <vector>

using namespace std;

vector<int> getPascalRow(int i) {
    // Initialize the first row of Pascal's Triangle
    vector<int> row = {1};
    
    // Build each row up to the i-th row
    for (int rowIndex = 1; rowIndex <= i; ++rowIndex) {
        vector<int> newRow(rowIndex + 1, 1);  // Initialize a new row with 1s
        for (int j = 1; j < rowIndex; ++j) {
            newRow[j] = row[j - 1] + row[j];  // Compute each element as sum of elements above it
        }
        row = newRow;  // Update row to the new row
    }
    
    return row;
}

int main() {
    int i;
    cout << "Enter the row index: ";
    cin >> i;

    vector<int> result = getPascalRow(i);
    cout << "The " << i << "-th row of Pascal's Triangle is: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
