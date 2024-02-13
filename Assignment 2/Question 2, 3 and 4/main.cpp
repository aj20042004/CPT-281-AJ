#include <iostream>
#include "Vector.h"


using namespace std;

int main() {

	Vector<int> v_1;
	Vector<int> v_2;
	Vector<int> v_3;


	v_1.push_back(1);
	v_1.push_back(2);
	v_1.push_back(3);
	v_1.push_back(4);
	v_1.push_back(5);

	v_2.push_back(6);
	v_2.push_back(7);
	v_2.push_back(8);
	v_2.push_back(9);
	v_2.push_back(10);
	v_2.push_back(11);
	v_2.push_back(12);

	cout << "capacity of first vector : " << v_1.capacity_return() << endl;

	cout << v_1 << endl;

	v_1.shrink_to_fit();

	cout << "Shrinked the capacity of first vector: " << v_1.capacity_return() << endl;

	cout << "\ncapacity of second vector : " << v_2.capacity_return() << endl;

	cout << v_2 << endl;

	v_2.shrink_to_fit();

	cout << "Shrinked the capacity of second vector: " << v_2.capacity_return() << endl;

	v_3 = v_1 + v_2;

	cout << v_3 << endl;

	cout << v_3.find(50) << endl;

	system("pause");
	return 0;
}

