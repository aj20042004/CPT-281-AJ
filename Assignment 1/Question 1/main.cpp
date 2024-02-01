#include <iostream>
#include <string>
#include "Header.h"

using namespace std;

int main() {

	string s = "datastructures";

	Solution sol;

	cout << "Input: " << s << endl;
	cout << "Output: " << sol.remove_vowels(s) << endl;

	system("pause");
	return 0;
}