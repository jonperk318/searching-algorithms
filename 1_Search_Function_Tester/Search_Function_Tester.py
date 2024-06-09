# Imports
import time
import matplotlib.pyplot as plt; plt.rcParams['figure.dpi'] = 300
import matplotlib.ticker as mticker
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

# Comparing linear and binary searches
def compare_searches(input:list, trials:int):

    # This funciton finds the time it takes to find x using each search algorithm
    # It returns two lists with the time it takes to find x, one list per search

    sorted_input = input
    sorted_input.sort()
    linear_times = []
    binary_times = []

    for trial in range(trials):

        arr = [] # Create array with 2^n randomly chosen numbers between 0 and 999
        [arr.append(random.choice(range(1000))) for _ in range(2**(trial+4))]

        tic = time.perf_counter() # Record time before trial
        [linear_search(arr, i) for i in input]
        toc = time.perf_counter() # Record time after trial
        linear_times.append(toc-tic) # Create array with time it took to compute each trial

        tic = time.perf_counter()
        [binary_search(arr, i, 0, len(arr)-1) for i in sorted_input]    
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
trials = 16
linear_times, binary_times = compare_searches(input, trials)

print("Linear search times: ", linear_times)
print("Binary search times: ", binary_times)

# Creating the plot
fig, ax = plt.subplots(figsize=(4,2))
x_axis = [2**t for t in range(4, trials+4)]
print("Array Sizes: ", x_axis)
ax.plot(x_axis, linear_times,'o', c='#8080FF', alpha=0.9, markeredgecolor='k', label ='Linear Search Times')
ax.plot(x_axis, binary_times,'o', c='#A020F0', alpha=0.9, markeredgecolor='k', label ='Binary Search Times')
ax.set_xscale('log')
ax.set_yscale('log')
#ax.xaxis.set_major_locator(mticker.FixedLocator(x_axis))
#ax.set_xticks(x_axis)
#ax.set_xticks(x_axis)
ax.set_xlabel('Array Size')
ax.set_ylabel('Time (seconds)')
ax.tick_params(axis='both', which='major', labelsize=8)
ax.tick_params(axis='both', which='minor', labelsize=6)
ax.legend(loc='upper left', fontsize='xx-small')
fig.tight_layout()
#fig.savefig('Search_Functions_Graph_Log_Scale')
plt.show()