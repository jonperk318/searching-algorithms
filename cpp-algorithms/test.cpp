using namespace std;
#include <iostream>
#include <vector>
#include "utils.h"
#include "linear_search.h"
#include "binary_search.h"
#include "ternary_search.h"

void test() {

    vector const test_arr {1, 2, 3, 4, 5, 6, 7, 8, 9, 30234};
    cout << endl << "Test array:\t";
    print_array(test_arr);

    cout << endl;
    cout << "Linear search with key of 0 (not present):\t\t" << linear_search(test_arr, 0) << endl;
    cout << "Linear search with key of 1 (1st element):\t\t" << linear_search(test_arr, 1) << endl;
    cout << "Linear search with key of 30234 (9th element):\t" << linear_search(test_arr, 30234) << endl;
    cout << endl;
    cout << "Binary search with key of 0 (not present):\t\t" << binary_search(test_arr, 0, 0, test_arr.size() - 1) << endl;
    cout << "Binary search with key of 1 (1st element):\t\t" << binary_search(test_arr, 1, 0, test_arr.size() - 1) << endl;
    cout << "Binary search with key of 30234 (9th element):\t" << binary_search(test_arr, 30234, 0, test_arr.size() - 1) << endl;
    cout << endl;
    cout << "Ternary search with key of 0 (not present):\t\t" << ternary_search(test_arr, 0, 0, test_arr.size() - 1) << endl;
    cout << "Ternary search with key of 1 (1st element):\t\t" << ternary_search(test_arr, 1, 0, test_arr.size() - 1) << endl;
    cout << "Ternary search with key of 30234 (9th element):\t" << ternary_search(test_arr, 30234, 0, test_arr.size() - 1) << endl;

}