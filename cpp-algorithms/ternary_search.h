/*
TERNARY SEARCH: repeatedly divide sorted array into equal thirds until the target element is found.
Time complexity:
    best case: O(1) (first element checked matches)
    average case: O(log3(n))
Space complexity: O(1)
 */

#ifndef TERNARY_SEARCH_H
#define TERNARY_SEARCH_H

using namespace std;
#include <vector>

int ternary_search(vector<int> arr, int const key, int const low, int const high) {

    if (high >= low) { // base case

        int const mid1 = low + (high - low) / 3;
        int const mid2 = high - (high - low) / 3;

        if (arr[mid1] == key) // check both midpoints
            return mid1;
        if (arr[mid2] == key)
            return mid2;

        if (key < arr[mid1])
            return ternary_search(arr, key, low, mid1 - 1);

        if (key > arr[mid2])
            return ternary_search(arr, key, mid2 + 1, high);

        return ternary_search(arr, key, mid1 + 1, mid2 - 1);
    }

    return -1; // key not found
}

#endif //TERNARY_SEARCH_H
