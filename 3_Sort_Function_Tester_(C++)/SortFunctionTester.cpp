#include <iostream>
using namespace std;


// SORTING FUNCTIONS

// Merge Sort

void merge(int arr[], int const left, int const mid,
           int const right) 
    // helper function that merges left and right halves of arr[]
{
    int const subArrayOne = mid - left + 1; 
    int const subArrayTwo = right - mid; 

    // Create temp arrays
    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++) 
        leftArray[i] = arr[left + i]; // first subarray is arr[begin...mid]
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = arr[mid + 1 + j]; // second subarray is arr[mid+1..end]

    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne
           && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne]
            <= rightArray[indexOfSubArrayTwo]) {
            arr[indexOfMergedArray]
                = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            arr[indexOfMergedArray]
                = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        arr[indexOfMergedArray]
            = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        arr[indexOfMergedArray]
            = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

void mergeSort(int arr[], int const begin, int const end)
{
    if (begin >= end) // begin and end are left and right indices of sub-array of arr
        return;

    int mid = begin + (end - begin) / 2;
    mergeSort(arr, begin, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, begin, mid, end);
}

// Quick Sort

int partition(int arr[], int low, int high)
  // helper function to choose the pivot
{
  int pivot = arr[high];
  //Index of smaller element and Indicate
  //the right position of pivot found so far
  int i = (low - 1);
  
  for(int j = low; j <= high - 1; j++)
  {
    //If current element is smaller than the pivot
    if(arr[j] < pivot)
    {
      //Increment index of smaller element
      i++;
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i + 1], arr[high]);
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
