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
        const int row_size = matrix.size();
 
        int sum = 0;

        for (int i = 0; i < row_size; i++) {
            
            pair<int, int> PairOne(i, i);
            pair<int, int> PairTwo(i, row_size - 1 - i);

            if (PairOne == PairTwo) {
                sum += matrix[i][i];
                i++;
            }
            sum += matrix[i][i] + matrix[i][row_size - 1 - i];
        }
        
        return sum;
    }
};




#endif


