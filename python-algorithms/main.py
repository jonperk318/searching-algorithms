"""
This script tests all 3 searching algorithms using the randomly generated input files
and stores their run times in a text file to be plotted elsewhere
"""

from linear_search import linear_search
from binary_search import binary_search
from ternary_search import ternary_search

import os
import time

current_dir = os.path.dirname(__file__) # ensure script reads files from correct directory
ss_file_path = os.path.join(current_dir, "../samples/sample-sizes.txt")

# get sizes of sample arrays
with open(ss_file_path, "r") as file:
    sample_sizes = file.read()
sample_sizes = sample_sizes.split(",")
if sample_sizes[-1] == "": # if last value in array is empty, remove it
    sample_sizes.pop()
sample_sizes = [eval(i) for i in sample_sizes]

samples = []
sorted_samples = []

# create a list of lists of input samples
for size in sample_sizes:

    r_file_path = os.path.join(current_dir, "../samples/" + str(size) + ".txt")
    with open(r_file_path, "r") as file:
        sample = file.read()
    sample = sample.split(",")
    if sample[-1] == "": # if last value in array is empty, remove it
        sample.pop()
    sample = [eval(i) for i in sample] # get int from string

    samples.append(sample)
    sorted_samples.append(sorted(sample))

# get list of random ints
random_int_file_path = os.path.join(current_dir, "../samples/random-ints.txt")
with open(random_int_file_path, "r") as file:
    random_ints = file.read()
random_ints = random_ints.split(",")
if random_ints[-1] == "": # if last value in array is empty, remove it
    random_ints.pop()
random_ints = [eval(i) for i in random_ints]

(linear_times_1, binary_times_1, ternary_times_1, linear_times_2, binary_times_2, ternary_times_2, 
 linear_times_3, binary_times_3, ternary_times_3) = [], [], [], [], [], [], [], [], []

for i in range(len(samples)): # RUN ALL SEARCHING FUNCTIONS

    random_int = random_ints[i]
    not_present_int = 1000001

    # Linear search with random key
    tick = time.perf_counter()
    linear_search(samples[i], random_int) 
    tock = time.perf_counter()
    linear_times_1.append(tock - tick)

    # Linear search with key equal to first element in array
    tick = time.perf_counter()
    linear_search(samples[i], samples[i][0])
    tock = time.perf_counter()
    linear_times_2.append(tock - tick)

    # Linear search with key not present in array
    tick = time.perf_counter()
    linear_search(samples[i], not_present_int)
    tock = time.perf_counter()
    linear_times_3.append(tock - tick)

    # Binary search with random key
    tick = time.perf_counter()
    binary_search(sorted_samples[i], random_int)
    tock = time.perf_counter()
    binary_times_1.append(tock - tick)

    # Binary search with key equal to first element in array
    tick = time.perf_counter()
    binary_search(sorted_samples[i], sorted_samples[i][0])
    tock = time.perf_counter()
    binary_times_2.append(tock - tick)

    # Binary search with key not present in array
    tick = time.perf_counter()
    binary_search(sorted_samples[i], not_present_int)
    tock = time.perf_counter()
    binary_times_3.append(tock - tick)

    # Ternary search with random key
    tick = time.perf_counter()
    ternary_search(sorted_samples[i], random_int)
    tock = time.perf_counter()
    ternary_times_1.append(tock - tick)

    # Ternary search with key equal to first element in array
    tick = time.perf_counter()
    ternary_search(sorted_samples[i], sorted_samples[i][0])
    tock = time.perf_counter()
    ternary_times_2.append(tock - tick)

    # Ternary search with key not present in array
    tick = time.perf_counter()
    ternary_search(sorted_samples[i], not_present_int)
    tock = time.perf_counter()
    ternary_times_3.append(tock - tick)

    print("Searched array of length " + str(sample_sizes[i]))


# write search times to separate files

searching_times = [linear_times_1, linear_times_2, linear_times_3, binary_times_1, binary_times_2, 
                binary_times_3, ternary_times_1, ternary_times_2, ternary_times_3]
searching_names = ["linear-times-1", "linear-times-2", "linear-times-3", "binary-times-1", "binary-times-2", 
                 "binary-times-3", "ternary-times-1", "ternary-times-2", "ternary-times-3"]

for i in range(len(searching_times)):

    w_file_path = os.path.join(current_dir, "python-searching-times/python-" + 
                               searching_names[i] + ".txt")

    with open(w_file_path, "w") as file:

        time_string = ",".join([str(time) for time in searching_times[i]])
        file.write(time_string)