#ifndef SOLUTION1_H
#define SOLUTION1_H

#include <iostream>
#include <vector>

// Am I allowed to use make pair method ? 

using namespace std;

class Solution {
public:
	/*  Calculates the sum the diagonal elements in a square matrix.
		@param matrix: a non-empty square matrix
		@return: calculated sum of the diagonal elements in the matrix */

	static int sum_diagonal_elements(const vector<vector<int>>& matrix) {
		// Please copy this code to Canvas answer textbox.
		// Please add your code here to solve the problem.

		vector<pair<int, int>> storage;
		const int row_size = matrix.size();

		int sum = 0;

		for (int i = 0; i < row_size; i++) {
			sum += matrix[i][i];
			storage.push_back(make_pair(i, i));
		}

		for (int k = 0; k < row_size; k++) {

			pair<int, int> numPair(k, row_size - 1 - k);
			if (find(storage.begin(), storage.end(), numPair) == storage.end()) {
				sum += matrix[k][row_size - 1 - k];
			}
		}

		return sum;
	}
};





#endif
