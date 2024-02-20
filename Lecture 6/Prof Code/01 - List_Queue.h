// Created by Dayu Wang (dwang@stchas.edu) on 2022-10-03

// Last updated by Dayu Wang (dwang@stchas.edu) on 2022-10-03

#ifndef LIST_QUEUE_H
#define LIST_QUEUE_H

#include <exception>
#include <stddef.h>

using std::exception;

/** A linked list based sequential queue */
template<class T>
class List_Queue {
public:
    // Constructors
    List_Queue();  // Default constructor
    List_Queue(const List_Queue<T>&);  // Copy constructor

    // Destructor
    virtual ~List_Queue();

    // Deep-copy assignment operator
    const List_Queue<T>& operator = (const List_Queue<T>&);

    // Class-member functions
    size_t size() const;  // Returns the number of elements in the queue.
    bool empty() const;  // Tests whether the queue is empty.
    T& front();  // Returns the element at the front end of the queue (l-value).
    const T& front() const;  // Returns the element at the front end of the queue (r-value).
    void pop();  // Deletes an element from the front end of the queue.
    void push(const T&);  // Adds an element to the rear end of the queue.

private:
    /** A singly-linked list node */
    struct Node;

    // Data fields
    Node *front_node, *rear_node;  // Stores pointers to the front and rear node in the queue.
    size_t num_of_items;  // Stores the number of elements in the queue.

    // Class-member function
    void clear();  // Deletes all the nodes in the queue.
};

// Implementation of class {List_Queue}

/** A singly-linked list node */
template<class T>
struct List_Queue<T>::Node {
    // Data fields
    T data;  // Stores some data in the node.
    Node* next;  // Stores a pointer to the next node in the list.

    // Constructor
    Node(const T&);
};

// Constructor of struct {Node}
template<class T>
List_Queue<T>::Node::Node(const T& data) : data(data), next(NULL) {}

// Default constructor of class {List_Queue}
template<class T>
List_Queue<T>::List_Queue() : front_node(NULL), rear_node(NULL), num_of_items(0) {}

// Copy constructor of class {List_Queue}
template<class T>
List_Queue<T>::List_Queue(const List_Queue<T>& other) {
    front_node = rear_node = NULL;
    *this = other;
}

// Destructor
template<class T>
List_Queue<T>::~List_Queue() { clear(); }

// Deep-copy assignment operator.
template<class T>
const List_Queue<T>& List_Queue<T>::operator = (const List_Queue<T>& rhs) {
    if (this != &rhs) {
        clear();
        num_of_items = rhs.num_of_items;
        if (num_of_items) {
            front_node = rear_node = new Node(rhs.front_node->data);
            Node* q = rhs.front_node->next;
            while (q) {
                rear_node->next = new Node(q->data);
                rear_node = rear_node->next;
                q = q->next;
            }
        }
    }
    return *this;
}

/** Returns the number of elements in the queue.
    @return: number of elements in the queue
*/
template<class T>
size_t List_Queue<T>::size() const { return num_of_items; }  // Time complexity: O(1)

/** Tests whether the queue is empty.
    @return: {true} if the queue is empty; {false} otherwise
*/
template<class T>
bool List_Queue<T>::empty() const { return !size(); }  // Time complexity: O(1)

/** Returns the element at the front end of the queue (l-value).
    @return: element at the front end of the queue (l-value)
    @throws exception: queue is empty.
*/
template<class T>
T& List_Queue<T>::front() {
    if (empty()) { throw exception("Accessing empty queue"); }
    return front_node->data;
}  // Time complexity: O(1)

/** Returns the element at the front end of the queue (r-value).
    @return: element at the front end of the queue (r-value)
    @throws exception: queue is empty.
*/
template<class T>
const T& List_Queue<T>::front() const {
    if (empty()) { throw exception("Accessing empty queue"); }
    return front_node->data;
}  // Time complexity: O(1)

/** Deletes an element from the front end of the queue.
    @throws exception: queue is empty.
*/
template<class T>
void List_Queue<T>::pop() {
    if (empty()) { throw exception("Accessing empty queue"); }
    Node* to_be_deleted = front_node;
    if (num_of_items-- == 1) { front_node = rear_node = NULL; }
    else { front_node = front_node->next; }
    delete to_be_deleted;
}  // Time complexity: O(1)

/** Adds an element to the rear end of the queue.
    @param item: element to add to the queue
*/
template<class T>
void List_Queue<T>::push(const T& item) {
    if (!(num_of_items++)) { front_node = rear_node = new Node(item); }
    else {
        rear_node->next = new Node(item);
        rear_node = rear_node->next;
    }
}  // Time complexity: O(1)

/** Deletes all the nodes in the queue. */
template<class T>
void List_Queue<T>::clear() {
    while (!empty()) { pop(); }
}  // Time complexity: O(n)

#endif