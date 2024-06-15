# This script tests sorting algorithms

# Imports
import time
import matplotlib.pyplot as plt; plt.rcParams['figure.dpi'] = 300
import numpy as np

# Insertion Sort
def insertion_sort(arr:list):

    for i in range(1, len(arr)): # skip the 0th index

        key = arr[i] 
        j = i - 1 # insert arr[i] into the sorted sequence arr[1] to arr[j-1]

        while (j > 0 and arr[j] > key):

            arr[j + 1] = arr[j]
            j -= 1 # j decreases until it reaches a smaller number or it's the first index of the array

        arr[j + 1] = key

    return arr


# Reading input files
sample_sizes = [1000, 2500, 5000, 10000, 25000, 50000, 100000, 250000, 500000, 1000000]
inputs = []

for sample_size in sample_sizes: # Create a list of lists of input samples

    file = open("" + str(sample_size) + ".txt", "r")
    input = file.read()
    file.close()
    input = input.split()
    if input[-1] == '':
        input.pop()
    input = [eval(i) for i in input]

    inputs.append(input)

# Testing insertion search

sorted_inputs = []
insertion_times = []

for input in inputs:

    tic = time.perf_counter()
    sorted_inputs.append(insertion_sort(input))
    toc = time.perf_counter()
    insertion_times.append(toc-tic)

print(insertion_sort([2, 9, 101, 3853029342, 5738, 1, 78, 303, 304]))
#print(sorted_inputs)

# Plot
fig, ax = plt.subplots(figsize=(4,2))
ax.plot(sample_sizes, insertion_times,'o', c='#8080FF', alpha=0.9, markeredgecolor='k', 
        label ='Insertion Sort Times')
#ax.plot(x_axis, binary_times,'o', c='#A020F0', alpha=0.9, markeredgecolor='k', 
#       label ='Binary Search Times')
ax.set_xscale('log')
ax.set_yscale('log')
#ax.xaxis.set_major_locator(mticker.FixedLocator(x_axis))
#ax.set_xticks(x_axis)
ax.set_xlabel('Array Size')
ax.set_ylabel('Time (seconds)')
ax.tick_params(axis='both', which='major', labelsize=8)
ax.tick_params(axis='both', which='minor', labelsize=6)
ax.legend(loc='upper left', fontsize='xx-small')
fig.tight_layout()
fig.savefig('Insertion_Sort_Graph')
plt.show()