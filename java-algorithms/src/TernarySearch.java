/*
TERNARY SEARCH: repeatedly divide sorted array into equal thirds until the target element is found.
Time complexity:
    best case: O(1) (first element checked matches)
    average case: O(log3(n))
Space complexity: O(1)
 */

import java.util.ArrayList;

public class TernarySearch {

    public static int search(ArrayList<Integer> arr, int key) {
        return searchRecursive(arr, key, 0, arr.size() - 1);
    }

    public static int searchRecursive(ArrayList<Integer> arr, int key, int low, int high)
    {
        if (high >= low) { // base case

            int mid1 = low + (high - low) / 3;
            int mid2 = high - (high - low) / 3;

            if (arr.get(mid1) == key) // check both midpoints
                return mid1;
            if (arr.get(mid2) == key)
                return mid2;

            if (key < arr.get(mid1))
                return searchRecursive(arr, key, low, mid1 - 1);

            if (key > arr.get(mid2))
                return searchRecursive(arr, key, mid2 + 1, high);

            return searchRecursive(arr, key, mid1 + 1, mid2 - 1);
        }

        return -1; // key not found
    }

}

