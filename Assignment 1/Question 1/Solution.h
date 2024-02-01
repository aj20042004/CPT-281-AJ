#ifndef SOLUTION_H
#define SOLUTION_H

#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

// input string: "datastructures"
// output string: "dtstrctrs"


class Solution {
public:
    /** Removes all the vowels from a string.
        @param s: a string that contains only lowercase letters
        @return: a copy of the input string with all the vowels removed
    */
    static string remove_vowels(const string& s) {
        // Please copy this code to Canvas answer textbox.
        // Please add your code here to solve the problem.s

        unordered_set<char> vowels = {'a','e','i','o','u'};
        
        string new_string;

        for (char search_value : s) {
            if (vowels.find(search_value) == vowels.end()) {
                new_string.push_back(search_value);
            }
        }
        return new_string;
   
    }
};



#endif

