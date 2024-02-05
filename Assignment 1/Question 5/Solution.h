#ifndef SOLUTION_H
#define SOLUTION_H

#include <iostream>
#include <vector>

// Am I allowed to use make pair method ? 

using namespace std;

class Solution {
public:
    /** Calculates the sum the diagonal elements in a square matrix.
        @param matrix: a non-empty square matrix
        @return: calculated sum of the diagonal elements in the matrix
    */
    static int sum_diagonal_elements(const vector<vector<int>>& matrix) {
        // Please copy this code to Canvas answer textbox.
        // Please add your code here to solve the problem.

        // Storing the size of the matrix in variable "row_size"
        const int row_size = matrix.size();

        // Initializing a variable to calculate the sum
        int sum = 0;

        // Iterating the vector using loop
        for (int i = 0; i < row_size; i++) {

            // Adding the element from the primary diagnol
            sum += matrix[i][i];

            // Avoids double counting for elements in the intersection
            if (i != row_size - 1 - i) {

                // Adding the element from the secondary diagnol
                sum += matrix[i][row_size - 1 - i];
            }   
        }

        // returning the sum
        return sum;
    }
};




#endif
