// Created by Dayu Wang (dwang@stchas.edu) on 2022-09-21

// Last updated by Dayu Wang (dwang@stchas.edu) on 2023-06-28


#ifndef VECTOR_STACK_H
#define VECTOR_STACK_H

#include <exception>
#include <vector>

using std::exception;
using std::vector;

/** A vector-based stack */
template<class T>
class Vector_Stack {
public:
    // Constructor
    Vector_Stack();  // Default constructor

    // Class-member functions
    size_t size() const;  // Returns the size of the stack.
    bool empty() const;  // Tests whether the stack is empty.
    T& top();  // Returns the element at the top of the stack (l-value).
    const T& top() const;  // Returns the element at the top of the stack (r-value).
    void push(const T&);  // Adds an element onto the top of the stack.
    void pop();  // Removes the element at the top of the stack.
    void clear();  // Removes all the elements from the stack.

private:
    // Data field
    vector<T> data;  // Stores the elements in the stack.
};

// Default constructor
template<class T>
Vector_Stack<T>::Vector_Stack() {}

/** Returns the size of the stack.
    @return: size of the stack
*/
template<class T>
size_t Vector_Stack<T>::size() const { return data.size(); }  // Time complexity: O(1)

/** Tests whether the stack is empty.
    @return: {true} if the stack is empty; {false} otherwise
*/
template<class T>
bool Vector_Stack<T>::empty() const { return !size(); }  // Time complexity: O(1)

/** Returns the element at the top of the stack (l-value).
    @return: element at the top of the stack (l-value)
    @throws exception: stack is empty.
*/
template<class T>
T& Vector_Stack<T>::top() {
    if (empty()) { throw exception("Accessing empty stack"); }
    return data.back();
}  // Time complexity: O(1)

/** Returns the element at the top of the stack (r-value).
    @return: element at the top of the stack (r-value)
    @throws exception: stack is empty.
*/
template<class T>
const T& Vector_Stack<T>::top() const {
    if (empty()) { throw exception("Accessing empty stack"); }
    return data.back();
}  // Time complexity: O(1)

/** Adds an element onto the top of the stack.
    @param value: element to add to the stack
*/
template<class T>
void Vector_Stack<T>::push(const T& value) { data.push_back(value); }  // Time complexity: O(1)

/** Removes the element at the top of the stack.
    @throws exception: stack is empty.
*/
template<class T>
void Vector_Stack<T>::pop() {
    if (empty()) { throw exception("Accessing empty stack"); }
    data.pop_back();
}

/** Removes all the elements from the stack. */
template<class T>
void Vector_Stack<T>::clear() { data.clear(); }  // Time complexity: O(1)

#endif