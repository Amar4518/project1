#include <iostream>
#include <vector>

using namespace std;

bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
    // Check if rec1 is to the left of rec2
    if (rec1[2] <= rec2[0]) {
        return false; // rec1's right edge is to the left of rec2's left edge
    }
    
    // Check if rec1 is to the right of rec2
    if (rec1[0] >= rec2[2]) {
        return false; // rec1's left edge is to the right of rec2's right edge
    }
    
    // Check if rec1 is below rec2
    if (rec1[3] <= rec2[1]) {
        return false; // rec1's top edge is below rec2's bottom edge
    }
    
    // Check if rec1 is above rec2
    if (rec1[1] >= rec2[3]) {
        return false; // rec1's bottom edge is above rec2's top edge
    }
    
    // If none of the above conditions are true, the rectangles overlap
    return true;
}

int main() {
    vector<int> rec1 = {0, 0, 1, 1}; // Rectangle 1: [x1, y1, x2, y2]
    vector<int> rec2 = {2, 2, 3, 3}; // Rectangle 2: [x1, y1, x2, y2]
    
    if (isRectangleOverlap(rec1, rec2)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    
    return 0;
}
