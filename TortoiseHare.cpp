/* 

Useful for detecting cycles in a linked list, finding middle of linked of list without finding size 

Rabbit hare algorithm

Take two pointers. Fast and slow
Fast = head
slow = head

while(fast && fast->next)
{
		slow = slow->next;
		fast = fast->next->next
}
*/

#include <iostream>
#include <vector>

// Function to detect cycle in a linked list using the Rabbit-Hare algorithm
bool hasCycle(std::vector<int>& nums) {
    int slow = nums[0];
    int fast = nums[nums[0]];

    // Loop until fast and slow pointers meet or fast pointer reaches the end
    while (fast != slow) {
        if (nums[fast] == -1 || nums[nums[fast]] == -1) {
            return false; // No cycle
        }
        slow = nums[slow];
        fast = nums[nums[fast]];
    }
    return true; // Cycle detected
}

int main() {
    // Example list representing a sequence with a cycle
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 3};  // Example with a cycle

    if (hasCycle(nums)) {
        std::cout << "Cycle detected!" << std::endl;
    } else {
        std::cout << "No cycle detected." << std::endl;
    }

    return 0;
}
