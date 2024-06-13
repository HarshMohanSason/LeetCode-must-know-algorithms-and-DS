#include <iostream>

using namespace std;


//Bubble Sort algorithm. Swapping two elements at a time until the last element is largest in each pass
//For the given array {5,3,8,4,2}
// Pass 1: {3,5,4,2,8}
// Pass 2: {3,4,2,5,8}
// Pass 3: {3,2,4,5,8}
// Pass 4: {2,3,4,5,8}
// Time Complexity: O(n^2) because of two nested loops
// Space Complexity: O(n)

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
    
        for (int j = 0; j < n - i - 1; j++) {
            
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

//Selection Sort algorithm. Find the minimum element and place it at position 0, Find second minimum element and place it at position two and so on until array is sorted
//For the given array {5,3,8,4,2}
// Pass 1: {2,3,8,4,5}
// Pass 2: {2,3,8,4,5}
// Pass 3: {2,3,4,8,5}
// Pass 4: {2,3,4,5,8}
// Time Complexity: O(n^2)
// Space Complexity: O(n)


void selectionSort(int arr[], int n)
{
    for(int i = 0; i< n - 1; i++)
    {
        int minIndex = i; 
        
        for(int j = i+1; j< n; j++)
        {
            if(arr[j] < arr[minIndex])
            {
                minIndex = j; 
            }
        }
        swap(arr[minIndex], arr[i]);
    }
}

void insertionSort(int arr[], int n) {
    
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {5, 3, 8, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, n);
    cout << "Sorted array: \n";
    printArray(arr, n);

    return 0;
}

