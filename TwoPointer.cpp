
#include <iostream>
#include <string>
#include <vector>

using namespace std; 

vector<int> twoSum(vector<int>& nums, int target)
{
    int left = 0; 
    int right = nums.size() -1; 
    
    while(left < right)
    {
        int sums = nums[left] + nums[right];
        
        if(sums == target)
        {
            return {left, right};
        }
        else if(sums < target)
        {
            left ++; 
        }
        else
        {
            right --; 
        }
        
    }
    return {};
}

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = twoSum(nums, target);
    if (!result.empty()) {
        cout << "Indices: " << result[0] << ", " << result[1] << endl;
    } else {
        cout << "No such pair found!" << endl;
    }
   return 0;
}
