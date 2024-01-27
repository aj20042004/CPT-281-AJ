#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <algorithm>

using namespace std;

template<class T>
class Vector {

public:
	Vector();  // Default constructor
	Vector(const Vector<T>&); // Copy constructor
	Vector(size_t);  // Constructor with initial size
	Vector(size_t, const T&); // Constructor with initial size and filling value

	// Destructor
	virtual ~Vector();

	const Vector<T>& operator = (const Vector<T>&); // deep copy operator
	T& operator[] (size_t);   // left [] value
	const T& operator[] (size_t) const;  // right [] value

	T& at(size_t);
	const T& at(size_t) const;

	size_t size() const;
	bool empty() const;

	T& front();
	const T& front() const;

	T& back();
	const T& back() const;

	void push_back(const T&);
	void pop_back();

	const string search(const T&);

	void sort();


private:
	T* arr;
	size_t num_of_items;
	size_t capacity;
	static const size_t DEFAULT_CAPACITY;

	void resize();

};

// Default constructor
template<class T>
Vector<T>::Vector() {
	capacity = DEFAULT_CAPACITY;
	num_of_items = 0;
	arr = new T[capacity];
}

// default capacity
template<class T>
const size_t Vector<T>::DEFAULT_CAPACITY = 10;

// Deep copy assignment
template<class T>
const Vector<T>& Vector<T>::operator=(const Vector<T>& rhs) {

	// avoid self-assignment
	if (this != &rhs) {

		// Delete the dynamic data
		if (arr) {
			delete[] arr;
			arr = NULL;
		}

		// Copy the static data
		capacity = rhs.capacity;
		num_of_items = rhs.num_of_items;

		// Copy the dynamic data
		if (capacity) {
			arr = new T[capacity];
			for (size_t i = 0; i < num_of_items; i++) { this.arr[i] = rhs.arr[i]; }
		}
	}
	// return
	return *this;
}

// lvalue
template<class T>
T& Vector<T>::operator[] (size_t index) {
	return arr[index];
}

//rvalue
template<class T>
const T& Vector<T>::operator[] (size_t index) const {
	return arr[index];
}

// Constructor with initial size
template<class T>
Vector<T>::Vector(size_t initial_size) {

	capacity = max(DEFAULT_CAPACITY, initial_size);
	num_of_items = initial_size;
	arr = new T[capacity];
}

//Constructor with initial size and filling value
template<class T>
Vector<T>::Vector(size_t initial_size, const T& filling_value) {

	capacity = max(DEFAULT_CAPACITY, initial_size);
	num_of_items = initial_size;
	arr = new T[capacity];

	for (size_t i = 0; i < num_of_items; i++) {
		arr[i] = filling_value;
	}
}

// Destructor
template<class T>
Vector<T>::~Vector() {

	if (arr) {
		delete[] arr;
	}
}

template<class T>
T& Vector<T>::at(size_t index) {
	if (index >= size()) { throw exception("Index out of bounds"); }
	return arr[index];
}

template<class T>
const T& Vector<T>::at(size_t index) const {
	if (index >= size()) { throw exception("Index out of bounds"); }
	return data[index];
}

template<class T>
size_t Vector<T>::size() const {
	return num_of_items;
}

template<class T>
bool Vector<T>::empty() const {
	return !size();
}

template<class T>
T& Vector<T>::front() {
	if (empty()) { throw exception("Accessing empty vector"); }
	return at(0);
}

template<class T>
const T& Vector<T>::front() const {
	if (empty()) { throw exception("Accessing empty vector"); }
	return at(0);
}

template<class T>
T& Vector<T>::back() {
	if (empty()) { throw exception("Accessing empty vector"); }
	return at(size() - 1);
}

template<class T>
const T& Vector<T>::back() const {
	if (empty()) { throw exception("Accessing empty vector"); }
	return at(size() - 1);
}

template<class T>
void Vector<T>::push_back(const T& value) {
	if (size() == capacity) { resize(); }
	arr[num_of_items++] = value;
}

template<class T>
void Vector<T>::pop_back() {
	if (empty) { throw exception("Accessing empty vector"); }
	num_of_items--;
}

template<class T>
void Vector<T>::resize() {
	capacity *= 2;
	T* arr1 = new T[capacity];
	for (size_t i = 0; i < size(); i++) {
		arr1[i] = arr[i];
	}
	delete arr;
	arr = arr1;
}

template<class T>
Vector<T>::Vector(const Vector<T>& other) {
	arr = NULL;
	*this = other;
}

// Linear Search
template<class T>
const string Vector<T>::search(const T& search_value) {

	if (!size()) { throw exception("Empty Vector"); }

	for (size_t p = 0; p < size(); p++) {

		if (arr[p] == search_value) {
			return "Found";
		}
	}
	return "Not Found";
}


// Insertion sort
template<class T>
void Vector<T>::sort() {

	for (int k = 1; k < size(); k++) {

		int key = arr[k];
		int j = k - 1;

		while ((j >= 0) && (key < arr[j])) {
			arr[j + 1] = arr[j];
			j--;
		}

		arr[j + 1] = key;
	}

}

#endif