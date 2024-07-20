import java.util.ArrayList;
import java.util.Arrays;
import java.util.ListIterator;

public class Test {
    public static void main(String[] args) {

        ArrayList<Integer> testArr = new ArrayList<>
                (Arrays.asList(1, 2, 3, 4, 5, 6, 7, 8, 9, 30234));
        System.out.println();
        System.out.print("Test array:\t");
        Utils.printArray(testArr);
        System.out.println();

        System.out.println("Linear search with key of 0 (not present):\t\t" + LinearSearch.search(testArr, 0));
        System.out.println("Linear search with key of 1 (1st element):\t\t" + LinearSearch.search(testArr, 1));
        System.out.println("Linear search with key of 30234 (9th element):\t" + LinearSearch.search(testArr, 30234));
        System.out.println();

        System.out.println("Binary search with key of 0 (not present):\t\t" + BinarySearch.search(testArr, 0));
        System.out.println("Binary search with key of 1 (1st element):\t\t" + BinarySearch.search(testArr, 1));
        System.out.println("Binary search with key of 30234 (9th element):\t" + BinarySearch.search(testArr, 30234));
        System.out.println();

        System.out.println("Ternary search with key of 0 (not present):\t\t" + TernarySearch.search(testArr, 0));
        System.out.println("Ternary search with key of 1 (1st element):\t\t" + TernarySearch.search(testArr, 1));
        System.out.println("Ternary search with key of 30234 (9th element):\t" + TernarySearch.search(testArr, 30234));
        System.out.println();

    }

}
