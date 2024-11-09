#include <iostream>
#include <vector>

using namespace std;


struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
    // Initialize the m x n matrix with -1
    vector<vector<int>> matrix(m, vector<int>(n, -1));

    // Define the initial boundaries
    int top = 0, bottom = m - 1, left = 0, right = n - 1;
    ListNode* current = head;

    // Fill the matrix in a spiral order
    while (current != nullptr) {
        // Fill the top row from left to right
        for (int j = left; j <= right && current != nullptr; ++j) {
            matrix[top][j] = current->val;
            current = current->next;
        }
        ++top; 

        // Fill the right column from top to bottom
        for (int i = top; i <= bottom && current != nullptr; ++i) {
            matrix[i][right] = current->val;
            current = current->next;
        }
        --right; // Move the right boundary left

        // Fill the bottom row from right to left
        for (int j = right; j >= left && current != nullptr; --j) {
            matrix[bottom][j] = current->val;
            current = current->next;
        }
        ++bottom; 

        // Fill the left column from bottom to top
        for (int i = bottom; i >= top && current != nullptr; --i) {
            matrix[i][left] = current->val;
            current = current->next;
        }
        ++left; // Move the left boundary right
    }

    return matrix;
}

// Helper function to create a linked list from a vector of values
ListNode* createLinkedList(const vector<int>& values) {
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;
    for (int value : values) {
        current->next = new ListNode(value);
        current = current->next;
    }
    return dummy->next;
}

// Helper function to print a 2D matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    int m = 2, n = 6;
    vector<int> values = {1,2,3,4,5,6,7,8,9,10,11,12};
    ListNode* head = createLinkedList(values);
    
    vector<vector<int>> matrix = spiralMatrix(m, n, head);
    
    cout << "Generated Matrix:" << endl;
    printMatrix(matrix);
    
    return 0;
}
