// Created by Dayu Wang (dwang@stchas.edu) on 2023-06-20

// Last updated by Dayu Wang (dwang@stchas.edu) on 2023-06-20


#ifndef D_NODE_H
#define D_NODE_H

#include <stddef.h>

/** A doubly-linked list node */
template<class T>
struct D_Node {
    // Data fields
    T data;  // Stores some data in the node.
    D_Node<T>* next;  // Stores a pointer to the next node in the list.
    D_Node<T>* prev;  // Stores a pointer to the previous node in the list.

    // Constructor
    D_Node(const T&, D_Node<T>* = NULL, D_Node<T>* = NULL);
};

// Constructor
template<class T>
D_Node<T>::D_Node(const T& data, D_Node<T>* next, D_Node<T>* prev) :
    data(data), next(next), prev(prev) {}

#endif