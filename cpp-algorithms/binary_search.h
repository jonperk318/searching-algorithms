/*
BINARY SEARCH: repeatedly divide sorted array in half until the target element is found
Time complexity:
    best case: O(1) (first element checked matches)
    average case: O(log(n))
Space complexity: O(1)
*/

#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

using namespace std;
#include <vector>

int binary_search(vector<int> arr, int const key, int const low, int const high) {

    if (high >= low) { // base case

        int const mid = (high + low) / 2;

        if (arr[mid] == key) // check midpoint
            return mid;

        if (key > arr[mid])
            return binary_search(arr, key, mid + 1, high);

        return binary_search(arr, key, low, mid - 1);
    }
    return -1; // key not found
}

#endif //BINARY_SEARCH_H
