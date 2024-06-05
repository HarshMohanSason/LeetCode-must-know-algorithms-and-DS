/* Binary Search Algorithm: 

Time Complexity O(log n): Each time the array of size n gets halved. Suppose if we have array of size n, then we have to check n/2, n/4, n/8, n/16, n/32, there are n/2^k. To find the number of iterations that search space becomes 1, we solve: n/2^k = 1. We take log2 on both sides we get

        log2(n/2^k) = log2(1)
        log2(n) - log2(2^k) = 0
        log2n = klog(2)
        log2n = k

Thus no of iterations k is log2(n)
   
*/

#include <iostream>

using namespace std; 

int binarySearchIter(int arr[], int low, int high, int x)
{
  int mid = low + (high - low) / 2; 

    while(low <= high)
      {
        if(x == arr[mid])
        {
          return mid; 
        }
        if(arr[mid] <x)
        {
          low = mid + 1; 
        }
        else
        {
          high = mid - 1;
        }
      }
return -1; 
}

int binarySearchRecurs(int arr[], int low, int high, int x)
{
  if(high>= low)
  {
    int mid = low + (high - low) / 2;

    if(arr[mid] == x)
    {
      return mid; 
    }
    if(arr[mid]>x)
    {
      return binarySearchRecurs(arr, low, mid+1, x);
    }
    return binarySearchRecurs(arr, low, mid-1, x);
  }
return -1;
}

int main() {

  int arr[] = {1, 2, 3, 4, 5};
  int x = 3;
  int n = sizeof(arr) / sizeof(arr[0]);
  int low = 0; 
  int high = n - 1; 
  int resultIter = binarySearchIter(arr, low, high, x);
  int resultRecurs = binarySearchRecurs(arr, low, high, x);
  (resultIter == -1)
    ? cout << "Element is not present in array\n"
    : cout << "Element is present at index: " << resultIter<<'\n';
  (resultRecurs == -1)
    ? cout << "Element is not present in array"
    : cout << "Element is present at index: " << resultRecurs;
  
  return 0;
}
