// Created by Dayu Wang (dwang@stchas.edu) on 2022-11-07

// Last updated by Dayu Wang (dwang@stchas.edu) on 2024-03-31


#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "BTNode.h"

#include <vector>

using std::vector;

/** Generates a sorted vector from a binary search tree.
    @param root: a pointer to the root node of the binary search tree
    @return: a sorted vector generated from the binary search tree
*/
template<class T>
vector<T> to_vector(const BTNode<T>* root) {
    // Base case
    if (!root) { return vector<T>(); }
    // Generate a sorted vector representing the left subtree.
    vector<T> left;
    if (root->left) { left = to_vector(root->left); }
    // Generate a sorted vector representing the right subtree.
    vector<T> right;
    if (root->right) { right = to_vector(root->right); }
    // Generate the result vector.
    vector<T> result;
    result.insert(result.end(), left.begin(), left.end());
    result.push_back(root->data);
    result.insert(result.end(), right.begin(), right.end());
    return result;
}  // Time complexity: O(n)

/** Generates a balanced binary search tree from a segment of a sorted vector.
    @param vec: a sorted vector
    @param i: index of the beginning of the segment
    @param j: index of the end of the segment
    @return: pointer to the root of a BST generated from the vector
*/
template<class T>
BTNode<T>* to_bst(const vector<T>& vec, int i, int j) {
    if (i > j) { return NULL; }  // Base case
    int mid = (i + j) / 2;  // Get the middle value.
    BTNode<T>* left = to_bst(vec, i, mid - 1);  // Recursively generate the left subtree.
    BTNode<T>* right = to_bst(vec, mid + 1, j);  // Recursively generate the right subtree.
    return new BTNode<T>(vec.at(mid), left, right);
}  // Time complexity: O(n)

// Wrapper function
template<class T>
BTNode<T>* to_bst(const vector<T>& vec) { return to_bst(vec, 0, vec.size() - 1); }

/** Returns the minimum key in a binary search tree.
    @param root: a non-NULL pointer to the root node of the binary search tree
    @return: a const reference to the minimum key in the binary search tree
*/
template<class T>
const T& min_key(const BTNode<T>* root) {
    BTNode<T>* p = root;
    while (p->left) { p = p->left; }
    return p->data;
}  // Time complexity: O(h)

/** Returns the maximum key in a binary search tree.
    @param root: a non-NULL pointer to the root node of the binary search tree
    @return: a const reference to the maximum key in the binary search tree
*/
template<class T>
const T& max_key(const BTNode<T>* root) {
    BTNode<T>* p = root;
    while (p->right) { p = p->right; }
    return p->data;
}  // Time complexity: O(h)

#endif