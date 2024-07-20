"""
Testing all searching functions to verify their ability to work correcly
"""

from linear_search import linear_search
from binary_search import binary_search
from ternary_search import ternary_search


test_arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 30234]

print("\nTest array:\t" + str(test_arr))

print("\nLinear search key of 0 (not present):\t\t" + str(linear_search(test_arr, 0)))
print("Linear search key of 1 (1st element):\t\t" + str(linear_search(test_arr, 1)))
print("Linear search key of 30234 (9th element):\t" + str(linear_search(test_arr, 30234)))

print("\nBinary search key of 0 (not present):\t\t" + str(binary_search(test_arr, 0)))
print("Binary search key of 1 (1st element):\t\t" + str(binary_search(test_arr, 1)))
print("Binary search key of 30234 (9th element):\t" + str(binary_search(test_arr, 30234)))

print("\nTernary search key of 0 (not present):\t\t" + str(ternary_search(test_arr, 0)))
print("Ternary search key of 1 (1st element):\t\t" + str(ternary_search(test_arr, 1)))
print("Ternary search key of 30234 (9th element):\t" + str(ternary_search(test_arr, 30234)) + "\n")