#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>
#include <vector>
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
        // Please add your code here to solve the problem.

        // Creating a string variable
        string new_string;

        // Iterating through the parameter string
        for (char search_value : s) {

            // Checking if any character is a vowel (a,e,i,o,u)
            if (search_value == 'a' || search_value == 'e' || search_value == 'i' || search_value == 'o' || search_value == 'u') {

                // Skipping this iteration if the character is a vowel
                continue;
            }

            // Adding the character to the "new_string" if it's not a vowel
            new_string.push_back(search_value);
        }

        // return the edited string
        return new_string;

    }
};



#endif
