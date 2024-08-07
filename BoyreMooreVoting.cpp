#include <vector>
#include <iostream>

using namespace std;

vector<int> findMajorityElements(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return {};

    int candidate1 = 0, candidate2 = 0; 
    int count1 = 0, count2 = 0; 
    
    // First pass: Find potential candidates
    for (int num : nums) {
        if (num == candidate1) {
            count1++;
        } else if (num == candidate2) {
            count2++;
        } else if (count1 == 0) {
            candidate1 = num;
            count1 = 1;
        } else if (count2 == 0) {
            candidate2 = num;
            count2 = 1;
        } else {
            count1--;
            count2--;
        }
    }
    
    // Reset counts to validate candidates
    count1 = 0;
    count2 = 0;
 
    // Second pass: Validate the candidates
    for (int num : nums) {
        if (num == candidate1) count1++;
        else if (num == candidate2) count2++;
    }
    
    vector<int> result; 
    if (count1 > n / 3) result.push_back(candidate1);
    if (count2 > n / 3) result.push_back(candidate2);
    
    return result;
}

int main() {
    vector<int> nums = {3, 2, 3};
    vector<int> result = findMajorityElements(nums);
    cout<<"{";
    for (int num : result) {
        cout << num << " ";
    }
      cout<<"}";
    return 0;
}