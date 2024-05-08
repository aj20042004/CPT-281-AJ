// Created by Dayu Wang (dwang@stchas.edu) on 2024-04-14

// Last updated by Dayu Wang (dwang@stchas.edu) on 2024-04-14


#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using std::make_pair;
using std::map;
using std::pair;
using std::set;
using std::unordered_map;
using std::unordered_set;
using std::vector;

/** Finds all the unique values in a vector.
    @param vec: input vector (not sorted in any way)
    @return: a vector containing all the unique values in the input vector
*/
vector<int> unique_values(const vector<int>& vec) {
    unordered_set<int> us;  // Create an unordered_set to store all the discovered values.
    vector<int> result;  // Stores the unique values.
    for (size_t i = 0; i < vec.size(); i++) {
        if (us.find(vec.at(i)) == us.end()) {
            result.push_back(vec.at(i));
            us.insert(vec.at(i));
        }
    }
    return result;
}  // Time complexity: O(n) -> Average

/** Finds the duplicate number and missing number in a vector.
    @param vec: a vector containing one duplicate number and one missing number
    @return: a pair containing the duplicate number and missing number (in that order)
*/
pair<int, int> find_error_nums(const vector<int>& vec) {
    set<int> s;
    int d;  // Duplicate value
    for (size_t i = 0; i < vec.size(); i++) {
        if (s.find(vec.at(i)) != s.end()) { d = vec.at(i); }
        else { s.insert(vec.at(i)); }
    }
    int n = 1;
    for (set<int>::iterator it = s.begin(); it != s.end(); it++, n++) {
        if (*it != n) { return make_pair(d, n); }
    }
    return make_pair(d, n);
}  // Time complexity: O(n * log(n))

/** Finds the value with highest frequency in a vector.
    @param vec: a non-empty vector that is not sorted in any way
    @return: value with highest frequency in the vector
*/
int most_frequent_value(const vector<int>& vec) {
    // Store the frequency of each value into an unordered map.
    unordered_map<int, unsigned int> m;
    for (size_t i = 0; i < vec.size(); i++) {
        if (m.find(vec.at(i)) == m.end()) { m[vec.at(i)] = 1; }
        else { m[vec.at(i)]++; }
    }
    // Find the max value in the unordered map.
    int result = 0;
    unsigned int f = 0;
    for (unordered_map<int, unsigned int>::iterator it = m.begin(); it != m.end(); it++) {
        if (it->second > f) {
            result = it->first;
            f = it->second;
        }
    }
    return result;
}  // Time complexity: O(n) -> Average

#endif