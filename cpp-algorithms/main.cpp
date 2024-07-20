using namespace std;
#include <iostream>
#include <vector>
#include <fstream>
#include "quick_sort.h"

void test();
void print_array(const vector<int>& arr);
void print_array_doubles(const vector<double>& arr);
int linear_search(vector<int> arr, int key);
int binary_search(vector<int> arr, int key, int low, int high);
int ternary_search(vector<int> arr, int key, int low, int high);


int main() {

    // Uncomment to run test
    // test();


    // get sizes of sample arrays

    ifstream sample_sizes_file("../../samples/sample-sizes.txt");
    if (!sample_sizes_file.is_open()) { // there should be no error opening the file
        cerr << "Error opening the file!" << endl;
        return 1;
    }
    vector<string> sample_sizes_strings; // initialize array to read the strings of numbers into
    while (sample_sizes_file.good()) {
        string substr;
        getline(sample_sizes_file, substr, ','); // split each string by the "," delineator
        sample_sizes_strings.push_back(substr);
    }
    sample_sizes_file.close();
    vector<int> sample_sizes; // initialize array to store integers
    for (const auto & sample_sizes_string : sample_sizes_strings) {
        sample_sizes.push_back(stoi(sample_sizes_string)); // convert string to integer
    }

    // create a list of lists of input samples

    vector<vector<int>> samples;

    for (int sample_size : sample_sizes) {

        string str = ("../../samples/" + to_string(sample_size) + ".txt");
        ifstream input_file(str.c_str());

        if (!input_file.is_open()) { // there should be no error opening the file
            cerr << "Error opening the file!" << endl;
            return 1;
        }

        vector<string> result; // initialize array to read the strings of numbers into
        while (input_file.good()) {
            string substr;
            getline(input_file, substr, ','); // split each string by the "," delineator
            result.push_back(substr);
        }

        input_file.close();
        vector<int> values; // initialize array to store integers

        for(const auto & value : result) {
            values.push_back(stoi(value)); // convert string to integer
        }
        samples.push_back(values); // add unsorted array to array of inputs
    }

    vector<vector<int>> sorted_samples = samples;
    for (vector<int>& sorted_sample : sorted_samples) {
        quick_sort(sorted_sample, 0, sorted_sample.size() - 1);
    }

    //print_array(samples[0]);
    //print_array(sorted_samples[0]);

    // get list array of random ints

    ifstream random_ints_file("../../samples/random-ints.txt");
    if (!random_ints_file.is_open()) { // there should be no error opening the file
        cerr << "Error opening the file!" << endl;
        return 1;
    }
    vector<string> random_ints_strings; // initialize array to read the strings of numbers into
    while (random_ints_file.good()) {
        string substr;
        getline(random_ints_file, substr, ','); // split each string by the "," delineator
        random_ints_strings.push_back(substr);
    }
    random_ints_file.close();
    vector<int> random_ints; // initialize array to store random ints
    for (int i = 0; i < random_ints_strings.size(); i++) {
        random_ints.push_back(stoi(random_ints_strings[i])); // convert string to integer
    }

    vector<double> linear_times_1, linear_times_2, linear_times_3, binary_times_1,
    binary_times_2, binary_times_3, ternary_times_1, ternary_times_2, ternary_times_3;

    // RUN ALL SORTING FUNCTIONS

    for (int i = 0; i < samples.size(); i++) {

        int random_int = random_ints[i]; // test all three algorithms on same arr and same key
        int notPresentInt = 1000001;

        // Linear search with random key
        auto tick = chrono::high_resolution_clock::now();
        linear_search(samples[i], random_int);
        auto tock = chrono::high_resolution_clock::now();
        auto duration = double(duration_cast<chrono::nanoseconds>(tock - tick).count());
        linear_times_1.push_back(duration / 1000000000);

        // Linear search with key equal to first element in array
        tick = chrono::high_resolution_clock::now();
        linear_search(samples[i], samples[i][0]);
        tock = chrono::high_resolution_clock::now();
        duration = double(duration_cast<chrono::nanoseconds>(tock - tick).count());
        linear_times_2.push_back(duration / 1000000000);

        // Linear search with key not present in array
        tick = chrono::high_resolution_clock::now();
        linear_search(samples[i], notPresentInt);
        tock = chrono::high_resolution_clock::now();
        duration = double(duration_cast<chrono::nanoseconds>(tock - tick).count());
        linear_times_3.push_back(duration / 1000000000);

        // Binary search with random key
        tick = chrono::high_resolution_clock::now();
        binary_search(sorted_samples[i], random_int, 0, sorted_samples[i].size() - 1);
        tock = chrono::high_resolution_clock::now();
        duration = double(duration_cast<chrono::nanoseconds>(tock - tick).count());
        binary_times_1.push_back(duration / 1000000000);

        // Binary search with key equal to first element in array
        tick = chrono::high_resolution_clock::now();
        binary_search(sorted_samples[i], sorted_samples[i][0], 0, sorted_samples[i].size() - 1);
        tock = chrono::high_resolution_clock::now();
        duration = double(duration_cast<chrono::nanoseconds>(tock - tick).count());
        binary_times_2.push_back(duration / 1000000000);

        // Binary search with key not present in array
        tick = chrono::high_resolution_clock::now();
        binary_search(sorted_samples[i], notPresentInt, 0, sorted_samples[i].size() - 1);
        tock = chrono::high_resolution_clock::now();
        duration = double(duration_cast<chrono::nanoseconds>(tock - tick).count());
        binary_times_3.push_back(duration / 1000000000);

        // Ternary search with random key
        tick = chrono::high_resolution_clock::now();
        ternary_search(sorted_samples[i], random_int, 0, sorted_samples[i].size() - 1);
        tock = chrono::high_resolution_clock::now();
        duration = double(duration_cast<chrono::nanoseconds>(tock - tick).count());
        ternary_times_1.push_back(duration / 1000000000);

        // Ternary search with key equal to first element in array
        tick = chrono::high_resolution_clock::now();
        ternary_search(sorted_samples[i], sorted_samples[i][0], 0, sorted_samples[i].size() - 1);
        tock = chrono::high_resolution_clock::now();
        duration = double(duration_cast<chrono::nanoseconds>(tock - tick).count());
        ternary_times_2.push_back(duration / 1000000000);

        // Ternary search with key not present in array
        tick = chrono::high_resolution_clock::now();
        ternary_search(sorted_samples[i], notPresentInt, 0, sorted_samples[i].size() - 1);
        tock = chrono::high_resolution_clock::now();
        duration = double(duration_cast<chrono::nanoseconds>(tock - tick).count());
        ternary_times_3.push_back(duration / 1000000000);

        cout << "Searched array of length " << sample_sizes[i] << endl;
    }

    vector<vector<double>> searching_times {linear_times_1, linear_times_2, linear_times_3,
    binary_times_1, binary_times_2, binary_times_3, ternary_times_1, ternary_times_2, ternary_times_3};
    vector<string> searching_names {"linear-times-1", "linear-times-2", "linear-times-3", "binary-times-1",
                "binary-times-2", "binary-times-3", "ternary-times-1", "ternary-times-2", "ternary-times-3"};

    for (int i = 0; i < searching_times.size(); i++) {

        ofstream output_file("../cpp-searching-times/cpp-" + searching_names[i] + ".txt");

        if (output_file.is_open()) {

            for (double j : searching_times[i]) {
                output_file << j << ",";
            }
        }
    }

    return 0;
}