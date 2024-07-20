/*
BINARY SEARCH: repeatedly divide sorted array in half until the target element is found
Time complexity:
    best case: O(1) (first element checked matches)
    average case: O(log(n))
Space complexity: O(1)
*/

import java.util.ArrayList;

public class BinarySearch {

    public static int search(ArrayList<Integer> arr, int key) {
        return searchRecursive(arr, key, 0, arr.size() - 1);
    }

    public static int searchRecursive(ArrayList<Integer> arr, int key, int low, int high)
    {
        if (high >= low) { // base case

            int mid = (high + low) / 2;

            if (arr.get(mid) == key) // check midpoint
                return mid;

            if (key > arr.get(mid))
                return searchRecursive(arr, key, mid + 1, high);

            return searchRecursive(arr, key, low, mid - 1);
        }
        return -1; // key not found
    }

}
