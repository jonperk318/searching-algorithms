"""
TERNARY SEARCH: repeatedly divide sorted array into equal thirds until the target element is found.
Time complexity:
    best case: O(1) (first element checked matches)
    average case: O(log3(n))
Space complexity: O(1)
"""


def ternary_search(arr, key):
    return(ternary_search_recursive(arr, key, 0, len(arr) - 1))

def ternary_search_recursive(arr, key, low, high):

    if high >= low: # base case

        mid1 = low + (high - low) // 3
        mid2 = high - (high - low) // 3

        if arr[mid1] == key: # check both midpoints
            return mid1
        if arr[mid2] == key: 
            return mid2
        
        if key < arr[mid1]:
            return ternary_search_recursive(arr, key, low, mid1 - 1)
        
        elif key > arr[mid2]: 
            return ternary_search_recursive(arr, key, mid2 + 1, high)
        
        else: 
            return ternary_search_recursive(arr, key, mid1 + 1, mid2 - 1)
        
    return -1 # key not found