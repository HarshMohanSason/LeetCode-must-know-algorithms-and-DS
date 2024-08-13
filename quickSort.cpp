#include <iostream>
#include <vector>
using namespace std;

// Function to partition the array
int partition(vector<int>& nums, int left, int right) {
    int pivotValue = nums[right]; // Choose the last element as the pivot
    int storeIndex = left; // Place to store the pivot's final position

    for (int i = left; i < right; i++) {
        if (nums[i] < pivotValue) { // If the current element is smaller than the pivot
            swap(nums[i], nums[storeIndex]); // Swap with the element at storeIndex
            storeIndex++;
        }
    }
    swap(nums[storeIndex], nums[right]); // Place the pivot in its correct position
    return storeIndex;
}

// Quicksort function
void quicksort(vector<int>& nums, int left, int right) {
    if (left < right) {
        int pivotIndex = partition(nums, left, right); // Partition the array
        quicksort(nums, left, pivotIndex - 1); // Recursively sort the left part
        quicksort(nums, pivotIndex + 1, right); // Recursively sort the right part
    }
}

// Utility function to print the array
void printArray(const vector<int>& nums) {
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

// Main function to test the quicksort
int main() {
    vector<int> nums = {3, 6, 8, 10, 1, 2, 1};
    cout << "Original array: ";
    printArray(nums);

    quicksort(nums, 0, nums.size() - 1);

    cout << "Sorted array: ";
    printArray(nums);

    return 0;
}
