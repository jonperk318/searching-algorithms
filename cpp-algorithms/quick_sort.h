/*
QUICK SORT: divide and conquer algorithm that recursively sorts elements into
two arrays by selecting a pivot (here, the last index of the subarray) and partitioning
the array around that pivot, sorting elements smaller than the pivot to one subarray and
larger elements to the other subarray until reaching the base case of an empty array
Time complexity:
    best case: O(n*log(n))
    average case: O(n*log(n))
    worst case: O(n^2) (chosen partition is always an extrema of the subarray)
Space complexity: O(1)
Most often not stable
Better for arrays than linked lists
*/

#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include <vector>
using namespace std;

int partition(vector<int>& arr, int const first, int const last)
  // helper function to choose the pivot
{
    int const pivot = arr[last]; // last element is selected as the pivot
    int i = (first - 1);

    for(int j = first; j <= last - 1; j++)
    {
        if(arr[j] < pivot) // check if each element is smaller than the pivot
        {
            i++; //if so, increment index of smaller element
            swap(arr[i], arr[j]); // swap elements
        }
    }
    swap(arr[i + 1], arr[last]); // swap pivot
    return i + 1; // return index of pivot
}

void quick_sort(vector<int>& arr, int const first, int const last) // main function
{
    if (first >= last) { // base case: empty array
        return;
    }

    int const pivot = partition(arr, first, last); // find index of pivot and sort on either side
    quick_sort(arr, first, pivot - 1); // recursive calls for each side of the pivot
    quick_sort(arr, pivot + 1, last);
}

#endif //QUICK_SORT_H