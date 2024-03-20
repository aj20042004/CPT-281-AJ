#ifndef Q4MAXANDMIN_H
#define Q4MAXANDMIN_H

#include <iostream>
#include <vector>
#include <list>

using namespace std;


class Solution_for_Q4 {
public:
    /** Finds the max and second max value in a linked list.
        @param li: a linked list that has at least two elements
        @return: a vector containing the max and second max value
    */
    static vector<int> max_and_second_max(const list<int>& li) {
        // Please copy this code to Canvas answer textbox.
        // Please add your code here to solve the problem.

        // Checking whether the list has at least 2 nodes
        if (li.size() < 2) {
            throw exception("List must at least have 2 nodes");
        }

        // Creating the iterator
        list<int>::const_iterator it;

        // Creating a vector to store the max nad second max values
        vector<int> max_and_secondMax;

        // Initializing the max and second max
        int max = INT_MIN;
        int second_max = INT_MIN;

        // Using iterator to traverse the linked list
        for (it = li.begin(); it != li.end(); it++) {

            // If the current iterator node is greater or equal to max, we're updating the max and second max
            if (*it >= max) {
                second_max = max;
                max = *it;
            } 
        }

        // Adding the max and second max values to the vector
        max_and_secondMax.push_back(max);
        max_and_secondMax.push_back(second_max);

        // returing the vector
        return max_and_secondMax;

    }
};


#endif
