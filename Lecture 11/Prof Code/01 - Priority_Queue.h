// Created by Dayu Wang (dwang@stchas.edu) on 2022-11-14

// Last updated by Dayu Wang (dwang@stchas.edu) on 2022-11-14


#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <algorithm>
#include <exception>

using std::exception;
using std::swap;

template<class T>
class Priority_Queue {
public:
    // Constructors
    Priority_Queue();  // Default constructor
    Priority_Queue(bool);  // Constructs a priority queue using user-specified min/max heap.
    Priority_Queue(const Priority_Queue<T>&);  // Copy constructor

    // Destructor
    ~Priority_Queue();

    // Deep-copy assignment operator
    const Priority_Queue<T>& operator = (const Priority_Queue<T>&);

    // Class-member functions
    size_t size() const;  // Returns the size of the priority queue.
    bool empty() const;  // Tests whether the priority queue is empty.
    T& top();  // Returns the element at the top of the heap (lvalue).
    const T& top() const;  // Returns the element at the top of the heap (rvalue).
    void pop();  // Deletes the element at the top of the heap.
    void push(const T&);  // Inserts an element to the priority queue.

private:
    // Data fields
    T* data;  // Stores the elements in the priority queue.
    size_t capacity;  // Stores the maximum capacity of the priority queue.
    size_t num_of_items;  // Stores the number of elements in the priority queue.
    static const size_t DEFAULT_CAPACITY;  // Initial capacity when an empty priority queue is created
    bool min_heap;  // {true} if the priority queue is a min heap; {false} if it is a max heap.

    // Class-member functions
    void resize();  // Doubles the capacity without changing the current elements.
    bool compare(int, int);  // Compares the elements at given indices.
};

// Default capacity
template<class T>
const size_t Priority_Queue<T>::DEFAULT_CAPACITY = 10;

/** Doubles the capacity without changing the current elements. */
template<class T>
void Priority_Queue<T>::resize() {
    capacity *= 2;
    T* new_data = new T[capacity];
    for (size_t i = 0; i < size(); i++) { new_data[i] = data[i]; }
    delete[] data;
    data = new_data;
}  // Time complexity: O(n)

/** Compares the elements at given indices.
    @param i: index of the first element to compare
    @param j: index of the second element to compare
    @return: {true} if data[i] is an inorder precedessor of data[j]; {false} if data[i] is an inorder successor if data[j]
*/
template<class T>
bool Priority_Queue<T>::compare(int i, int j) {
    return min_heap ? data[i] < data[j] : !(data[i] < data[j]);
}  // Time complexity: O(1)

// Default constructor
template<class T>
Priority_Queue<T>::Priority_Queue() : capacity(DEFAULT_CAPACITY), num_of_items(0), min_heap(false) { data = new T[capacity]; }

// Constructs a priority queue using user-specified min/max heap.
template<class T>
Priority_Queue<T>::Priority_Queue(bool min_heap) : capacity(DEFAULT_CAPACITY), num_of_items(0), min_heap(min_heap) {
    data = new T[capacity];
}

// Copy constructor
template<class T>
Priority_Queue<T>::Priority_Queue(const Priority_Queue<T>& other) {
    data = NULL;
    *this = other;
}

// Destructor
template<class T>
Priority_Queue<T>::~Priority_Queue() {
    if (data) { delete[] data; }
}

// Deep-copy assignment operator
template<class T>
const Priority_Queue<T>& Priority_Queue<T>::operator = (const Priority_Queue<T>& rhs) {
    if (this != &rhs) {
        if (data) {
            delete[] data;
            data = NULL;
        }
        capacity = rhs.capacity;
        num_of_items = rhs.num_of_items;
        min_heap = rhs.min_heap;
        if (capacity) {
            data = new T[capacity];
            for (size_t i = 0; i < size(); i++) { data[i] = rhs.data[i]; }
        }
    }
    return *this;
}

/** Returns the size of the priority queue.
    @return: size of the priority queue
*/
template<class T>
size_t Priority_Queue<T>::size() const { return num_of_items; }  // Time complexity: O(1)

/** Tests whether the priority queue is empty.
    @return: {true} if the priority queue is empty; {false} otherwise
*/
template<class T>
bool Priority_Queue<T>::empty() const { return !size(); }  // Time complexity: O(1)

/** Returns the element at the top of the heap (lvalue).
    @return: element at the top of the heap (lvalue)
    @throws exception: priority queue is empty.
*/
template<class T>
T& Priority_Queue<T>::top() {
    if (empty()) { throw exception("Accessing empty queue"); }
    return data[0];
}  // Time complexity: O(1)

/** Returns the element at the top of the heap (rvalue).
    @return: element at the top of the heap (rvalue)
    @throws exception: priority queue is empty.
*/
template<class T>
const T& Priority_Queue<T>::top() const {
    if (empty()) { throw exception("Accessing empty queue"); }
    return data[0];
}  // Time complexity: O(1)

/** Deletes the element at the top of the heap.
    @throws exception: priority queue is empty.
*/
template<class T>
void Priority_Queue<T>::pop() {
    if (empty()) { throw exception("Accessing empty queue"); }
    data[0] = data[size() - 1];  // Overwrite the root with the last element in the array.
    num_of_items--;  // Delete the last element from the array.
    int root = 0, left = 2 * root + 1, right = 2 * root + 2;
    while (true) {
        int min = root;
        if (left < size() && compare(left, min)) { min = left; }
        if (right < size() && compare(right, min)) { min = right; }
        if (min == root) { break; }
        swap(data[root], data[min]);
        root = min;
        left = root * 2 + 1;
        right = root * 2 + 2;
    }
}  // Time complexity: O(log(n))

/** Inserts an element to the priority queue.
    @param item: element to insert to the priority queue
*/
template<class T>
void Priority_Queue<T>::push(const T& item) {
    if (num_of_items == capacity) { resize(); }
    data[num_of_items++] = item;
    int child = (int)size() - 1, parent = (child - 1) / 2;
    while (compare(child, parent)) {
        swap(data[child], data[parent]);
        if (!parent) { break; }
        child = parent;
        parent = (child - 1) / 2;
    }
}  // Time complexity: O(log(n))

#endif