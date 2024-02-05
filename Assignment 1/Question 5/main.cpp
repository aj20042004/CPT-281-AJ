#include <iostream>
#include <vector>
#include <sstream>
#include "Solution.h"

using namespace std;

int main() {
    // Initialize a 2D vector with specific values
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    std::vector<std::vector<int>> matrix_2 = {
    {1, 1, 1,1},
    {1, 1, 1,1},
    {1, 1, 1,1},
    {1, 1, 1,1}
    };

    vector<vector<int>> matrix_3 = {
        {5}
    };

    Solution sol;

    cout << "The Sum is: " << sol.sum_diagonal_elements(matrix) << endl;

    return 0;
}

