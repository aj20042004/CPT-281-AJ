// Created by Dayu Wang (dwang@stchas.edu) on 2022-10-31

// Last updated by Dayu Wang (dwang@stchas.edu) on 2022-10-31


#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "BTNode.h"

#include <algorithm>
#include <iostream>

using std::max;
using std::ostream;

/** Calculates the height of a binary tree.
    @param root: a pointer to the root node of the binary tree
    @return: calculated height of the binary tree
*/
template<class T>
unsigned int height(const BTNode<T>* root) {
    // Base case
    if (!root) { return 0; }
    // Recurrence relation
    return max(height(root->left), height(root->right)) + 1;
}  // Time complexity: O(n)

/** Tests whether a binary tree is full.
    @param root: a pointer to the root node of the binary tree
    @return: {true} if the binary tree is full; {false} otherwise
*/
template<class T>
bool is_full(const BTNode<T>* root) {
    // Base case
    if (!root) { return true; }

    if ((bool)root->left + (bool)root->right == 1) { return false; }

    // Recurrence relation
    return is_full(root->left) && is_full(root->right);
}  // Time complexity: O(n)

// Preorder traversal
template<class T>
void preorder_traversal(const BTNode<T>* root, ostream& out) {
    if (root) {
        out << root << ' ';
        preorder_traversal(root->left, out);
        preorder_traversal(root->right, out);
    }
}  // Time complexity: O(n)

// Inorder traversal
template<class T>
void inorder_traversal(const BTNode<T>* root, ostream& out) {
    if (root) {
        out << " ( ";
        inorder_traversal(root->left, out);
        out << ' ' << root << ' ';
        inorder_traversal(root->right, out);
        out << " ) ";
    }
}  // Time complexity: O(n)

// Postorder traversal
template<class T>
void postorder_traversal(const BTNode<T>* root, ostream& out) {
    if (root) {
        postorder_traversal(root->left, out);
        postorder_traversal(root->right, out);
        out << root << ' ';
    }
}  // Time complexity: O(n)

#endif