// Created by Dayu Wang (dwang@stchas.edu) on 2023-06-20

// Last updated by Dayu Wang (dwang@stchas.edu) on 2023-06-20


#ifndef NODE_H
#define NODE_H

#include <stddef.h>

/** A singly-linked list node */
template<class T>
struct Node {
    // Data fields
    T data;  // Stores some data in the node.
    Node<T>* next;  // Stores a pointer to the next node in the list.

    // Constructor
    Node(const T&, Node<T>* = NULL);
};

// Constructor
template<class T>
Node<T>::Node(const T& data, Node<T>* next) : data(data), next(next) {}

#endif