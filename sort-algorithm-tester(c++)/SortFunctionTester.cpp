#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;


// SORTING FUNCTIONS

// Merge Sort

void merge(vector<int> arr, int first, int mid, int last) 
    // helper function that merges left and right halves of arr[]
{
    int const leftLength = mid - first + 1; 
    int const rightLength = last - mid; 

    // Create temp arrays
    vector<int> leftArray(leftLength), rightArray(rightLength);

    // Copy data to temp arrays
    for (int i = 0; i < leftLength; i++) 
        leftArray[i] = arr[first + i]; // first subarray is arr[first...mid]
    for (int j = 0; j < rightLength; j++)
        rightArray[j] = arr[mid + 1 + j]; // second subarray is arr[mid+1...last]

    int indexOfLeftLength = 0, indexOfRightLength = 0;
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

    // Copy the remaining elements of left, if there are any
    while (indexOfLeftLength < leftLength) {
        arr[indexOfMergedArray]
            = leftArray[indexOfLeftLength];
        indexOfLeftLength++;
        indexOfMergedArray++;
    }

    // Copy the remaining elements of right, if there are any
    while (indexOfRightLength < rightLength) {
        arr[indexOfMergedArray]
            = rightArray[indexOfRightLength];
        indexOfRightLength++;
        indexOfMergedArray++;
    }
}

void mergeSort(vector<int> arr, int const first, int const last)
    // divide and conquer algorithm with O(nlog(n)) time complexity
{
    if (first >= last) { // base case is an empty array
        return;
        }

    int mid = first + (last - first) / 2;
    mergeSort(arr, first, mid); // first half of array
    mergeSort(arr, mid + 1, last); // second half of array
    merge(arr, first, mid, last);
}

// Quick Sort

int partition(vector<int> arr, int first, int last)
  // helper function to choose the pivot
{
  int pivot = arr[last]; // last element is initially selected as the pivot
  int i = (first - 1);
  
  for(int j = first; j <= last - 1; j++)
  {
    if(arr[j] < pivot) // check if each element is smaller than the pivot
    {
      i++; //if so, increment index of smaller element
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[i + 1], arr[last]);
  return i + 1; // return index of pivot
}
           
void quickSort(vector<int> arr, int first, int last)
    // divide and conquer algorithm with O(nlog(n)) time complexity
{
    if (first >= last) { // base case is an empty array
        return;
        }

    int pivot = partition(arr, first, last); // find index of pivot
    quickSort(arr, first, pivot - 1); // recursive calls to sort both subarrays
    quickSort(arr, pivot + 1, last);
}


// UTILITY FUNCTIONS

void printArray(vector<int> arr) // prints all elements of an array
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}


// DRIVER

int main()
{
    vector<int> testArr = {19, 201, 202, 9, 3, 14, 63, 1001};
    vector<int> testArr2 = testArr;
    int testArrSize = testArr.size();

    cout << endl << "Given array is \n";
    printArray(testArr);

    mergeSort(testArr, 0, testArrSize - 1);
    quickSort(testArr2, 0, testArrSize - 1);

    cout << "\nArray sorted by Merge Sort: \n";
    printArray(testArr);
    cout << "\nArray sorted by Quick Sort: \n";
    printArray(testArr2);
    cout << endl;


    // Reading input texts
    cout << "here";
    vector<int> sampleSizes = {1000, 2500, 5000, 10000, 25000, 50000, 100000, 250000, 500000, 1000000};
    vector<vector<int>> inputs1(sampleSizes.size());

    for (int sampleSize : sampleSizes) {

        string str = to_string(sampleSize);
        str.append(".txt");
        ifstream inputFile(str.c_str());
        inputFile.open;

        if (!inputFile.is_open()) { // there should be no error opening the file
            cerr << "Error opening the file!" << endl; 
            return 1; 
        }

        vector<string> result; // initialize array to read the strings of numbers into

        while (inputFile.good()) {
            string substr;
            getline(inputFile, substr, ','); // split each string by the "," delineator
            result.push_back(substr);
        }

        inputFile.close();

        vector<int> values; // initialize array to store integers

        for(int i = 0; i < result.size() ; i++) {
            values[i] = stoi(result[i]); // convert string to integer
        }

        inputs1.push_back(values); // add unsorted array to array of inputs
    }

    vector<vector<int>> inputs2 = inputs1;
    

    // Testing sorting functions

    vector<double> mergeSortTimes;
    vector<double> quickSortTimes;

    for (vector<int> input : inputs1) { // testing mergeSort times
        auto tick = high_resolution_clock::now();
        mergeSort(input, 0, input.size());
        auto tock = high_resolution_clock::now();
        auto duration = duration_cast<seconds>(tock - tick);
        mergeSortTimes.push_back(duration.count());
    }

    for (vector<int> input : inputs2) { // testing quickSort times
        auto tick = high_resolution_clock::now();
        mergeSort(input, 0, input.size());
        auto tock = high_resolution_clock::now();
        auto duration = duration_cast<seconds>(tock - tick);
        quickSortTimes.push_back(duration.count());
    }

    for (double i : mergeSortTimes) {
        cout << i << " ";
    }
    cout << endl;
    for (double i : quickSortTimes) {
        cout << i << " ";
    }
    cout << endl;

    printArray(inputs1[0]);
    printArray(inputs2[0]);


    return 0;
}
