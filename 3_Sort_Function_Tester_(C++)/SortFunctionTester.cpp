#include <iostream>
#include <fstream>
#include <string>

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
    // divide and conquer algorithm with O(nlog(n)) time complexity
{
    if (first >= last) { // the array cannot be empty or have negative length
        cout << "Error: length of array has to be greater than 0";
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
  int pivot = arr[last]; // last element is initially selected as the pivot
  int i = (first - 1);
  
  for(int j = first; j <= last - 1; j++)
  {
    // check if each element is smaller than the pivot
    if(arr[j] < pivot)
    {
      i++; //if so, increment index of smaller element
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i + 1], arr[last]);
  return i + 1; // return index of pivot
}
           
void quickSort(int arr[], int first, int last)
    // divide and conquer algorithm with O(nlog(n)) time complexity
{
    if (first >= last) { // the array cannot be empty or have negative length
        cout << "Error: length of array has to be greater than 0" << endl;
        return;
        }

    int pivot = partition(arr, first, last); // find index of pivot
    quickSort(arr, first, pivot - 1); // recursive calls to sort both subarrays
    quickSort(arr, pivot + 1, last);
}


// UTILITY FUNCTIONS

void printArray(int arr[], int size) // prints all elements of an array
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


    // Reading input texts

    int sampleSizes[10] = {1000, 2500, 5000, 10000, 25000, 50000, 100000, 250000, 500000, 1000000};

    for (int size : sampleSizes) {

        auto str = to_string(size);
        ifstream inputFile("" + str + ".txt");

        if (!inputFile.is_open()) { // there should be no error opening the file
        cerr << "Error opening the file!" << endl; 
        return 1; 
        }

        string line;


    }

    return 0;
}
