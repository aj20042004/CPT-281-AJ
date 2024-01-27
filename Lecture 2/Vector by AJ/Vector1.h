#ifndef VECTOR1_H
#define VECTOR1_H

#include <algorithm>
#include <iostream>

using namespace std;

template<class T>
class Vector1 {

public:
	Vector1(); // Default constructor

private:
	static const size_t DEFAULT_CAPACITY;
	size_t num_of_elements;
	size_t capacity;
	T* arr;

};

template<class T>
Vector1<T>::Vector1() {
	capacity = DEFAULT_CAPACITY;
	num_of_elements = 0;
	arr = new T[capacity];
}






#endif
