// Created by Dayu Wang (dwang@stchas.edu) on 2023-07-02

// Last updated by Dayu Wang (dwang@stchas.edu) on 2023-07-02


#ifndef RECURSION_H
#define RECURSION_H

#include <algorithm>
#include <iterator>
#include <vector>

using std::back_inserter;
using std::max;
using std::vector;

class Recursion {
public:
    // Wrapper function
    static int sum(const vector<int>& vec) { return sum(vec, 0, vec.size() - 1); }  // Time complexity: O(n)

    /** Finds the length of the longest increasing segment in a vector.
        @param vec: a non-empty vector of integers
        @return: length of the longest increasing segment
    */
    unsigned int len(const vector<int>& vec) {
        if (vec.size() == 1) { return 1; }
        vector<int> left, right;
        copy(vec.begin(), vec.begin() + vec.size() / 2, back_inserter(left));
        copy(vec.begin() + vec.size() / 2, vec.end(), back_inserter(right));
        unsigned int c_1 = len(left);  // First candidate
        unsigned int c_2 = len(right);  // Second candidate
        size_t i, j;
        for (i = vec.size() / 2; i >= 1; i--) {
            if (vec.at(i - 1) >= vec.at(i)) { break; }
        }
        for (j = vec.size() / 2; j < vec.size() - 1; j++) {
            if (vec.at(j + 1) <= vec.at(j)) { break; }
        }
        unsigned int c_3 = j - i + 1;  // Third candidate
        return max({ c_1, c_2, c_3 });
    }

private:
    /** Sums up the segment of a vector from index i to index j.
        @param vec: vector whose segment is to sum up
        @param i: inclusive beginning index of the segment
        @param j: inclusive end index of the segment
        @return: sum of all the elements in the segment
    */
    static int sum(const vector<int>& vec, size_t i, size_t j) {
        if (i > j) { return 0; }  // Base case
        return vec.at(i) + sum(vec, i + 1, j);  // Recurrence relation
    }  // Time complexity: O(n)
};

#endif