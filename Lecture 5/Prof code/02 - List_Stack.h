// Created by Dayu Wang (dwang@stchas.edu) on 2020-09-27

// Last updated by Dayu Wang (dwang@stchas.edu) on 2023-06-28


#ifndef LIST_STACK_H
#define LIST_STACK_H

#include <exception>
#include <stddef.h>

using std::exception;

/** A linked-list based stack */
template<class T>
class List_Stack {
public:
    // Constructors
    List_Stack();  // Default constructor
    List_Stack(const List_Stack<T>&);  // Copy constructor

    // Destructor
    virtual ~List_Stack();

    // Operator
    const List_Stack<T>& operator = (const List_Stack<T>&);  // Deep-copy assignment operator

    // Class-member functions
    size_t size() const;  // Returns the size of the stack.
    bool empty() const;  // Tests whether the stack is empty.
    T& top();  // Returns the element at the top of the stack (l-value).
    const T& top() const;  // Returns the element at the top of the stack (r-value).
    void push(const T&);  // Adds an element onto the top of the stack.
    void pop();  // Removes the element at the top of the stack.
    void clear();  // Removes all elements from the stack.

protected:
    /** A singly-linked list node */
    struct Node;

    // Data fields
    Node* top_node;  // Stores a pointer to the top node of the stack.
    size_t num_of_items;  // Stores the number of elements in the stack.
};

/** A singly-linked list node */
template<class T>
struct List_Stack<T>::Node {
    // Data fields
    T data;  // Stores some data in the node.
    Node* next;  // Stores a pointer to the next node in the stack.

    // Constructor
    Node(const T&);
};

// Constructor of struct "Node"
template<class T>
List_Stack<T>::Node::Node(const T& data) : data(data), next(NULL) {}

/** Removes the element at the top of the stack.
    @throws exception: stack is empty.
*/
template<class T>
void List_Stack<T>::pop() {
    if (empty()) { throw exception("Accessing empty stack"); }
    Node* to_be_deleted = top_node;
    top_node = top_node->next;
    num_of_items--;
    delete to_be_deleted;
}  // Time complexity: O(1)

/** Adds an element onto the top of the stack.
    @param item: element to add to the stack
*/
template<class T>
void List_Stack<T>::push(const T& item) {
    Node* new_top = new Node(item);
    new_top->next = top_node;
    top_node = new_top;
    num_of_items++;
}  // Time complexity: O(1)

/** Returns the element at the top of the stack (r-value).
    @return: element at the top of the stack (r-value)
    @throws exception: stack is empty.
*/
template<class T>
const T& List_Stack<T>::top() const {
    if (empty()) { throw exception("Accessing empty stack"); }
    return top_node->data;
}  // Time complexity: O(1)

/** Returns the element at the top of the stack (l-value).
    @return: element at the top of the stack (l-value)
    @throws exception: stack is empty.
*/
template<class T>
T& List_Stack<T>::top() {
    if (empty()) { throw exception("Accessing empty stack"); }
    return top_node->data;
}  // Time complexity: O(1)

/** Tests whether the stack is empty.
    @return: {true} if the stack is empty; {false} otherwise
*/
template<class T>
bool List_Stack<T>::empty() const { return !size(); }  // Time complexity: O(1)

/** Returns the size of the stack.
    @return: number of elements in the stack
*/
template<class T>
size_t List_Stack<T>::size() const { return num_of_items; }  // Time complexity: O(1)

// Deep-copy assignment operator
template<class T>
const List_Stack<T>& List_Stack<T>::operator = (const List_Stack<T>& rhs) {
    if (this != &rhs) {
        clear();
        num_of_items = rhs.num_of_items;
        if (num_of_items) {
            top_node = new Node(rhs.top_node->data);
            Node* p = top_node;
            Node* q = rhs.top_node->next;
            while (q) {
                p->next = new Node(q->data);
                p = p->next;
                q = q->next;
            }
        }
    }
    return *this;
}

// Destructor
template<class T>
List_Stack<T>::~List_Stack() { clear(); }

/** Removes all elements from the stack. */
template<class T>
void List_Stack<T>::clear() {
    while (top_node) {
        Node* p = top_node;
        top_node = top_node->next;
        delete p;
    }
    num_of_items = 0;
}

// Copy constructor
template<class T>
List_Stack<T>::List_Stack(const List_Stack<T>& other) {
    top_node = NULL;
    *this = other;
}

// Default constructor
template<class T>
List_Stack<T>::List_Stack() : top_node(NULL), num_of_items(0) {}

#endif