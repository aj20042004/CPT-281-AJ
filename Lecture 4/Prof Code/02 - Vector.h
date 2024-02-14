// Created by Dayu Wang (dwang@stchas.edu) on 2022-08-29

// Last updated by Dayu Wang (dwang@stchas.edu) on 2023-02-13


#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <string>

using std::exception;
using std::ostream;
using std::to_string;

/** A vector with iterators */
template<class T>
class Vector {
public:
    /** A vector iterator */
    class Iterator;

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
    Iterator begin() const;  // Generates an iterator pointing to the first element of the vector.
    Iterator end() const;  // Generates an iterator just after the last element of the vector.
    Iterator& insert(Iterator&, const T&);  // Inserts an element at iterator position.
    const Iterator& erase(const Iterator&);  // Deletes the element at iterator position.
    virtual Iterator find(const T&) const;  // Finds a target value in the vector.

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


/* Implementation of class "Vector" */

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
    if (index >= size()) { throw exception("Index out of range"); }
    return data[index];
}  // Time complexity: O(1)

/** Returns the element at specified index (r-value).
    @param index: specified index
    @return: element at specified index
    @throw exception: index >= size()
*/
template<class T>
const T& Vector<T>::at(size_t index) const {
    if (index >= size()) { throw exception("Index out of range"); }
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
    for (typename Vector<T>::Iterator it = vec.begin(); it != vec.end(); it++) {
        out << *it;
        if (it != vec.end() - 1) { out << ", "; }
    }
    return out << ']';
}  // Time complexity: O(n)

// A vector iterator
template<class T>
class Vector<T>::Iterator {
public:
    // Operators
    Iterator& operator ++ ();  // Moves the iterator forward for one position (prefix).
    Iterator operator ++ (int);  // Moves the iterator forward for one position (postfix).
    Iterator& operator -- ();  // Moves the iterator backward for one position (prefix).
    Iterator operator -- (int);  // Moves the iterator backward for one position (postfix).
    Iterator operator + (int) const;  // Gets an iterator that is some positions after current position.
    Iterator& operator += (int);  // Moves the iterator forward for some positions.
    Iterator operator - (int) const;  // Gets an iterator that is some positions before current position.
    Iterator& operator -= (int);  // Moves the iterator backward for some positions.
    int operator - (const Iterator&) const;  // Finds the position difference of two iterators.
    T& operator * ();  // Returns the element at iterator position (l-value).
    const T& operator * () const;  // Returns the element at iterator position (r-value).
    T* operator -> ();  // Returns a pointer to the element at iterator position.
    bool operator == (const Iterator&) const;  // Tests whether two iterators point to the same element.
    bool operator != (const Iterator&) const;  // Tests whether two iterators point to different element.

private:
    // Data field
    const Vector<T>* parent;  // A pointer to the parent vector
    size_t index;  // Index of the current element

    // Constructor
    Iterator(const Vector<T>*, size_t);

    friend class Vector<T>;
};

// Constructor of class "Iterator"
template<class T>
Vector<T>::Iterator::Iterator(const Vector<T>* parent, size_t index) : parent(parent), index(index) {}  // Time complexity: O(1)

// Moves the iterator forward for one position (prefix).
template<class T>
typename Vector<T>::Iterator& Vector<T>::Iterator::operator ++ () {
    if (index == parent->size()) { throw exception("Iterator out of range"); }
    index++;
    return *this;
}  // Time complexity: O(1)

// Moves the iterator forward for one position (postfix).
template<class T>
typename Vector<T>::Iterator Vector<T>::Iterator::operator ++ (int) {
    typename Vector<T>::Iterator result = *this;
    ++(*this);
    return result;
}  // Time complexity: O(1)

// Moves the iterator backward for one position (prefix).
template<class T>
typename Vector<T>::Iterator& Vector<T>::Iterator::operator -- () {
    if (!index) { throw exception("Iterator out of range"); }
    index--;
    return *this;
}  // Time complexity: O(1)

// Moves the iterator backward for one position (postfix).
template<class T>
typename Vector<T>::Iterator Vector<T>::Iterator::operator -- (int) {
    typename Vector<T>::Iterator result = *this;
    --(*this);
    return result;
}  // Time complexity: O(1)

// Gets an iterator that is some positions after current position.
template<class T>
typename Vector<T>::Iterator Vector<T>::Iterator::operator + (int num) const {
    if (num < 0) { return *this - -num; }
    if (index + num > parent->size()) { throw exception("Iterator out of range"); }
    return Iterator(parent, index + num);
}  // Time complexity: O(1)

// Moves the iterator forward for some positions.
template<class T>
typename Vector<T>::Iterator& Vector<T>::Iterator::operator += (int num) {
    return *this = *this + num;
}  // Time complexity: O(1)

// Gets an iterator that is some positions before current position.
template<class T>
typename Vector<T>::Iterator Vector<T>::Iterator::operator - (int num) const {
    if (num < 0) { return *this + -num; }
    if ((int)index - num < 0) { throw exception("Iterator out of range"); }
    return Iterator(parent, index - num);
}  // Time complexity: O(1)

// Moves the iterator backward for some positions.
template<class T>
typename Vector<T>::Iterator& Vector<T>::Iterator::operator -= (int num) {
    return *this = *this - num;
}  // Time complexity: O(1)

// Finds the position difference of two iterators.
template<class T>
int Vector<T>::Iterator::operator - (const Vector<T>::Iterator& other) const {
    return (int)index - (int)other.index;
}  // Time complexity: O(1)

// Returns the element at iterator position (l-value).
template<class T>
T& Vector<T>::Iterator::operator * () {
    if (index == parent->size()) { throw exception("Index out of range"); }
    return parent->data[index];
}  // Time complexity: O(1)

// Returns the element at iterator position (r-value).
template<class T>
const T& Vector<T>::Iterator::operator * () const {
    if (index == parent->size()) { throw exception("Index out of range"); }
    return parent->data[index];
}  // Time complexity: O(1)

// Returns a pointer to the element at iterator position.
template<class T>
T* Vector<T>::Iterator::operator -> () {
    if (index == size()) { throw exception("Index out of range"); }
    return &(parent->data[index]);
}  // Time complexity: O(1)

// Tests whether two iterators point to the same element.
template<class T>
bool Vector<T>::Iterator::operator == (const Vector<T>::Iterator& other) const {
    return index == other.index;
}  // Time complexity: O(1)

// Tests whether two iterators point to different elements.
template<class T>
bool Vector<T>::Iterator::operator != (const Vector<T>::Iterator& other) const {
    return index != other.index;
}  // Time complexity: O(1)

// Generates an iterator pointing to the first element of the vector.
template<class T>
typename Vector<T>::Iterator Vector<T>::begin() const {
    return Iterator(this, 0);
}  // Time complexity: O(1)

// Generates an iterator just after the last element of the vector.
template<class T>
typename Vector<T>::Iterator Vector<T>::end() const {
    return Iterator(this, size());
}  // Time complexity: O(1)

// Inserts an element at iterator position.
template<class T>
typename Vector<T>::Iterator& Vector<T>::insert(Iterator& pos, const T& value) {
    if (size() == capacity) { resize(); }
    for (size_t i = size(); i > pos.index; i--) { data[i] = data[i - 1]; }
    data[pos.index] = value;
    num_of_items++;
    return ++pos;
}  // Time complexity: O(n)

// Deletes the element at iterator position.
template<class T>
typename const Vector<T>::Iterator& Vector<T>::erase(const Iterator& pos) {
    for (size_t i = pos.index; i < size() - 1; i++) { data[i] = data[i + 1]; }
    num_of_items--;
    return pos;
}  // Time complexity: O(n)

// Finds a target value in the vector.
template<class T>
typename Vector<T>::Iterator Vector<T>::find(const T& value) const {
    for (size_t i = 0; i < size(); i++) {
        if (at(i) == value) { return Iterator(this, i); }
    }
    return end();
}  // Time complexity: O(n)

#endif