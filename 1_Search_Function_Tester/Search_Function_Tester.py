# Imports
import time
import matplotlib.pyplot as plt
import numpy as np
import random

# These search funcitons return the index of x within the array arr. If x is not in arr, they return -1

# Linear Search
def linear_search(arr:list, x:int):

    for i in range(len(arr)):
        if arr[i] == x:
            return i
        
    return -1

# Binary Search
def binary_search(arr:list, x:int, low:int, high:int):

    if high > low: # Base case is that high != low

        mid = (high + low) // 2

        if arr[mid] == x:
            return mid
        
        elif arr[mid] <= x:
            return binary_search(arr, x, mid+1, high)
        
        else:
            return binary_search(arr, x, low, mid-1)

    return -1

def compare_searches(input:list, trials:int):

    # This funciton finds the time it takes to find x using each search algorithm
    # It returns two lists with the time it takes to find x, one list per search

    linear_times = []
    binary_times = []

    for trial in range(trials):

        arr = random.sample(range(1000), 2**(trial+4))

        for i in input:

            tic = time.perf_counter()
            linear_search(arr, i)
            toc = time.perf_counter()
            linear_times.append(toc-tic)

            tic = time.perf_counter()
            binary_search(arr, i, 0, len(arr)-1)
            toc = time.perf_counter()
            binary_times.append(toc-tic)

    return linear_times, binary_times

# Reading testing data from input text file

file = open("input_1000.txt", "r")
input = file.read()
file.close()
input = input.split(",")
if input[-1] == '': # There is an akward comma at the end of this input data, so we remove the last index
    input.pop()
input = [eval(i) for i in input]

# Comparing the search functions

linear_times, binary_times = compare_searches(input, 3)

print(linear_times)
print(binary_times)