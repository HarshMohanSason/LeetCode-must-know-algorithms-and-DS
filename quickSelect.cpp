#include <iostream>
#include <vector>
#include <cstdlib> 
#include <algorithm> 

using namespace std;

int partition(vector<int>& nums, int left, int right, int pivotIndex) {
    int pivotValue = nums[pivotIndex];
    swap(nums[pivotIndex], nums[right]);
    int storeIndex = left;
    for (int i = left; i < right; i++) {
        if (nums[i] > pivotValue) { // For largest element, use '>' instead of '<'
            swap(nums[i], nums[storeIndex]);
            storeIndex++;
        }
    }
    swap(nums[storeIndex], nums[right]);
    return storeIndex;
}

int quickselect(vector<int>& nums, int left, int right, int k) {
    if (left == right) return nums[left];

    int pivotIndex = left + rand() % (right - left + 1);
    pivotIndex = partition(nums, left, right, pivotIndex);

    if (k == pivotIndex) return nums[k];
    else if (k < pivotIndex) return quickselect(nums, left, pivotIndex - 1, k);
    else return quickselect(nums, pivotIndex + 1, right, k);
}

int findKthLargest(vector<int>& nums, int k) {
    int n = nums.size();
    return quickselect(nums, 0, n - 1, k - 1); // k - 1 for zero-indexed position
}

int main() {
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 6;
    cout << "The " << k << "th largest element is " << findKthLargest(nums, k) << endl;
    return 0;
}