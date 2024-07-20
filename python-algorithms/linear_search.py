"""
LINEAR SEARCH: begins at one end of array and checks each element until the target element is found
Time Complexity:
    best case: O(1) (first element checked matches)
    average case: O(N)
Space complexity: O(N)
"""


def linear_search(arr, key):

    for i in range(len(arr)):
        if arr[i] == key:
            return i
        
    return -1 # key not found