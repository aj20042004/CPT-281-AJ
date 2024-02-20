// Created by Dayu Wang (dwang@stchas.edu) on 2022-10-03

// Last updated by Dayu Wang (dwang@stchas.edu) on 2022-10-03


#ifndef CIRCULAR_ARRAY_QUEUE_H
#define CIRCULAR_ARRAY_QUEUE_H

#include <exception>
#include <stddef.h>

using std::exception;

/** A circular array based sequential queue */
template<class T>
class Circular_Array_Queue {
public:
    // Constructors
    Circular_Array_Queue();  // Default constructor
    Circular_Array_Queue(const Circular_Array_Queue<T>&);  // Copy constructor

    // Destructor
    virtual ~Circular_Array_Queue();

    // Deep-copy assignment operator
    const Circular_Array_Queue<T>& operator = (const Circular_Array_Queue<T>&);

    // Class-member functions
    size_t size() const;  // Returns the number of elements in the queue.
    bool empty() const;  // Tests whether the queue is empty.
    T& front();  // Returns the element at the front end of the queue (l-value).
    const T& front() const;  // Returns the element at the front end of the queue (r-value).
    void pop();  // Deletes an element from the front end of the queue.
    void push(const T&);  // Adds an element to the rear end of the queue. 

private:
    // Data fields
    T* data;  // An array to store the elements in the queue
    size_t capacity;  // Stores the maximum capacity of the queue.
    size_t num_of_items;  // Stores the number of elements in the queue.
    static const size_t DEFAULT_CAPACITY;  // Initial capacity of the queue
    int front_index, rear_index;  // Stores the indices of the front and rear end of the queue.

    // Class-member function
    void resize();  // Doubles the capacity of the queue.
};

// Implementation of class {Circular_Array_Queue}

// Initial capacity of the queue
template<class T>
const size_t Circular_Array_Queue<T>::DEFAULT_CAPACITY = 10;

// Default constructor
template<class T>
Circular_Array_Queue<T>::Circular_Array_Queue() :
    capacity(DEFAULT_CAPACITY), num_of_items(0), front_index(0), rear_index(DEFAULT_CAPACITY - 1) {
    data = new T[DEFAULT_CAPACITY];
}

// Copy constructor
template<class T>
Circular_Array_Queue<T>::Circular_Array_Queue(const Circular_Array_Queue<T>& other) {
    data = NULL;
    *this = other;
}

// Destructor
template<class T>
Circular_Array_Queue<T>::~Circular_Array_Queue() {
    if (data) { delete[] data; }
}

// Deep-copy assignment operator
template<class T>
const Circular_Array_Queue<T>& Circular_Array_Queue<T>::operator = (const Circular_Array_Queue<T>& rhs) {
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

/** Returns the number of elements in the queue.
    @return: number of elements in the queue
*/
template<class T>
size_t Circular_Array_Queue<T>::size() const { return num_of_items; }  // Time complexity: O(1)

/** Tests whether the queue is empty.
    @return: {true} if the queue is empty; {false} otherwise
*/
template<class T>
bool Circular_Array_Queue<T>::empty() const { return !size(); }  // Time complexity: O(1)

/** Returns the element at the front end of the queue (l-value).
    @return: element at the front end of the queue (l-value)
    @throws exception: queue is empty.
*/
template<class T>
T& Circular_Array_Queue<T>::front() {
    if (empty()) { throw exception("Accessing empty queue"); }
    return data[front_index];
}  // Time complexity: O(1)

/** Returns the element at the front end of the queue (r-value).
    @return: element at the front end of the queue (r-value)
    @throws exception: queue is empty.
*/
template<class T>
const T& Circular_Array_Queue<T>::front() const {
    if (empty()) { throw exception("Accessing empty queue"); }
    return data[front_index];
}  // Time complexity: O(1)

/** Deletes an element from the front end of the queue.
    @throws exception: queue is empty.
*/
template<class T>
void Circular_Array_Queue<T>::pop() {
    if (empty()) { throw exception("Accessing empty queue"); }
    front_index = (front_index + 1) % capacity;
    num_of_items--;
}  // Time complexity: O(1)

/** Adds an element to the rear end of the queue.
    @param item: element to add to the queue
*/
template<class T>
void Circular_Array_Queue<T>::push(const T& item) {
    if (num_of_items == capacity) { resize(); }
    rear_index = (rear_index + 1) % capacity;
    data[rear_index] = item;
    num_of_items++;
}  // Time complexity: O(1)

/** Doubles the capacity of the queue */
template<class T>
void Circular_Array_Queue<T>::resize() {
    capacity *= 2;
    T* new_data = new T[capacity];
    for (int i = 0, j = front_index; i < size(); i++, j = (j + 1) % (capacity / 2)) { new_data[i] = data[j]; }
    front_index = 0;
    rear_index = size() - 1;
    delete[] data;
    data = new_data;
}  // Time complexity: O(n)

#endif