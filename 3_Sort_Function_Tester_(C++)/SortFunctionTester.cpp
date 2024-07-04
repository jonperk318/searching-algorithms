#include <iostream>
using namespace std;


// SORTING FUNCTIONS

// Merge Sort

void merge(int arr[], int first, int mid, int last) 
    // helper function that merges left and right halves of arr[]
{
    int const leftLength = mid - first + 1; 
    int const rightLength = last - mid; 

    // Create temp arrays
    auto *leftArray = new int[leftLength], *rightArray = new int[rightLength];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < leftLength; i++) 
        leftArray[i] = arr[first + i]; // first subarray is arr[first...mid]
    for (auto j = 0; j < rightLength; j++)
        rightArray[j] = arr[mid + 1 + j]; // second subarray is arr[mid+1..last]

    auto indexOfLeftLength = 0, indexOfRightLength = 0;
    int indexOfMergedArray = first;

    // Merge temp arrays back into single array
    while (indexOfLeftLength < leftLength
           && indexOfRightLength < rightLength) {
        if (leftArray[indexOfLeftLength]
            <= rightArray[indexOfRightLength]) {
            arr[indexOfMergedArray]
                = leftArray[indexOfLeftLength];
            indexOfLeftLength++;
        }
        else {
            arr[indexOfMergedArray]
                = rightArray[indexOfRightLength];
            indexOfRightLength++;
        }
        indexOfMergedArray++;
    }

    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfLeftLength < leftLength) {
        arr[indexOfMergedArray]
            = leftArray[indexOfLeftLength];
        indexOfLeftLength++;
        indexOfMergedArray++;
    }

    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfRightLength < rightLength) {
        arr[indexOfMergedArray]
            = rightArray[indexOfRightLength];
        indexOfRightLength++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

void mergeSort(int arr[], int const first, int const last)
{
    if (first >= last) { // the first index cannot be larger than the last index
        cout << "Error: length of array cannot be less than 0";
        return;
        }

    int mid = first + (last - first) / 2;
    mergeSort(arr, first, mid);
    mergeSort(arr, mid + 1, last);
    merge(arr, first, mid, last);
}

// Quick Sort

int partition(int arr[], int first, int last)
  // helper function to choose the pivot
{
  int pivot = arr[last];
  //Index of smaller element and Indicate
  //the right position of pivot found so far
  int i = (first - 1);
  
  for(int j = first; j <= last - 1; j++)
  {
    //If current element is smaller than the pivot
    if(arr[j] < pivot)
    {
      //Increment index of smaller element
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i + 1], arr[last]);
  return i + 1;
}
           
void quickSort(int arr[], int low, int high)
{
  if(low < high)
  {    
    int pivot = partition(arr, low, high); // index of pivot
    
    // Recursive quicksort call
    // element smaller than pivot goes left, larger element goes right
    quickSort(arr, low, pivot - 1);
    quickSort(arr, pivot + 1, high);
  }
}


// UTILITY FUNCTIONS

void printArray(int arr[], int size) // Prints all elements of an array
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}


// DRIVER

int main()
{
    int testArr[] = { 19, 201, 202, 9, 3, 14, 63, 1001 };
    int testArr2[] = { 19, 201, 202, 9, 3, 14, 63, 1001 };
    int test_arr_size = sizeof(testArr) / sizeof(testArr[0]);

    cout << "Given array is \n";
    printArray(testArr, test_arr_size);

    mergeSort(testArr, 0, test_arr_size - 1);
    quickSort(testArr2, 0, test_arr_size - 1);

    cout << "\nArray sorted by Merge Sort: \n";
    printArray(testArr, test_arr_size);
    cout << "\nArray sorted by Quick Sort: \n";
    printArray(testArr2, test_arr_size);

    return 0;
}
