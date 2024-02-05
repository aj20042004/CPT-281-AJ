// Created by Dayu Wang (dwang@stchas.edu) on 2023-06-20

// Last updated by Dayu Wang (dwang@stchas.edu) on 2023-06-20


#ifndef LIST_H
#define LIST_H

#include <iostream>

using std::exception;
using std::ostream;

/** A doubly-linked list without iterators */
template<class T>
class List {
public:
    // Constructors
    List();  // Default constructor
    List(const List<T>&);  // Copy constructor

    // Destructor
    virtual ~List();

    // Operators
    const List<T>& operator = (const List<T>&);  // Deep-copy assignment operator
    template<class E>
    friend ostream& operator << (ostream&, const List<E>&);  // Stream insertion operator

    // Class-member functions
    size_t size() const;  // Returns the number of elements in the list.
    bool empty() const;  // Tests whether the list is empty.
    T& front();  // Returns a reference (lvalue) to the first element in the list.
    const T& front() const;  // Returns a const reference (rvalue) to the first element in the list.
    T& back();  // Returns a reference (lvalue) to the last element in the list.
    const T& back() const;  // Returns a const reference (rvalue) to the last element in the list.
    void push_front(const T&);  // Inserts an element to the front end of the list.
    void push_back(const T&);  // Inserts an element to the rear end of the list.
    void pop_front();  // Deletes an element from the front end of the list.
    void pop_back();  // Deletes an element from the rear end of the list.
    void clear();  // Deletes all the nodes.

private:
    /** A doubly-linked list node */
    struct D_Node {
        // Data fields
        T data;  // Stores some data in the node.
        D_Node* next;  // Stores a pointer to the next node in the list.
        D_Node* prev;  // Stores a pointer to the previous node in the list.

        // Constructor
        D_Node(const T&, D_Node* = NULL, D_Node* = NULL);
    };

    // Data fields
    D_Node* head;  // Stores a pointer to the first node in the list.
    D_Node* tail;  // Stores a pointer to the last node in the list.
    size_t num_of_items;  // Stores the number of nodes in the list.
};

// Stream insertion operator
template<class T>
ostream& operator << (ostream& out, const List<T>& li) {
    typename List<T>::D_Node* current = li.head;
    while (current) {
        out << current->data;
        if (current->next) { out << " -> "; }
        current = current->next;
    }
    return out;
}

/** Deletes all the nodes. */
template<class T>
void List<T>::clear() {
    while (!empty()) { pop_front(); }
}  // Time complexity: O(n);

/** Deletes an element from the rear end of the list.
    @throws exception: list is empty.
*/
template<class T>
void List<T>::pop_back() {
    if (empty()) { throw exception("Accessing empty list"); }
    D_Node* to_be_deleted = tail;
    if (num_of_items-- == 1) { head = tail = NULL; }
    else {
        tail = tail->prev;
        tail->next = NULL;
    }
    delete to_be_deleted;
}  // Time complexity: O(1)

/** Deletes an element from the front end of the list.
    @throws exception: list is empty.
*/
template<class T>
void List<T>::pop_front() {
    if (empty()) { throw exception("Accessing empty list"); }
    D_Node* to_be_deleted = head;
    if (num_of_items-- == 1) { head = tail = NULL; }
    else {
        head = head->next;
        head->prev = NULL;
    }
    delete to_be_deleted;
}  // Time complexity: O(1)

/** Inserts an element to the rear end of the list.
    @param value: the element to insert to the list
*/
template<class T>
void List<T>::push_back(const T& value) {
    if (num_of_items++ == 0) { head = tail = new D_Node(value); }
    else {
        tail->next = new D_Node(value);
        tail->next->prev = tail;
        tail = tail->next;
    }
}  // Time complexity: O(1)

/** Inserts an element to the front end of the list.
    @param value: the element to insert to the list
*/
template<class T>
void List<T>::push_front(const T& value) {
    if (num_of_items++ == 0) { head = tail = new D_Node(value); }
    else {
        head->prev = new D_Node(value);
        head->prev->next = head;
        head = head->prev;
    }
}  // Time complexity: O(1)

/** Returns a const reference (rvalue) to the last element in the list.
    @return: a const reference (rvalue) to the last element in the list
*/
template<class T>
const T& List<T>::back() const {
    if (empty()) { throw exception("Accessing empty list"); }
    return tail->data;
}  // Time complexity: O(1)

/** Returns a reference (lvalue) to the last element in the list.
    @return: a reference (lvalue) to the last element in the list
*/
template<class T>
T& List<T>::back() {
    if (empty()) { throw exception("Accessing empty list"); }
    return tail->data;
}  // Time complexity: O(1)

/** Returns a const reference (rvalue) to the first element in the list.
    @return: a const reference (rvalue) to the first element in the list
*/
template<class T>
const T& List<T>::front() const {
    if (empty()) { throw exception("Accessing empty list"); }
    return head->data;
}  // Time complexity: O(1)

/** Returns a reference (lvalue) to the first element in the list.
    @return: a reference (lvalue) to the first element in the list
    @throws exception: list is empty.
*/
template<class T>
T& List<T>::front() {
    if (empty()) { throw exception("Accessing empty list."); }
    return head->data;
}  // Time complexity: O(1)

/** Tests whether the list is empty.
    @return: {true} if the list is empty; {false} otherwise
*/
template<class T>
bool List<T>::empty() const { return !size(); }  // Time complexity: O(1)

/** Returns the number of elements in the list.
    @return: number of elements in the list
*/
template<class T>
size_t List<T>::size() const { return num_of_items; }  // Time complexity: O(1)

// Deep-copy assignment operator
template<class T>
const List<T>& List<T>::operator = (const List<T>& rhs) {
    // Step 1: avoid self-assignment.
    if (this != &rhs) {
        // Step 2: delete dynamic memory.
        clear();
        // Step 3: copy static data.
        num_of_items = rhs.num_of_items;
        // Step 4: copy dynamic data.
        if (num_of_items) {
            head = tail = new D_Node(rhs.head->data);
            D_Node* q = rhs.head->next;
            while (q) {
                tail->next = new D_Node(q->data);
                tail->next->prev = tail;
                tail = tail->next;
                q = q->next;
            }
        }
    }
    // Step 5: return.
    return *this;
}

// Destructor
template<class T>
List<T>::~List() { clear(); }

// Copy constructor
template<class T>
List<T>::List(const List<T>& other) {
    head = tail = NULL;
    *this = other;
}

// Default constructor
template<class T>
List<T>::List() : head(NULL), tail(NULL), num_of_items(0) {}

// Constructor of the "D_Node" struct
template<class T>
List<T>::D_Node::D_Node(const T& data, D_Node* next, D_Node* prev) :
    data(data), next(next), prev(prev) {}

#endif