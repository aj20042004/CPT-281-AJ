// Created by Dayu Wang (dwang@stchas.edu) on 2023-03-27

// Last updated by Dayu Wang (dwang@stchas.edu) on 2023-03-27


#ifndef SORTING_H
#define SORTING_H

#include <algorithm>
#include <vector>

using std::swap;
using std::vector;

// Selection sort
void selection_sort(vector<int>& vec) {
    for (size_t i = 0; i < vec.size(); i++) {
        // Stores the index of the min value in the rest of the vector.
        size_t min = i;

        // Find the min value in the rest of the vector.
        for (size_t j = i + 1; j < vec.size(); j++) {
            if (vec.at(j) < vec.at(min)) { min = j; }
        }

        // Swap vec.at(min) with vec.at(i) if they are not the same.
        if (min != i) { swap(vec.at(i), vec.at(min)); }
    }
}

// Bubble sort
void bubble_sort(vector<int>& vec) {
    for (size_t i = 0; i < vec.size(); i++) {
        // Stores whether a swap occurs in this iteration.
        bool swapped = false;

        for (size_t j = 1; j < vec.size(); j++) {
            if (vec.at(j) < vec.at(j - 1)) {  // Out of order
                swap(vec.at(j), vec.at(j - 1));
                swapped = true;
            }
        }

        // If no swap occurred in this iteration,
        // then the vector is already sorted.
        if (!swapped) { return; }
    }
}

// Insertion sort
void insertion_sort(vector<int>& vec) {
    for (size_t mark = 1; mark < vec.size(); mark++) {
        int key = vec.at(mark), j;
        for (j = mark - 1; j >= 0 && vec.at(j) > key; j--) {
            vec.at(j + 1) = vec.at(j);  // Data shift
        }
        vec.at(j + 1) = key;
    }
}

/** Merges two sorted vectors into a single sorted vector.
    @param vec_1: first sorted vector to merge
    @param vec_2: second sorted vector to merge
    @param vec_3: merged vector
*/
void merge(const vector<int>& vec_1, const vector<int>& vec_2,
    vector<int>& vec_3) {
    size_t i = 0, j = 0, k = 0;
    while (i < vec_1.size() && j < vec_2.size()) {
        if (vec_1.at(i) <= vec_2.at(j)) { vec_3.at(k++) = vec_1.at(i++); }
        else { vec_3.at(k++) = vec_2.at(j++); }
    }
    while (i < vec_1.size()) { vec_3.at(k++) = vec_1.at(i++); }
    while (j < vec_2.size()) { vec_3.at(k++) = vec_2.at(j++); }
}

// Merge sort
void merge_sort(vector<int>& vec) {
    // Base case
    if (vec.size() < 2) { return; }

    // Copy the left and right half of the vector into 2 other vectors.
    vector<int> left, right;
    for (size_t i = 0; i < vec.size(); i++) {
        if (i < vec.size() / 2) { left.push_back(vec.at(i)); }
        else { right.push_back(vec.at(i)); }
    }

    // Sort "left" and "right" recursively.
    merge_sort(left);
    merge_sort(right);

    // Merge the sorted left and right half.
    merge(left, right, vec);
}

#endif