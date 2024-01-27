#include <iostream>
#include "Vector.h"


using namespace std;


int main() {

	Vector<int> vec;

	vec.push_back(100);
	vec.push_back(91);
	vec.push_back(1);
	vec.push_back(1000);

	cout << "Vector before sorting: " << endl;

	for (int i = 0; i < vec.size(); i++) {
		cout << vec.at(i) << " ";
	}

	cout << endl;

	cout << "\nElement Found or Not Found? " << vec.search(98) << endl;

	vec.sort();

	cout << "\nVector after sorting: " << endl;

	for (int j = 0; j < vec.size(); j++) {
		cout << vec.at(j) << " ";
	}

	system("pause");
	return 0;
}