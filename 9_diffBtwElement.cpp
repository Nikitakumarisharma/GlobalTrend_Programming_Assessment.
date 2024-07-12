#include <iostream>
#include <vector>
#include <limits> // For numeric_limits

using namespace std;

int maxDifference(vector<int>& nums) {
    if (nums.size() < 2) {
        return 0; // If array has less than 2 elements, no difference can be found
    }

    int minElem = nums[0];
    int maxDiff = numeric_limits<int>::min(); // Initialize with smallest possible integer

    for (int i = 1; i < nums.size(); ++i) {
        maxDiff = max(maxDiff, nums[i] - minElem); // Update maxDiff if larger difference found
        minElem = min(minElem, nums[i]); // Update minElem to current minimum
    }

    return maxDiff;
}

int main() {
    vector<int> arr = {7, 1, 5, 3, 6, 4};

    int result = maxDifference(arr);
    cout << "Maximum difference between any two elements in the array: " << result << endl;

    return 0;
}
