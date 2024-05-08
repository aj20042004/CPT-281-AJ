// Created by Dayu Wang (dwang@stchas.edu) on 2023-03-27

// Last updated by Dayu Wang (dwang@stchas.edu) on 2024-03-31


#ifndef BITWISE_OPERATIONS_H
#define BITWISE_OPERATIONS_H

#include <vector>

using std::vector;

/** Tests whether a non-negative integer is an odd number.
    @param n: a non-negative integer to test
    @return: {true} if n is an odd number; {false} if it is even.
*/
bool is_odd(unsigned int n) { return n & 1; }

/** Tests whether a positive integer is power of two.
    @param n: a positive integer to test
    @return: {true} if n is power of two; {false} otherwise
*/
bool is_power_of_two(unsigned int n) { return !(n & n - 1); }

/** Swap two integers without using temporary variables.
    @param a: first integer to swap
    @param b: second integer to swap
*/
void swap_integers(int& a, int& b) {
    a ^= b;
    b ^= a;
    a ^= b;
}

// Single Number I
int single_number(const vector<int>& vec) {
    int result = 0;
    for (int num : vec) { result ^= num; }
    return result;
}

#endif