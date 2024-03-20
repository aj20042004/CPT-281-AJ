#include <iostream>
#include "Q1D_List_Node.h"
#include "Q2List_Node.h"
#include "Q4MaxAndMin.h"
#include "List.h"
#include <vector>

using namespace std;


int main() {

	// Q1) Testing
	D_List_Node* head = new D_List_Node(5);
	head->next = new D_List_Node(6);
	head->next->next = new D_List_Node(7);
	head->next->next->next = new D_List_Node(8);

	D_List_Node* copy_head = Solution().deep_copy(head);

	// Printing the original linked list
	D_List_Node* current = head;
	while (current) {
		cout << "data: " << current->val << endl;
		current = current->next;
	}

	cout << endl;

	// Printing the deep copied linked list
	current = copy_head;
	while (current) {
		cout << "data: " << current->val << endl;
		current = current->next;
	}

	// ---------------------------------------------------------------------------------------

	// Q2) Testing
	List_Node* headList = new List_Node(2);
	headList->next = new List_Node(2);
	headList->next->next = new List_Node(7);
	headList->next->next->next = new List_Node(2);
	headList->next->next->next->next = new List_Node(10);

	// Original Linked List
	List_Node* current_1 = headList;
	while (current_1) {
		cout << "data -> " << current_1->val << endl;
		current_1 = current_1->next;
	}

	cout << endl;

	Solution_for_Q2().remove_first_occurrence(headList, 2);

	// -----------------------------------------------------------------------------------------

	//Q4) Testing
	list<int> li = { 6,5,6,4};
	list<int> li_1 = { 7,9,2,11,5 };

	vector<int> result = Solution_for_Q4().max_and_second_max(li); 

	for (int i = 0; i < result.size(); i++) {
		cout << "values -> " << result.at(i) << endl;
	}

	// ------------------------------------------------------------------------------------------

	// Q3) Testing
	List<string> parent;
	
	parent.push_back("Tom");
	parent.push_back("Dick");
	parent.push_back("Harry");
	parent.push_back("Sam");

	List<string>::Iterator it = parent.begin();
	it++;
	it++;
	
	it++;
	parent.insert(it, "Lisa");
	it -= 2;
	parent.erase(it);
	cout << *(it++) << endl;

	system("pause");
 	return 0;
}
