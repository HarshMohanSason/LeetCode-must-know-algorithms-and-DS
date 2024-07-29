'''

Dutch National Flag Algorithm

Use three pointers to partition the array

1. low: The boundary for 0s
2. mid: The current element being examinedå
3. high: The boundary for 2s

Steps: 

-- Start with low = 0, mid = 0, and high = n - 1. Iterate through the array with mid pointer. Based on the value at arr[mid], do the following: 
	-> 0. Swap [arr] and arr[mid], then incrememnt both low and mid
	-> 1. Just move the mid pointer
	-> 2. Swap arr[mid] and arr[high], then decrement high
	
Continue until mid exceeds high
'''

class Solution:
    def sort012(self, arr, n):
        low = 0
        mid = 0
        high = n - 1

        while mid <= high:
            if arr[mid] == 0:
                arr[low], arr[mid] = arr[mid], arr[low]
                low += 1
                mid += 1
            elif arr[mid] == 1:
                mid += 1
            else:
                arr[mid], arr[high] = arr[high], arr[mid]
                high -= 1

        return arr

# Example usage
sol = Solution()
arr = [0, 2, 1, 2, 0, 1, 1, 0]
n = len(arr)
print(sol.sort012(arr, n))  # Output should be [0, 0, 0, 1, 1, 1, 2, 2]