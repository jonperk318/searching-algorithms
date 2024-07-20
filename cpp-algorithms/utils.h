// UTILITY FUNCTIONS

#ifndef UTILS_H
#define UTILS_H

#include <ostream>
#include <vector>
using namespace std;

void print_array(const vector<int>& arr) // prints all elements of an array
{
    for (int const i : arr)
        cout << i << " ";
    cout << endl;
}

void print_array_doubles(const vector<double>& arr) // prints all elements of an array of doubles
{
    for (double const i : arr)
        cout << i << " ";
    cout << endl;
}

#endif //UTILS_H