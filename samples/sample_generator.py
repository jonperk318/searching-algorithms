"""
This is a script written to generate input files of various sizes to 
read into the main scripts and test the searching functions
"""

import random
import os
import numpy as np

int_range_high = 1000000
array_size_low = 100
array_size_high = 1000000
array_amount = 50

current_dir = os.path.dirname(__file__) # ensure script writes files to current directory
sample_sizes = np.geomspace(array_size_low, array_size_high, array_amount, endpoint=True) # 50 logarithmically spaced values
sample_sizes = [int(i) for i in sample_sizes] # convert to integers
print("Sample sizes: " + str(sample_sizes))

ss_file_path = os.path.join(current_dir, "sample-sizes.txt")
with open(ss_file_path, "w") as file: # write sample sizes to txt file
    sample_string = ",".join([str(i) for i in sample_sizes]) # separate ints by commas
    file.write(sample_string)

for s in sample_sizes:

    file_path = os.path.join(current_dir, str(s) + ".txt")

    with open(file_path, "w") as file:

        rand_list = []

        # creating list of random ints from 0 to 999,999
        for i in range(s):
            rand_list.append(random.randint(0, int_range_high)) 
        
        rand_string = ",".join([str(j) for j in rand_list]) # separating ints by commas
        file.write(rand_string) # write results to file

# generate a list of random ints to test, one for each sample size

random_ints = []
for i in range(array_amount):
    random_ints.append(random.randint(0, int_range_high))

file_path = os.path.join(current_dir, "random-ints.txt")
with open(file_path, "w") as file:

    randon_ints_string = ",".join([str(j) for j in random_ints])
    file.write(randon_ints_string)