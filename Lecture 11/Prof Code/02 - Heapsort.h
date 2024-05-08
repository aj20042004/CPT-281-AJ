// Created by Dayu Wang (dwang@stchas.edu) on 2022-11-14

// Last updated by Dayu Wang (dwang@stchas.edu) on 2022-11-14


#ifndef HEAPSORT_H
#define HEAPSORT_H

#include <algorithm>
#include <vector>

using std::swap;
using std::vector;

template<class T>
class Heapsort {
public:
    static void sort(vector<T>&);  // Wrapper function

private:
    static void max_heapify(vector<T>&, size_t, size_t);  // Moves the root downward to form a max heap.
    static void build_max_heap(vector<T>&, size_t);  // Generates a max heap rooted at given index.
    static void sort(vector<T>&, size_t);  // Sorts a vector of given size.
};

/** Moves the root downward to form a max heap.
    @param vec: vector to sort
    @param root: index of the root
    @param size: size of the vector
*/
template<class T>
void Heapsort<T>::max_heapify(vector<T>& vec, size_t root, size_t size) {
    size_t left = root * 2 + 1, right = root * 2 + 2, max = root;
    if (left < size && vec.at(max) < vec.at(left)) { max = left; }
    if (right < size && vec.at(max) < vec.at(right)) { max = right; }
    if (max != root) {
        swap(vec.at(root), vec.at(max));
        max_heapify(vec, max, size);
    }
}  // Time complexity: O(log(n))

/** Generates a max heap rooted at given index.
    @param vec: vector to sort
    @param root: index of the root
*/
template<class T>
void Heapsort<T>::build_max_heap(vector<T>& vec, size_t root) {
    size_t left = root * 2 + 1, right = root * 2 + 2;
    if (left < vec.size()) { build_max_heap(vec, left); }
    if (right < vec.size()) { build_max_heap(vec, right); }
    max_heapify(vec, root, vec.size());
}  // Time complexity: O(log(n))

/** Sorts a vector of given size.
    @param vec: vector to sort
    @param size: size of the vector
*/
template<class T>
void Heapsort<T>::sort(vector<T>& vec, size_t size) {
    build_max_heap(vec, 0);
    for (size_t i = size - 1; i > 0; i--) {
        swap(vec.at(0), vec.at(i));
        max_heapify(vec, 0, --size);
    }
}  // Time complexity: O(n * log(n))

// Wrapper function
template<class T>
void Heapsort<T>::sort(vector<T>& vec) { sort(vec, vec.size()); }  // Time complexity: O(n * log(n))

#endif