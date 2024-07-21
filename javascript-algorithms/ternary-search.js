/*
TERNARY SEARCH: repeatedly divide sorted array into equal thirds until the target element is found.
Time complexity:
    best case: O(1) (first element checked matches)
    average case: O(log3(n))
Space complexity: O(1)
 */


function ternarySearch(arr, key) {
    return ternarySearchRecursive(arr, key, 0, arr.length - 1);
}

function ternarySearchRecursive(arr, key, low, high)
{
    if (high >= low) { // base case

        let mid1 = Math.floor(low + (high - low) / 3);
        let mid2 = Math.floor(high - (high - low) / 3);

        if (arr[mid1] === key) // check both midpoints
            return mid1;
        if (arr[mid2] === key)
            return mid2;

        if (key < arr[mid1])
            return ternarySearchRecursive(arr, key, low, mid1 - 1);

        if (key > arr[mid2])
            return ternarySearchRecursive(arr, key, mid2 + 1, high);

        return ternarySearchRecursive(arr, key, mid1 + 1, mid2 - 1);
    }

    return -1; // key not found
}

module.exports = ternarySearch;