// Created by Dayu Wang (dwang@stchas.edu) on 2022-09-11

// Last updated by Dayu Wang (dwang@stchas.edu) on 2023-06-21


#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <string>

using std::exception;
using std::ostream;
using std::to_string;

/** A doubly-linked list with iterators */
template<class T>
class List {
public:
    /** An iterator */
    class Iterator;

    // Constructors
    List();  // Default constructor
    List(const List<T>&);  // Copy constructor

    // Destructor
    virtual ~List();

    // Operators
    const List<T>& operator = (const List<T>&);  // Deep-copy assignment operator

    // Class-member functions
    size_t size() const;  // Returns the size of the list.
    bool empty() const;  // Tests whether the list is empty.
    T& front();  // Returns the first element stored in the list (l-value).
    const T& front() const;  // Returns the first element stored in the list (r-value).
    T& back();  // Returns the last element stored in the list (l-value).
    const T& back() const;  // Returns the last element stored in the list (r-value).
    void push_front(const T&);  // Adds an element to the front end of the list.
    void push_back(const T&);  // Adds an element to the rear end of the list.
    void pop_front();  // Deletes the element at the front end of the list.
    void pop_back();  // Deletes the element at the rear end of the list.
    void clear();  // Deletes all the elements in the list.
    Iterator begin() const;  // Generates an iterator on the first element of the list.
    Iterator end() const;  // Generates an iterator just after the last element of the list.
    Iterator& insert(Iterator&, const T&);  // Inserts an element at iterator position.
    Iterator& erase(Iterator&);  // Deletes the element at iterator position.
    Iterator find(const T&) const;  // Searches for a value in the list.

private:
    /** A doubly-linked list node */
    struct D_Node;

    // Data fields
    D_Node *head, *tail;  // Stores pointers to the first and last node.
    size_t num_of_items;  // Stores the number of elements in the list.
};

/* Implementation of class "List" */

// A doubly-linked list node
template<class T>
struct List<T>::D_Node {
    // Data fields
    T data;  // Stores some data in the node.
    D_Node* next;  // A pointer to the next node in the list
    D_Node* prev;  // A pointer to the previous node in the list

    // Constructor
    D_Node(const T&);
};

// Constructor ofs struct "D_Node"
template<class T>
List<T>::D_Node::D_Node(const T& data) : data(data), next(NULL), prev(NULL) {}  // Time complexity: O(1)

// Default constructor
template<class T>
List<T>::List() : head(NULL), tail(NULL), num_of_items(0) {}  // Time complexity: O(1)

// Copy constructor
template<class T>
List<T>::List(const List<T>& other) {
    head = tail = NULL;
    *this = other;
}  // Time complexity: O(n)

// Destructor
template<class T>
List<T>::~List() { clear(); }  // Time complexity: O(n)

// Deep-copy assignment operator
template<class T>
const List<T>& List<T>::operator = (const List<T>& rhs) {
    if (this != &rhs) {
        clear();
        num_of_items = rhs.num_of_items;
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
    return *this;
}  // Time complexity: O(n)

// Returns the size of the list.
template<class T>
size_t List<T>::size() const { return num_of_items; }  // Time complexity: O(1)

// Tests whether the list is empty.
template<class T>
bool List<T>::empty() const { return !size(); }  // Time complexity: O(1)

// Returns the first element in the list (l-value).
template<class T>
T& List<T>::front() {
    if (empty()) { throw exception("Accessing empty list"); }
    return head->data;
}  // Time complexity: O(1)

// Returns the first element in the list (r-value).
template<class T>
const T& List<T>::front() const {
    if (empty()) { throw exception("Accessing empty list"); }
    return head->data;
}  // Time complexity: O(1)

// Returns the last element in the list (l-value).
template<class T>
T& List<T>::back() {
    if (empty()) { throw exception("Accessing empty list"); }
    return tail->data;
}  // Time complexity: O(1)

// Returns the last element in the list (r-value).
template<class T>
const T& List<T>::back() const {
    if (empty()) { throw exception("Accessing empty list"); }
    return tail->data;
}  // Time complexity: O(1)

// Adds an element to the front end of the list.
template<class T>
void List<T>::push_front(const T& item) {
    if (!(num_of_items++)) { head = tail = new D_Node(item); } else {
        head->prev = new D_Node(item);
        head->prev->next = head;
        head = head->prev;
    }
}  // Time complexity: O(1)

// Adds an element to the rear end of the list.
template<class T>
void List<T>::push_back(const T& item) {
    if (!(num_of_items++)) { head = tail = new D_Node(item); }
    else {
        tail->next = new D_Node(item);
        tail->next->prev = tail;
        tail = tail->next;
    }
}  // Time complexity: O(1)

// Deletes the element at the front end of the list.
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

// Deletes the element at the rear end of the list.
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

// Deletes all the elements in the list.
template<class T>
void List<T>::clear() {
    if (head) {
        D_Node* p = head;
        head = head->next;
        delete p;
    }
    tail = NULL;
    num_of_items = 0;
}  // Time complexity: O(n)

// Stream insertion operator
template<class T>
ostream& operator << (ostream& out, const List<T>& li) {
    out << '[';
    for (typename List<T>::Iterator it = li.begin(); it != li.end(); it++) {
        out << *it;
        if (it != li.end() - 1) { out << ", "; }
    }
    return out << ']';
}  // Time complexity: O(n)

// A list iterator
template<class T>
class List<T>::Iterator {
public:
    // Operators
    Iterator operator + (int) const;  // Generates an iterator several positions after current position.
    Iterator& operator += (int);  // Moves the iterator forward for specified positions.
    Iterator operator - (int) const;  // Generates an iterator several positions before current position.
    Iterator& operator -= (int);  // Moves the iterator backward for specified positions.
    Iterator& operator ++ ();  // Moves the iterator forward for one position (prefix).
    Iterator operator ++ (int);  // Moves the iterator forward for one position (postfix).
    Iterator& operator -- ();  // Moves the iterator backward for one position (prefix).
    Iterator operator -- (int);  // Moves the iterator backward for one position (postfix).
    int operator - (const Iterator&) const;  // Finds the position different for two iterators.
    T& operator * ();  // Returns the element at current iterator position (l-value).
    const T& operator * () const;  // Returns the element at current iterator position (r-value).
    T* operator -> ();  // Returns a pointer to the element at current iterator position.
    bool operator == (const Iterator&) const;  // Tests whether two iterators point to the same element.
    bool operator != (const Iterator&) const;  // Tests whether two iterators point to difference elements.

private:
    // Data fields
    const List<T>* parent;  // Stores a pointer to the parent linked list.
    D_Node* current;  // Stores a pointer to the node the iterator is on.
    size_t offset;  // Stores the number of elements passed after the first element.

    // Constructor
    Iterator(const List<T>*, D_Node*, size_t);

    friend class List<T>;
};

// Constructor of iterator
template<class T>
List<T>::Iterator::Iterator(const List<T>* parent, D_Node* current, size_t offset) :
    parent(parent), current(current), offset(offset) {}  // Time complexity: O(1)

// Generates an iterator several positions after current position.
template <class T>
typename List<T>::Iterator List<T>::Iterator::operator + (int num) const {
    if (num < 0) { return *this - -num; }
    typename List<T>::Iterator result = *this;
    for (int i = 0; i < num; i++) { result++; }
    return result;
}  // Time complexity: O(n)

// Moves the iterator forward for specified positions.
template<class T>
typename List<T>::Iterator& List<T>::Iterator::operator += (int num) {
    if (num < 0) { return *this -= -num; }
    for (int i = 0; i < num; i++) { (*this)++; }
    return *this;
}  // Time complexity: O(n)

// Generates an iterator several positions before current position.
template<class T>
typename List<T>::Iterator List<T>::Iterator::operator - (int num) const {
    if (num < 0) { return *this + -num; }
    typename List<T>::Iterator result = *this;
    for (int i = 0; i < num; i++) { result--; }
    return result;
}  // Time complexity: O(n)

// Moves the iterator backward for specified positions.
template<class T>
typename List<T>::Iterator& List<T>::Iterator::operator -= (int num) {
    if (num < 0) { return *this += -num; }
    for (int i = 0; i < num; i++) { (*this)--; }
    return *this;
}  // Time complexity: O(n)

// Moves the iterator forward for one position (prefix).
template<class T>
typename List<T>::Iterator& List<T>::Iterator::operator ++ () {
    if (!current) { throw exception("Iterator out of range"); }
    current = current->next;
    offset++;
    return *this;
}  // Time complexity: O(1)

// Moves the iterator forward for one position (postfix).
template<class T>
typename List<T>::Iterator List<T>::Iterator::operator ++ (int) {
    typename List<T>::Iterator result = *this;
    ++(*this);
    return result;
}  // Time complexity: O(1)

// Moves the iterator backward for one position (prefix).
template<class T>
typename List<T>::Iterator& List<T>::Iterator::operator -- () {
    if (current == parent->head) { throw exception("Iterator out of range"); }
    current = current ? current->prev : parent->tail;
    offset--;
    return *this;
}  // Time complexity: O(1)

// Moves the iterator backward for one position (postfix).
template<class T>
typename List<T>::Iterator List<T>::Iterator::operator -- (int) {
    typename List<T>::Iterator result = *this;
    --(*this);
    return result;
}  // Time complexity: O(1)

// Finds the position different for two iterators.
template<class T>
int List<T>::Iterator::operator - (const Iterator& other) const {
    return (int)offset - (int)other.offset;
}  // Time complexity: O(1)

// Returns the element at current iterator position (l-value).
template<class T>
T& List<T>::Iterator::operator * () {
    if (!current) { throw exception("Dereferencing NULL pointer"); }
    return current->data;
}  // Time complexity: O(1)

// Returns the element at current iterator position (r-value).
template<class T>
const T& List<T>::Iterator::operator * () const {
    if (!current) { throw exception("Dereferencing NULL pointer"); }
    return current->data;
}  // Time complexity: O(1)

// Returns a pointer to the element at current iterator position.
template<class T>
T* List<T>::Iterator::operator -> () {
    if (!current) { throw exception("Dereferencing NULL pointer"); }
    return &(current->data);
}  // Time complexity: O(1)

// Tests whether two iterators point to the same element.
template<class T>
bool List<T>::Iterator::operator == (const Iterator& other) const {
    return offset == other.offset;
}  // Time complexity: O(1)

// Tests whether two iterators point to different elements.
template<class T>
bool List<T>::Iterator::operator != (const Iterator& other) const {
    return offset != other.offset;
}  // Time complexity: O(1)

// Generates an iterator on the first element of the list.
template<class T>
typename List<T>::Iterator List<T>::begin() const {
    return Iterator(this, head, 0);
}  // Time complexity: O(1)

// Generates an iterator just after the last element of the list.
template<class T>
typename List<T>::Iterator List<T>::end() const {
    return Iterator(this, NULL, size());
}  // Time complexity: O(1)

// Inserts an element at iterator position.
template<class T>
typename List<T>::Iterator& List<T>::insert(Iterator& pos, const T& value) {
    if (pos == begin()) {
        push_front(value);
        pos = ++begin();
    } else if (pos == end()) {
        push_back(value);
        pos = end();
    } else {
        D_Node* new_node = new D_Node(value);
        new_node->prev = pos.current->prev;
        new_node->prev->next = new_node;
        new_node->next = pos.current;
        new_node->next->prev = new_node;
        num_of_items++;
        pos.offset++;
    }
    return pos;
}  // Time complexity: O(1)

// Deletes the element at iterator position.
template<class T>
typename List<T>::Iterator& List<T>::erase(Iterator& pos) {
    if (pos == end()) { throw exception("Dereferencing NULL pointer"); }
    if (pos == begin()) {
        pop_front();
        pos = begin();
    } else if (pos == --end()) {
        pop_back();
        pos = end();
    } else {
        D_Node* to_be_deleted = pos.current;
        pos.current->prev->next = pos.current->next;
        pos.current->next->prev = pos.current->prev;
        pos.current = pos.current->next;
        num_of_items--;
        delete to_be_deleted;
    }
    return pos;
}  // Time complexity: O(1)

// Searches for a value in the list.
template<class T>
typename List<T>::Iterator List<T>::find(const T& value) const {
    for (Iterator it = begin(); it != end(); it++) {
        if (*it == value) { return it; }
    }
    return end();
}  // Time complexity: O(n)

#endif