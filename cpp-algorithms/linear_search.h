/*
LINEAR SEARCH: begins at one end of array and checks each element until the target element is found
Time Complexity:
    best case: O(1) (first element checked matches)
    average case: O(N)
Space complexity: O(N)
*/

#ifndef LINEAR_SEARCH_H
#define LINEAR_SEARCH_H

using namespace std;
#include <vector>

int linear_search(vector<int> arr, int const key) {

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == key)
            return i;
    }
    return -1; // key not found
}

#endif //LINEAR_SEARCH_H
