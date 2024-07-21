/*
BINARY SEARCH: repeatedly divide sorted array in half until the target element is found
Time complexity:
    best case: O(1) (first element checked matches)
    average case: O(log(n))
Space complexity: O(1)
*/

function binarySearch(arr, key) {
    return binarySearchRecursive(arr, key, 0, arr.length - 1);
}

function binarySearchRecursive(arr, key, low, high)
{
    if (high >= low) { // base case

        let mid = Math.floor((high + low) / 2);

        if (arr[mid] === key) // check midpoint
            return mid;

        if (key > arr[mid])
            return binarySearchRecursive(arr, key, mid + 1, high);

        return binarySearchRecursive(arr, key, low, mid - 1);
    }

    return -1; // key not found
}

module.exports = binarySearch;