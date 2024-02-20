// Created by Dayu Wang (dwang@stchas.edu) on 2022-10-03

// Last updated by Dayu Wang (dwang@stchas.edu) on 2022-10-03


#ifndef CIRCULAR_ARRAY_DEQUE_H
#define CIRCULAR_ARRAY_DEQUE_H

#include <exception>
#include <stddef.h>

using std::exception;

/** A circular array based deque */
template<class T>
class Circular_Array_Deque {
public:
    // Constructors
    Circular_Array_Deque();  // Default constructor
    Circular_Array_Deque(const Circular_Array_Deque<T>&);  // Copy constructor

    // Destructor
    virtual ~Circular_Array_Deque();

    // Deep-copy assignment operator
    const Circular_Array_Deque<T>& operator = (const Circular_Array_Deque<T>&);

    // Class-member functions
    size_t size() const;  // Returns the number of elements in the deque.
    bool empty() const;  // Tests whether the deque is empty.
    T& front();  // Returns the element at the front end of the deque (l-value).
    const T& front() const;  // Returns the element at the front end of the deque (r-value).
    T& back();  // Returns the element at the rear end of the deque (l-value).
    const T& back() const;  // Returns the element at the rear end of the deque (r-value).
    void pop_front();  // Deletes an element from the front end of the deque.
    void pop_back();  // Deletes an element from the rear end of the deque.
    void push_front(const T&);  // Adds an element to the front end of the deque.
    void push_back(const T&);  // Adds an element to the rear end of the deque.

private:
    // Data fields
    T* data;  // An array to store the elements in the deque
    size_t capacity;  // Stores the maximum capacity of the deque.
    size_t num_of_items;  // Stores the number of elements in the deque.
    static const size_t DEFAULT_CAPACITY;  // Initial capacity of the deque
    int front_index, rear_index;  // Stores the indices of the front and rear end of the deque.

    // Class-member function
    void resize();  // Doubles the capacity of the deque.
};

// Implementation of class {Circular_Array_Deque}

// Initial capacity of the deque
template<class T>
const size_t Circular_Array_Deque<T>::DEFAULT_CAPACITY = 10;

// Default constructor
template<class T>
Circular_Array_Deque<T>::Circular_Array_Deque() :
    capacity(DEFAULT_CAPACITY), num_of_items(0), front_index(0), rear_index(DEFAULT_CAPACITY - 1) {
    data = new T[DEFAULT_CAPACITY];
}

// Copy constructor
template<class T>
Circular_Array_Deque<T>::Circular_Array_Deque(const Circular_Array_Deque<T>& other) {
    data = NULL;
    *this = other;
}

// Destructor
template<class T>
Circular_Array_Deque<T>::~Circular_Array_Deque() {
    if (data) { delete[] data; }
}

// Deep-copy assignment operator
template<class T>
const Circular_Array_Deque<T>& Circular_Array_Deque<T>::operator = (const Circular_Array_Deque<T>& rhs) {
    if (this != &rhs) {
        if (data) {
            delete[] data;
            data = NULL;
        }
        capacity = rhs.capacity;
        num_of_items = rhs.num_of_items;
        front_index = rhs.front_index;
        rear_index = rhs.rear_index;
        if (capacity) {
            data = new T[capacity];
            for (size_t i = 0; i < num_of_items; i++) { data[i] = rhs.data[i]; }
        }
    }
    return *this;
}

/** Returns the number of elements in the deque.
    @return: number of elements in the deque
*/
template<class T>
size_t Circular_Array_Deque<T>::size() const { return num_of_items; }  // Time complexity: O(1)

/** Tests whether the deque is empty.
    @return: {true} if the deque is empty; {false} otherwise
*/
template<class T>
bool Circular_Array_Deque<T>::empty() const { return !size(); }  // Time complexity: O(1)

/** Returns the element at the front end of the deque (l-value).
    @return: element at the front end of the deque (l-value)
    @throws exception: deque is empty.
*/
template<class T>
T& Circular_Array_Deque<T>::front() {
    if (empty()) { throw exception("Accessing empty deque"); }
    return data[front_index];
}  // Time complexity: O(1)

/** Returns the element at the front end of the deque (r-value).
    @return: element at the front end of the deque (r-value)
    @throws exception: deque is empty.
*/
template<class T>
const T& Circular_Array_Deque<T>::front() const {
    if (empty()) { throw exception("Accessing empty deque"); }
    return data[front_index];
}  // Time complexity: O(1)

/** Returns the element at the rear end of the deque (l-value).
    @return: element at the rear end of the deque (l-value)
    @throws exception: deque is empty.
*/
template<class T>
T& Circular_Array_Deque<T>::back() {
    if (empty()) { throw exception("Accessing empty deque"); }
    return data[rear_index];
}  // Time complexity: O(1)

/** Returns the element at the rear end of the deque (r-value).
    @return: element at the rear end of the deque (r-value)
    @throws exception: deque is empty.
*/
template<class T>
const T& Circular_Array_Deque<T>::back() const {
    if (empty()) { throw exception("Accessing empty deque"); }
    return data[rear_index];
}  // Time complexity: O(1)

/** Deletes an element from the front end of the deque.
    @throws exception: deque is empty.
*/
template<class T>
void Circular_Array_Deque<T>::pop_front() {
    if (empty()) { throw exception("Accessing empty deque"); }
    front_index = (front_index + 1) % capacity;
    num_of_items--;
}  // Time complexity: O(1)

/** Deletes an element from the rear end of the deque.
    @throws exception: deque is empty.
*/
template<class T>
void Circular_Array_Deque<T>::pop_back() {
    if (empty()) { throw exception("Accessing empty deque"); }
    rear_index = (rear_index - 1 + capacity) % capacity;
    num_of_items--;
}  // Time complexity: O(1)

/** Adds an element to the front end of the deque.
    @param item: element to add to the deque
*/
template<class T>
void Circular_Array_Deque<T>::push_front(const T& item) {
    if (num_of_items == capacity) { resize(); }
    front_index = (front_index - 1 + capacity) % capacity;
    data[front_index] = item;
    num_of_items++;
}  // Time complexity: O(1)

/** Adds an element to the rear end of the deque.
    @param item: element to add to the deque
*/
template<class T>
void Circular_Array_Deque<T>::push_back(const T& item) {
    if (num_of_items == capacity) { resize(); }
    rear_index = (rear_index + 1) % capacity;
    data[rear_index] = item;
    num_of_items++;
}  // Time complexity: O(1)

/** Doubles the capacity of the deque */
template<class T>
void Circular_Array_Deque<T>::resize() {
    capacity *= 2;
    T* new_data = new T[capacity];
    for (int i = 0, j = front_index; i < size(); i++, j = (j + 1) % (capacity / 2)) { new_data[i] = data[j]; }
    front_index = 0;
    rear_index = size() - 1;
    delete[] data;
    data = new_data;
}  // Time complexity: O(n)

#endif