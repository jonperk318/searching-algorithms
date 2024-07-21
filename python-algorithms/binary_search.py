"""
BINARY SEARCH: repeatedly divide sorted array in half until the target element is found
Time complexity:
    best case: O(1) (first element checked matches)
    average case: O(log(n))
Space complexity: O(1)
"""


def binary_search(arr, key):
    return binary_search_recursive(arr, key, 0, len(arr) - 1)


def binary_search_recursive(arr, key, low, high):

    if high >= low: # base case

        mid = (high + low) // 2

        if arr[mid] == key: # check midpoint
            return mid
        
        elif arr[mid] <= key:
            return binary_search_recursive(arr, key, mid+1, high)
        
        return binary_search_recursive(arr, key, low, mid-1)

    return -1 # key not found