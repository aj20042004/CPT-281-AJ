// Created by Dayu Wang (dwang@stchas.edu) on 2020-08-29

// Last updated by Dayu Wang (dwang@stchas.edu) on 2022-08-29

#ifndef ORDERED_VECTOR_H
#define ORDERED_VECTOR_H

#include "Vector.h"

#include <iostream>

template<class T>
class Ordered_Vector : public Vector<T> {
public:
    // Constructors
    Ordered_Vector();  // Default constructor
    Ordered_Vector(const Ordered_Vector<T>&);  // Copy constructor

    // Destructor
    ~Ordered_Vector();

    // Operators
    const Ordered_Vector<T>& operator = (const Ordered_Vector<T>&);  // Deep-copy assignment operator
    T& operator [] (size_t);  // Subscript operator (lvalue)

    // Class-member functions
    T& at(int);  // l-value
    T& front();  // l-value
    T& back();  // l-value
    void push_back(const T&);

    /* Question 2.4 */
    // Searches for a target element in the ordered vector.
    int find(const T&) const;
};

// Implementation of class Ordered_Vector

// Default constructor
template<class T>
Ordered_Vector<T>::Ordered_Vector() : Vector<T>() {}

// Deep-copy assignment oprator
template<class T>
const Ordered_Vector<T>& Ordered_Vector<T>::operator = (const Ordered_Vector<T>& rhs) {
    if (this != &rhs) {
        if (arr) {
            delete[] arr;
            arr = NULL;
        }
        capacity = rhs.capacity;
        num_of_items = rhs.num_of_items;
        if (capacity) {
            arr = new T[capacity];
            for (size_t i = 0; i < num_of_items; i++) {
                arr[i] = rhs.arr[i];
            }
        }
    }
    return *this;
}

// Copy constructor
template<class T>
Ordered_Vector<T>::Ordered_Vector(const Ordered_Vector<T>& other) {
    arr = NULL;
    *this = other;
}

// Destructor
template<class T>
Ordered_Vector<T>::~Ordered_Vector() {
    if (arr) { delete[] arr; }
}

// Class-member functions

template<class T>
T& Ordered_Vector<T>::operator [] (size_t index) {
    throw exception("Unsupported operation");
}

template<class T>
T& Ordered_Vector<T>::at(int index) {
    throw exception("Unsupported operation");
}

template<class T>
T& Ordered_Vector<T>::front() {
    throw exception("Unsupported operation");
}

template<class T>
T& Ordered_Vector<T>::back() {
    throw exception("Unsupported operation");
}

template<class T>
void Ordered_Vector<T>::push_back(const T& value) {
    throw exception("Unsupported operation");
}


// Question 2.4
/** searches the value in the vector
    @param value: value to search
    @returns: index of the search value
*/
template<class T>
int Vector<T>::find(const T& value) const {

    // Creating begin and end variable to access the index
    int begin = 0;
    int end = static_cast<int>(size()) - 1;

    // Creating a while loop to iterate continuosly
    while (begin <= end) {

        // Creating a middle index variable
        int mid_index = (begin + end) / 2;

        // Checking whether if mid_index value is equal to value
        if (data[mid_index] == value) {
            return mid_index;
        }

        // If mid_index value is greater than the parameter value, change the end index
        else if (data[mid_index] > value) {
            end = mid_index - 1;
        }

        // If mid_index value is smaller than the parameter value, change the begin index
        else {
            begin = mid_index + 1;
        }
    }

    // return -1 if the value cannot be found
    return -1;
}   // Time Complexity: O(log n)
#endif;