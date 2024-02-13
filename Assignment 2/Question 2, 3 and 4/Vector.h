// Created by Dayu Wang (dwang@stchas.edu) on 2022-08-29

// Last updated by Dayu Wang (dwang@stchas.edu) on 2022-08-30


#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <string>

using std::exception;
using std::ostream;
using std::to_string;

/** A vector without iterators */
template<class T>
class Vector {
public:
    // Constructors
    Vector();  // Default constructor
    Vector(size_t);  // Constructs a vector with specified initial size.
    Vector(size_t, const T&);  // Constructs a vector with specified initial size and filling value.
    Vector(const Vector<T>&);  // Copy constructor

    // Destructor
    ~Vector();

    // Operators
    const Vector<T>& operator = (const Vector<T>&);  // Deep-copy assignment operator
    Vector<T>& operator [] (size_t);  // Subscript operator (l-value)
    const Vector<T>& operator [] (size_t) const;  // Subscript operator (r-value)

    // Class-member functions
    size_t size() const;  // Returns the size of the vector.
    bool empty() const;  // Tests whether the vector is empty or not.
    T& at(size_t);  // Returns the element at specified index (l-value).
    const T& at(size_t) const;  // Returns the element at specified index (r-value).
    T& front();  // Returns the first element in the vector (l-value).
    const T& front() const;  // Returns the last element in the vector (r-value).
    T& back();  // Returns the last element in the vector (l-value).
    const T& back() const;  // Returns the last element in the vector (r-value).
    void push_back(const T&);  // Adds a new element to the rear end of the vector.
    void pop_back();  // Deletes the last element in the vector.

    /* Question 2.2 */
    // Removes unused space from the vector to make capacity the same as num_of_items.
    void shrink_to_fit();

    /* Question 2.3 */
    // Overloads the '+' operator to concatenate two vectors of the same type.
    Vector<T> operator + (const Vector<T>&) const;

    /* Question 2.4 */
    // Searches for a target element in the ordered vector.
    int find(const T&) const;

    const size_t& capacity_return();
    
private:
    // Constant
    static const size_t DEFAULT_CAPACITY;  // Default capacity used when capacity is not specified

    // Data fields
    T* data;  // Stores the elements in the vector.
    size_t capacity;  // Stores the length of the array "data".
    size_t num_of_items;  // Stores the number of elements in the vector.

    // Class-member function
    void resize();  // Doubles the capacity of the vector without changing the current data stored in it.
};

// Implementation of class Vector

// Static variable
template<class T>
const size_t Vector<T>::DEFAULT_CAPACITY = 10;

// Constructors

// Default constructor
template<class T>
Vector<T>::Vector() : capacity(DEFAULT_CAPACITY), num_of_items(0) {
    data = new T[DEFAULT_CAPACITY];
}  // Time complexity: O(1)

// Constructs a vector with specified initial size.
template<class T>
Vector<T>::Vector(size_t initial_size) : num_of_items(initial_size) {
    capacity = initial_size < DEFAULT_CAPACITY ? DEFAULT_CAPACITY : initial_size;
    data = new T[capacity];
}  // Time complexity: O(1)

// Constructs a vector with specified initial size and filling value.
template<class T>
Vector<T>::Vector(size_t initial_size, const T& filling_value) : num_of_items(initial_size) {
    capacity = initial_size < DEFAULT_CAPACITY ? DEFAULT_CAPACITY : initial_size;
    data = new T[capacity];
    for (size_t i = 0; i < num_of_items; i++) { data[i] = filling_value; }
}  // Time complexity: O(n)

// Copy constructor
template<class T>
Vector<T>::Vector(const Vector<T>& other) {
    data = NULL;
    *this = other;
}  // Time complexity: O(n)

// Destructor

template<class T>
Vector<T>::~Vector() {
    if (data) { delete[] data; }
}  // Time complexity: O(1)

// Operators

// Deep-copy assignment operator
template<class T>
const Vector<T>& Vector<T>::operator = (const Vector<T>& rhs) {
    if (this != &rhs) {
        if (data) {
            delete[] data;
            data = NULL;
        }
        capacity = rhs.capacity;
        num_of_items = rhs.num_of_items;
        if (capacity) {
            data = new T[capacity];
            for (size_t i = 0; i < num_of_items; i++) { data[i] = rhs.data[i]; }
        }
    }
    return *this;
}  // Time complexity: O(n)

// Subscript operator (l-value)
template<class T>
Vector<T>& Vector<T>::operator [] (size_t index) { return data[index]; }  // Time complexity: O(1)

// Subscript operator (r-value)
template<class T>
const Vector<T>& Vector<T>::operator [] (size_t index) const { return data[index]; }  // Time complexity: O(1)

// Class-member functions

/** Returns the size of the vector.
    @return: size of the vector
*/
template<class T>
size_t Vector<T>::size() const { return num_of_items; }  // Time complexity: O(1)

/** Tests whether the vector is empty or not.
    @return: {true} if the vector is empty; {false} otherwise
*/
template<class T>
bool Vector<T>::empty() const { return !size(); }  // Time complexity: O(1)

/** Returns the element at specified index (l-value).
    @param index: specified index
    @return: element at specified index
    @throw exception: index >= size()
*/
template<class T>
T& Vector<T>::at(size_t index) {
    if (index >= size()) { throw std::out_of_range("Index out of bounds: " + std::to_string(index)); }
    return data[index];
}  // Time complexity: O(1)

/** Returns the element at specified index (r-value).
    @param index: specified index
    @return: element at specified index
    @throw exception: index >= size()
*/
template<class T>
const T& Vector<T>::at(size_t index) const {
    if (index >= size()) { throw std::out_of_range("Index out of bounds: " + std::to_string(index)); }
    return data[index];
}  // Time complexity: O(1)

/** Returns the first element in the vector (l-value).
    @return: first element in the vector
    @throw exception: vector is empty.
*/
template<class T>
T& Vector<T>::front() {
    if (empty()) { throw exception("Accessing empty vector"); }
    return at(0);
}  // Time complexity: O(1)

/** Returns the first element in the vector (r-value).
    @return: first element in the vector
    @throw exception: vector is empty.
*/
template<class T>
const T& Vector<T>::front() const {
    if (empty()) { throw exception("Accessing empty vector"); }
    return at(0);
}  // Time complexity: O(1)

/** Returns the last element in the vector (l-value).
    @return: first element in the vector
    @throw exception: vector is empty.
*/
template<class T>
T& Vector<T>::back() {
    if (empty()) { throw exception("Accessing empty vector"); }
    return at(size() - 1);
}  // Time complexity: O(1)

/** Returns the last element in the vector (r-value).
    @return: first element in the vector
    @throw exception: vector is empty.
*/
template<class T>
const T& Vector<T>::back() const {
    if (empty()) { throw exception("Accessing empty vector"); }
    return at(size() - 1);
}  // Time complexity: O(1)

/** Doubles the capacity of the vector without changing the current data stored in it. */
template<class T>
void Vector<T>::resize() {
    capacity *= 2;
    T* new_data = new T[capacity];
    for (size_t i = 0; i < size(); i++) { new_data[i] = data[i]; }
    delete[] data;
    data = new_data;
}  // Time complexity: O(n)

/** Adds a new element to the rear end of the vector.
    @param item: new element to add to the vector
*/
template<class T>
void Vector<T>::push_back(const T& item) {
    if (size() == capacity) { resize(); }
    data[num_of_items++] = item;
}  // Time complexity: O(1)

/** Deletes the last element in the vector.
    @throw exception: vector is empty.
*/
template<class T>
void Vector<T>::pop_back() {
    if (empty()) { throw exception("Accessing empty vector"); }
    num_of_items--;
}  // Time complexity: O(1)

// Stream insertion operator
template<class T>
ostream& operator << (ostream& out, const Vector<T>& vec) {
    out << '[';
    for (size_t i = 0; i < vec.size(); i++) {
        out << vec.at(i);
        if (i != vec.size() - 1) { out << ", "; }
    }
    return out << ']';
}  // Time complexity: O(n)


// Checking the Capacity
template<class T>
const size_t& Vector<T>::capacity_return() {
    return capacity;
}


// Question 2.2
/** Removes all the unused space in the vector to make capacity same as num_of_items */
template<class T>
void Vector<T>::shrink_to_fit() {

    // Changing the capacity to current size of the vector
    capacity = size();

    // Creating an dynamic array
    T* data_copy = new T[capacity];

    // Copying all the data from current array to new dynamic array to remove all the unused space
    for (size_t i = 0; i < size(); i++) {
        data_copy[i] = data[i];
    }

    // Deleting the data array
    delete[] data;

    // Setting data array equal to new dynamic array
    data = data_copy;

}  // Time Complexity: O(n)


// Question 2.3
/** Overloads operator '+' for "Vector<T> + Vector<T>".
    @param rhs: second operand
    @returns:  addition result
*/
template<class T>
Vector<T> Vector<T>::operator + (const Vector<T>& rhs) const {

    // Creating a result vector to store data
    Vector<T> result;

    // Copying the data from the first vector
    for (size_t i = 0; i < size(); i++) {
        result.push_back(data[i]);
    }

    // Copying the data from the second vector
    for (size_t j = 0; j < rhs.size(); j++) {
        result.push_back(rhs.data[j]);
    }

    // Returning the vector
    return result;
} // Time Complexity: O(n)




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





#endif