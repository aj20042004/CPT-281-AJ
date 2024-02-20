// Created by Dayu Wang (dwang@stchas.edu) on 2022-10-03

// Last updated by Dayu Wang (dwang@stchas.edu) on 2022-10-03


#ifndef LIST_DEQUE_H
#define LIST_DEQUE_H

#include <exception>
#include <stddef.h>

using std::exception;

/** A linked list based deque */
template<class T>
class List_Deque {
public:
    // Constructors
    List_Deque();  // Default constructor
    List_Deque(const List_Deque<T>&);  // Copy constructor

    // Destructor
    virtual ~List_Deque();

    // Deep-copy assignment operator
    const List_Deque<T>& operator = (const List_Deque<T>&);

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
    /** A doubly-linked list node */
    struct D_Node;

    // Data fields
    D_Node *front_node, *rear_node;  // Stores pointers to the front and rear node in the deque.
    size_t num_of_items;  // Stores the number of elements in the deque.

    // Class-member function
    void clear();  // Deletes all the nodes in the deque.
};

// Implementation of class {List_Deque}

/** A doubly-linked list node */
template<class T>
struct List_Deque<T>::D_Node {
    // Data fields
    T data;  // Stores some data in the node.
    D_Node *next, *prev;  // Stores pointers to the next and previous node in the list.

    // Constructor
    D_Node(const T&);
};

// Constructor of struct {D_Node}
template<class T>
List_Deque<T>::D_Node::D_Node(const T& data) : data(data), next(NULL), prev(NULL) {}

// Default constructor of class {List_Deque}
template<class T>
List_Deque<T>::List_Deque() : front_node(NULL), rear_node(NULL), num_of_items(0) {}

// Copy constructor of class {List_Deque}
template<class T>
List_Deque<T>::List_Deque(const List_Deque<T>& other) {
    front_node = rear_node = NULL;
    *this = other;
}

// Destructor
template<class T>
List_Deque<T>::~List_Deque() { clear(); }

// Deep-copy assignment operator
template<class T>
const List_Deque<T>& List_Deque<T>::operator = (const List_Deque<T>& rhs) {
    if (this != &rhs) {
        clear();
        num_of_items = rhs.num_of_items;
        if (num_of_items) {
            front_node = rear_node = new D_Node(rhs.front_node->data);
            D_Node q = rhs.front_node->next;
            while (q) {
                rear_node->next = new D_Node(q->data);
                rear_node->next->prev = rear_node;
                rear_node = rear_node->next;
                q = q->next;
            }
        }
    }
}

/** Returns the number of elements in the deque.
    @return: number of elements in the deque
*/
template<class T>
size_t List_Deque<T>::size() const { return num_of_items; }  // Time complexity: O(1)

/** Tests whether the deque is empty
    @return: {true} if the deque is empty; {false} otherwise
*/
template<class T>
bool List_Deque<T>::empty() const { return !size(); }  // Time complexity: O(1)

/** Returns the element at the front end of the deque (l-value).
    @return: element at the front end of the deque (l-value)
    @throws exception: deque is empty.
*/
template<class T>
T& List_Deque<T>::front() {
    if (empty()) { throw exception("Accessing empty deque"); }
    return front_node->data;
}  // Time complexity: O(1)

/** Returns the element at the front end of the deque (r-value).
    @return: element at the front end of the deque (r-value)
    @throws exception: deque is empty.
*/
template<class T>
const T& List_Deque<T>::front() const {
    if (empty()) { throw exception("Accessing empty deque"); }
    return front_node->data;
}  // Time complexity: O(1)

/** Returns the element at the rear end of the deque (l-value).
    @return: element at the rear end of the deque (l-value)
    @throws exception: deque is empty.
*/
template<class T>
T& List_Deque<T>::back() {
    if (empty()) { throw exception("Accessing empty deque"); }
    return rear_node->data;
}  // Time complexity: O(1)

/** Returns the element at the rear end of the deque (r-value).
    @return: element at the rear end of the deque (r-value)
    @throws exception: deque is empty.
*/
template<class T>
const T& List_Deque<T>::back() const {
    if (empty()) { throw exception("Accessing empty deque"); }
    return rear_node->data;
}  // Time complexity: O(1)

/** Deletes an element from the front end of the deque.
    @throws exception: deque is empty.
*/
template<class T>
void List_Deque<T>::pop_front() {
    if (empty()) { throw exception("Accessing empty deque"); }
    D_Node* to_be_deleted = front_node;
    if (num_of_items-- == 1) { front_node = rear_node = NULL; }
    else {
        front_node = front_node->next;
        front_node->prev = NULL;
    }
    delete to_be_deleted;
}  // Time complexity: O(1)

/** Deletes an element from the rear end of the deque.
    @throws exception: deque is empty.
*/
template<class T>
void List_Deque<T>::pop_back() {
    if (empty()) { throw exception("Accessing empty deque"); }
    D_Node* to_be_deleted = rear_node;
    if (num_of_items-- == 1) { front_node = rear_node = NULL; }
    else {
        rear_node = rear_node->prev;
        rear_node->next = NULL;
    }
    delete to_be_deleted;
}  // Time complexity: O(1)

/** Adds an element to the front end of the deque.
    @param item: element to add to the deque
*/
template<class T>
void List_Deque<T>::push_front(const T& item) {
    if (!(num_of_items++)) { front_node = rear_node = new D_Node(item); }
    else {
        front_node->prev = new D_Node(item);
        front_node->prev->next = front_node;
        front_node = front_node->prev;
    }
}  // Time complexity: O(1)

/** Adds an element to the rear end of the deque.
    @param item: element to add to the deque
*/
template<class T>
void List_Deque<T>::push_back(const T& item) {
    if (!(num_of_items++)) { front_node = rear_node = new D_Node(item); }
    else {
        rear_node->next = new D_Node(item);
        rear_node->next->prev = rear_node;
        rear_node = rear_node->next;
    }
}  // Time complexity: O(1)

/** Deletes all the nodes in the deque. */
template<class T>
void List_Deque<T>::clear() {
    while (!empty()) { pop_front(); }
}  // Time complexity: O(n)

#endif